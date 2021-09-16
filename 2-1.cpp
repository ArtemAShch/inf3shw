#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
	int n, i, j, m;
	setlocale(LC_ALL, "Russian");
	cout<<"¬ведите размерность: ";
	cin>>n;
	int t[n][n];
	vector<int>vec(n);
	vector<int>res(n);
	cout<<"¬ведите вектор: ";
	for(i=0;i<n;i++){
		cin>>vec[i];
	}
	cout<<"¬ведите тензор: ";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>t[i][j];
		}
	}
	for(i=0;i<n;i++){
		m=0;
		for(j=0;j<n;j++){
			m+=vec[j]*t[i][j];
		}
		res[i]=m;
	}
	for(i=0;i<n;i++){
		cout<<res[i]<<endl;
	}
}
