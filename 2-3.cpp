#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
	int i = 1;
	int j, x, k, n;
	int c;
	setlocale(LC_ALL, "Russian");
	cout<<"Введите размер массива: ";
	cin>>n;
	vector <int> A(n);
	cout<<"Введите элементы массива: ";
	for(k=0;k<n;k++){
		cin>>A[k];
	}
	while(i < n){
	    j = i;
	    while(j > 0 && A[j-1] > A[j]){
	        swap(A[j], A[j-1]);
	        j -= 1;
		}
	    i += 1;
	}
	for(i=0;i<n;i++){
		cout << A[i]<<" ";
	}
	
}
