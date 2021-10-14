#include <iostream>
#include "Fraction.h"

int main()
{
    int asd;
    Fraction newFraction;
    Fraction newasd;
    std::cin >> newFraction;
    std::cout << newFraction;
    std::cin >> newasd;
    std::cout << newasd;
    std::cin >> asd;
    newFraction.setTop(asd);
    std::cout << newFraction;
    std::cout<<newFraction-newasd;
    std::cout<<newFraction*newasd;
    std::cout<<newFraction+newasd;
    std::cout<<newFraction/newasd;
    std::cout<< (newFraction>newasd)<<" ";
    std::cout<< (newFraction<newasd)<<"\n";
    std::cout << newFraction.getTop()<<" "<< newFraction.getBot() << ' ' <<  newFraction.getValue()<< '\n';

    return 0;
}
