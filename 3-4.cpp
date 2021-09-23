#include <iostream>
#include <vector>
#include <functional>

using namespace std;

double calculate(double x, double y, function<double(double, double)>& lambd){
    return lambd(x, y);
}

int main() {
    int i;
    vector<function<double(double, double)>>Fvec(4);
    Fvec[0] = [&](double x, double y) { return x + y; };
    Fvec[1] = [&](double x, double y) { return x - y; };
    Fvec[2] = [&](double x, double y) { return x * y; };
    Fvec[3] = [&](double x, double y) { return x / y; };
    for(i=0;i<4;i++){
        cout << calculate(1.23, 4.56, Fvec[i])<<endl;
    }

}
