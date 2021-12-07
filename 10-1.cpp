#include <iostream>

template<typename RT, typename... Types>
RT func1(Types ... args)
{
    RT tmp = (args + ...);
    return tmp;
}

template<typename RT, typename... Types>
void func2(RT f, Types ... args)
{
    std::cout << f(args...);
}

int func3(int a, int b)
{
    std::cout << a + b;
    return a + b;
}

int main()
{
    int a = 10;
    int b = 20;
    func2<int (*)(int, int), int, int>(func1<int, int>, a, b);
}
