#include <iostream>
#include "Fraction.h"

int main()
{
    int asd;
    double m;
    Fraction newFraction;
    Fraction newasd;
    /*std::cin >> newFraction;
    std::cout << newFraction;
    std::cin >> newasd;
    std::cout << newasd;
    std::cin >> asd;
    newFraction.setTop(asd);
    std::cout << newFraction;
    m=newFraction;
    std::cout<<m<<std::endl;
    std::cout<<newFraction-newasd;
    std::cout<<newFraction*newasd;
    std::cout<<newFraction+newasd;
    std::cout<<newFraction/newasd;
    std::cout<< (newFraction>newasd)<<" ";
    std::cout<< (newFraction<newasd)<<"\n";
    std::cout << newFraction.getTop()<<" "<< newFraction.getBot() << ' ' <<  newFraction.getValue()<< '\n';*/
    newFraction.setTop(3);
    newFraction.setBot(0);
    newasd = newFraction/0;
    std::cin >> newasd;


    return 0;
}
