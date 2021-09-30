#include <iostream>
//using namespace std;

struct DateTime{
    unsigned short Day : 5;
    unsigned short Month : 4;
    unsigned short Year : 7;
    unsigned short Hour : 5;
    unsigned short Minute : 6;
    unsigned short Second : 6;
    unsigned short Millisecond : 10;
};

int main()
{
    DateTime d;
    int i;
    std::cout << "Enter the day (1-31):" ;
    std::cin >> i;
    d.Day = i;
    std::cout << "Enter the month (1-12):";
    std::cin >> i;
    d.Month = i;
    std::cout << "Enter the Year (00-99):";
    std::cin >> i;
    d.Year = i;
    std::cout << "Enter the Hour (0-24):";
    std::cin >> i;
    d.Hour = i;
    std::cout << "Enter the Minute (0-60):";
    std::cin >> i;
    d.Minute = i;
    std::cout << "Enter the Seconds (0-60):";
    std::cin >> i;
    d.Second = i;
    std::cout << "Enter the Milliseconds (0-999):";
    std::cin >> i;
    d.Millisecond = i;
    std::cout << std::endl << "Date is: " << d.Day << "." ;
    if(d.Month<10) std::cout<<"0";
    std::cout<< d.Month << ".20";
    if(d.Year<10) std::cout<<"0";
    std::cout<< d.Year<< " ";
    std::cout << d.Hour << ":";
    if(d.Minute<10) std::cout<<"0";
    std::cout<< d.Minute << ":";
    if(d.Second<10) std::cout<<"0";
    std::cout<< d.Second <<",";
    if(d.Millisecond<100) std::cout<<"0";
    if(d.Millisecond<10) std::cout<<"0";
    std::cout<<d.Millisecond<< std::endl;
}
