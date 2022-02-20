#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <array>
#include <forward_list>
#include "Timer.h"
#include <algorithm>


int main() {
    std::array<int, 20>a;
    for(int i=0;i<20;i++){
        std::cin>>a[i];
    }
    std::deque<int> b;
    std::vector<int> c;
    std::list<int> d;
    std::forward_list<int> e;
    for(int i=0;i<20;i++){
        b.push_back(a[i]);
        c.push_back(a[i]);
        d.push_back(a[i]);
        e.push_front(a[i]);
    }
    e.reverse();
    Timer<microseconds>t;
    std::sort(a.begin(), a.end());
    t.Pause();
    t.Reset();
    std::sort(b.begin(), b.end());
    t.Pause();
    t.Reset();
    std::sort(c.begin(), c.end());
    t.Pause();
    t.Reset();
    d.sort();
    t.Pause();
    t.Reset();
    e.sort();
    t.Pause();
    t.Reset();

}
