#include <iostream>
#include <numeric>
#include <vector>
#include <thread>
#include <algorithm>
#include <future>

/*template <typename Iterator, typename T, typename UnaryFunction>
void for_each_wrapper(Iterator begin, Iterator end, UnaryFunction f, T& result) {
    result = std::for_each(begin, end, f);
}*/

/*template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
    auto len = end - beg;
    if (len < 1000)
        return std::accumulate(beg, end, 0);

    RandomIt mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RandomIt>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}*/

template <typename Iterator, typename UnaryFunction>
void parallel_for_each(Iterator begin, Iterator end, UnaryFunction f) {
    auto size = std::distance(begin, end);
    auto num_workers = std::thread::hardware_concurrency();
    if (size < num_workers * 4) {
        std::for_each(begin, end, f);
        return;
    }
    auto size_per_worker = size / num_workers;
    std::vector<std::future <UnaryFunction >> results(num_workers);
    for(auto i = 0u; i < num_workers; i++) {
        results[i] = std::async(std::launch::async, std::for_each<Iterator, UnaryFunction>,
                                      std::next(begin, i * size_per_worker),
                                      std::next(begin, (i + 1) * size_per_worker),
                                      f);
    }
    for(auto i = 0u; i < num_workers; i++){
        results[i].get();
    }
    return;
}

int main() {
    std::vector<int> sequence(100);
    std::iota(std::begin(sequence), std::end(sequence), 0);
    parallel_for_each(std::begin(sequence),
                                     std::end(sequence),
                                     [](const int &n){std::cout<<n<<' ';});
}
