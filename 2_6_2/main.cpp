#include <mutex>
#include <queue>

class ThreadSafeQueue {

private:
    std::queue<int> SaveQ;
    std::mutex q_locker;

public:

    int& val_pop() {
        int a = 0;
        q_locker.lock();
        if(!SaveQ.empty()) {
            a = SaveQ.front();
            SaveQ.pop();
        }
        q_locker.unlock();
        return a;
    };

    void push(int a) {
        q_locker.lock();
        SaveQ.push(a);
        q_locker.unlock();
    };

}
