#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string name;
    int price, temperature;
    bool hasCashback;
    cout << "Product's name: ";
    cin >> name;
    cout << "Product's price: ";
    cin >> price;
    cout << "Is cash-back available for this product? (true/false) ";
    cin.setf(ios::boolalpha);
    cin >> /* Input your code here.. */  hasCashback;
    cin.unsetf( ios::boolalpha);
    cout << "Maximum storing temperature: ";
    cin >> temperature;

    cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    cout << name << '\n';
    cout<<left <<setfill('.') <<setw(17)<<"Price:";
    cout/* */<<right<< setfill('0')<<setw(8) <<uppercase << hex << price << endl;
    cout<<left <<"Has cash-back:";
    cout<<setfill('.') <<setw(11) << right<< boolalpha<<hasCashback<<endl;
    cout<<left<<"Max temperature:";
    cout<<setfill('.') <<setw(9) << right <<dec<< showpos<<temperature<<endl;

    // Input your code here..

    return 0;
}
