#include <iostream>>
#include <cmath>
using namespace std;


int main(){
	double x, y;
	cin >> x >> y;
	x=x+y;
	y=x-y;
	x=x-y;
	cout<< "x = "<<x<<", y = "<<y;
}
