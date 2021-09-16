#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int n, i, c;
	c=0;
	string a, p;
	char d;
	vector <string> s;
	setlocale(LC_ALL, "Russian");
	cout<<"¬ведите строку: ";
	getline(cin, a);
	cout<<"¬ведите символ, по которому нужно разбить строку: ";
	cin>>d;
	int sz = a.length();
	n=-1;
	while(true){
		p=a.substr(n+1);
		n=p.find(d);
		if(n==-1){
			s.push_back(p);
			break;
		} 
		c++;
		s.push_back(p.substr(0, n));
		a=p;
	}
	for(i=0;i<c+1;i++) cout<<s[i]<<' ';
	
}
