#include <iostream>
#include <numeric>
#include <vector>
#include <thread>
#include <stdexcept>
#include <mutex>

std::mutex resulter;

template <typename Iterator, typename T>
void accumulate_wrapper(Iterator begin, Iterator end, T init, T& result) {
    resulter.lock();
    result += std::accumulate(begin, end, init);
    resulter.unlock();
}

template <typename Iterator, typename T>
void parallel_accumulate(Iterator begin, Iterator end, T init, int N, T& result) {
    auto size = std::distance(begin, end);
    auto max_num_workers = std::thread::hardware_concurrency();
    auto num_workers = N;
    if(num_workers>max_num_workers){
        throw std::out_of_range("too lot of threads");
    }
    if (size < num_workers * 4) {
        result = std::accumulate(begin, end, init);
    }
    auto size_per_worker = size / num_workers;
    std::vector<std::thread> threads;
    std::vector<T> results(num_workers - 1);
    for(auto i = 0u; i < num_workers - 1; i++) {
        threads.push_back(std::thread(accumulate_wrapper<Iterator, T>,
                                      std::next(begin, i * size_per_worker),
                                      std::next(begin, (i + 1) * size_per_worker),
                                      0,
                                      std::ref(result)));
    }
    auto main_result = std::accumulate(
            std::next(begin, (num_workers - 1) * size_per_worker),
            end, init);
    result+=main_result;
    for(auto& thread: threads) {
        thread.join();
    }

    return;
}

int main() {
    int N;
    int res=0;
    std::cin>>N;

    std::vector<int> sequence(100000);
    std::cout<<"\n";

    std::iota(std::begin(sequence), std::end(sequence), 0);
    std::cout<<"\n";

    accumulate_wrapper(std::begin(sequence),
                                     std::end(sequence),
                                     0, res);
    std::cout <<res;
    res=0;

    std::cout << "\n";

    parallel_accumulate(std::begin(sequence),
                        std::end(sequence),
                        0,
                        N,
                        res);
    std::cout <<res;

    std::cout << "\n";


}