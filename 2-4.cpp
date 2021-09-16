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
	cout<<"¬ведите размер массива: ";
	cin>>n;
	vector <int> A(n);
	cout<<"¬ведите элементы массива: ";
	for(k=0;k<n;k++){
		cin>>A[k];
	}
	cout<<"¬ведите искомый элемент: ";
	cin>>c;
	if(bin_search(A, n, c)!=-1) cout << "Ёлемент присутствует";
	else cout<<"Ёлемент отсутствует";
	
}
