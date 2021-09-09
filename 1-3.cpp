#include <iostream>>
#include <cmath>
using namespace std;


int main(){
	double a, b, c;
	setlocale(LC_ALL, "Russian");
	cout << "Уравнение вида ах^2 + bx + c = 0 \nВведите коэффициент а: ";
	cin>>a;
	cout << "Введите коэффициент b: ";
	cin>>b;
	cout << "Введите коэффициент c: ";
	cin>>c;
	double D=b*b-(4*a*c);
	if(D<0) cout<<"Уравнение не имеет решений в действительных числах.";
	else{
		if(a!=0){
			if(D==0){
				cout<<"Уравнение имеет одно решение: х = ";
				cout<<-b/(2*a);
			}
			else{
				cout<<"Уравнение имеет два решения: х1 = ";
				cout<<(-b+pow(D, 0.5))/(2*a);
				cout<<", х2 = ";
				cout<<(-b-pow(D, 0.5))/(2*a);
			}
		}
		else{
			if(b!=0){
				cout<<"Линейное уравнение. Имеет одно решение: ";
				cout<<-1*c/b
			}
			else{
				if(c==0) cout << "Все числа на R являются решениями данного уравнения";
				else cout << "Уравнение не имеет решений";
			}
		}
	}
}
