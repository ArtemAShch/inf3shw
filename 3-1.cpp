#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int fib(int n){
	if(n==1 || n==2){
		return 1;
	}
	else{
		return fib(n-1)+fib(n-2);
	}
}

int main(){
	int i;
	setlocale(LC_ALL, "Russian");
	cout<<"Введите номер числа Фибоначчи: ";
	cin>>i;
	cout<<fib(i)<<endl;
}
