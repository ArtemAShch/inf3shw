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

int main() {
    Timer <microseconds>t ;


  //  ;
//  t.Reset();
    auto result = 0.;
    for (auto i = 0u; i<1000000u; i++){
        result += sin(i)*cos(i);
    }
    t.Pause();
    for (auto i = 0u; i<1000000u; i++){
        result += sin(i)*cos(i);
    }
    t.Continue();
    std::cout<< result<<std::endl ;

    return 0;
}
