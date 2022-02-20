//
// Created by Артем on 20.02.2022.
//

#ifndef INC_2_2_1_TIMER_H
#define INC_2_2_1_TIMER_H
#include <chrono>
using namespace std::chrono;
template <typename aboba>

class Timer {
public:
    Timer(): start(steady_clock::now()){}
    ~Timer(){
        std::cout<<"time is: "<<duration_cast<aboba>( steady_clock::now()- start).count()<<std::endl;
    }
    void Pause(){
        buff = duration_cast<aboba>(steady_clock::now()-start);
        std::cout<<"time is: "<<buff.count()<<std::endl;
    }
    void Continue(){
        start = steady_clock::now()-buff;
        std::cout<<"time is: "<<duration_cast<aboba>( steady_clock::now()- start).count()<<std::endl;
    }
    void Stop(){

    }
    void Reset(){
        start = steady_clock::now();
    }
private:
    steady_clock::time_point start;
    duration<int, std::micro> buff;
};
#endif //INC_2_2_1_TIMER_H
