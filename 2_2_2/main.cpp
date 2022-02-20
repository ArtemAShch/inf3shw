#include <iostream>
#include <map>
#include <set>
#include <string>

struct Phone{
    std::multimap<std::string, int> numbers;
    void phadd(std::string Name, int Number){
        numbers.insert({Name, Number});
    }
    void print()
    {
        for (auto& note : numbers)
            std::cout << note.first << " " << note.second << '\n';
        std::cout << '\n';
    }

    void print_rand()
    {
        int tmp = rand() % numbers.size();
        for (auto& note : numbers)
        {
            if (tmp == 0)
            {
                std::cout  << note.first << " " << note.second << '\n';
                break;
            }
            else tmp -= 1;
        }
    }

    void find(std::string name)
    {
        if (numbers.find(name) != numbers.end())
            std::cout << name << " " << numbers.find(name)->second << '\n';
        else
            std::cout << "No number found for \"" << name << "\".\n";
    }

    void set(std::string name, int number)
    {
        numbers.find(name)->second = number;
    }



};

int main() {
    std::string N;
    int Num;
    Phone Ph;
    for(int i=0;i<20;i++){
        std::cin>>N>>Num;
        Ph.phadd(N, Num);
    }
    std::cin>>N;
    Ph.find(N);
}
