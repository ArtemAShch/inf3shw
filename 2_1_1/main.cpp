#include <iostream>
#include <chrono>
#include <cmath>
#include <array>

using namespace std::chrono;


template <typename aboba>

class Timer {
public:
    Timer(): start(steady_clock::now()){}
    ~Timer(){
        std::cout<<"time is: "<<duration_cast<aboba>( steady_clock::now()- start).count()<<std::endl;
    }
    void Pause(){
        buff = steady_clock::now();
        std::cout<<"time is: "<<duration_cast<aboba>(steady_clock::now()- start).count()<<std::endl;
    }
    void Continue(){
        start+=steady_clock::now()-buff;
        std::cout<<"time is: "<<duration_cast<aboba>(steady_clock::now()- start).count()<<std::endl;
    }
    void Stop(){

    }
    void Reset(){
        start = steady_clock::now();
    }
private:
    steady_clock::time_point start;
    steady_clock::time_point buff;
};

int main() {
    Timer <milliseconds>t ;
    t.Pause();
    t.Continue();
    t.Reset();
    auto result = 0.;
    for (auto i = 0u; i<1000000u; i++){
        result += sin(i)*cos(i);
    }

    for (auto i = 0u; i<1000000u; i++){
        result += sin(i)*cos(i);
    }

    std::cout<< result<<std::endl ;

    return 0;
}
