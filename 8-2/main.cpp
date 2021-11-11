#include <iostream>
#include "Day.h"

int main() {
    Day d, e, f;
    d = Day(25, 9, 2002);
    e = Day(23, 5, 1999);
//    f = Day(32, 13, -1);
    if(d>e) std::cout<<1<<'\n';
    else std::cout<<0<<"\n";
    std::cin>>d;
    std::cout<<d<<std::endl;
    if(d>e) std::cout<<1;
    else std::cout<<0;
}
