#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
//    system("chcp 65001");
    int k, n;
    cout<<"Enter:";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter:";
    for(k=0;k<n;k++){
        cin>>a[k];
    }
    sort(a.begin(), a.end(), [](int a, int b) {
        return a > b;
    });
    for(k=0;k<n;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
    sort(a.begin(), a.end(), [](int a, int b) {
        return a < b;
    });
    for(k=0;k<n;k++){
        cout<<a[k]<<" ";
    }
}
