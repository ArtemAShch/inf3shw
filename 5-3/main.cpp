#include <iostream>
#include "Charge.h"

int main()
{
    Charge newCharge;
    std::cout << "Possible measurements are C (Coulomb), E (elementary charge) and F (Franklin).\n";
    std::cout << "Enter value and measurement units:";
    std::cin >> newCharge;
    std::cout << "Enter new units to convert:";
    Units f;
    std::cin >> f;
    std::cout << newCharge;
    newCharge.convert(f);
    std::cout << newCharge;
    newCharge.setValue(1488);
    std::cout << newCharge.getValue() << ' ' << newCharge.getUnit() << '\n';

    return 0;
}

