#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


int bin_search(vector<int> A, int n, int T){
    int L = 0;
    int R = n-1;
    while(L != R){
        int m = (L + R) / 2;
        if(A[m] < T)  L = m + 1;
        else{
        	if (A[m] > T) R = m - 1;
        	else return m;
		} 
        
	}
    return -1;
}

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
	cout<<"Введите искомый элемент: ";
	cin>>c;
	if(bin_search(A, n, c)!=-1) cout << "Элемент присутствует";
	else cout<<"Элемент отсутствует";
	
}
