#include <iostream>
#include <new>

template<typename OT, typename ... Types>
OT* ChronoCreate(Types... args)
{
    OT* ptr = new OT(args...);
    return ptr;
}

class Chrono
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Chrono(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    ~Chrono() {}

    friend std::ostream& operator<<(std::ostream& ostr, const Chrono& time)
    {
        if (time.hours < 10) ostr << '0';
        ostr << time.hours << ':';
        if (time.minutes < 10) ostr << '0';
        ostr << time.minutes << ':';
        if (time.seconds < 10) ostr << '0';
        ostr << time.seconds << '\n';

        return ostr;
    }
};

int main()
{
    int a = 20, b = 14, c = 5;
    Chrono* time1 = ChronoCreate<Chrono, int, int, int>(a, b, c);
    std::cout << (*time1);
    return 0;
}
