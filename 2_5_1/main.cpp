#include <iostream>
#include <numeric>
#include <vector>
#include <thread>
#include <stdexcept>
#include "Timer.h"

template <typename Iterator, typename T>
void accumulate_wrapper(Iterator begin, Iterator end, T init, T& result) {
    result = std::accumulate(begin, end, init);
}

template <typename Iterator, typename T>
T parallel_accumulate(Iterator begin, Iterator end, T init, int N) {
    auto size = std::distance(begin, end);
    auto max_num_workers = std::thread::hardware_concurrency();
    auto num_workers = N;
    if(num_workers>max_num_workers){
        throw std::out_of_range("too lot of threads");
    }
    if (size < num_workers * 4) {
        return std::accumulate(begin, end, init);
    }
    auto size_per_worker = size / num_workers;
    std::vector<std::thread> threads;
    std::vector<T> results(num_workers - 1);
    for(auto i = 0u; i < num_workers - 1; i++) {
        threads.push_back(std::thread(accumulate_wrapper<Iterator, T>,
                                      std::next(begin, i * size_per_worker),
                                      std::next(begin, (i + 1) * size_per_worker),
                                      0,
                                      std::ref(results[i])));
    }
    auto main_result = std::accumulate(
            std::next(begin, (num_workers - 1) * size_per_worker),
            end, init);
    for(auto& thread: threads) {
        thread.join();
    }
    return std::accumulate(std::begin(results),
                           std::end(results), main_result);
}

int main() {
    int N;
    std::cin>>N;
    std::vector<int> sequence(1000000);
    Timer<microseconds> t;
    t.Reset();
    std::cout<<"\n";
    std::iota(std::begin(sequence), std::end(sequence), 0);
    t.Pause();
    std::cout<<"\n";
    for(auto i=0;i<5;i++) {
        t.Reset();
        std::cout << parallel_accumulate(std::begin(sequence),
                                         std::end(sequence),
                                         0,
                                         N);
        std::cout << "\n";
        t.Pause();
    }

}