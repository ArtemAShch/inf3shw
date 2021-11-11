#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>

T* merge_sort(T *array, T *buff, int left, int right)
{
    if (left==right){
        buff[left] = array[left];
        return buff;
    }

    int middle=(left+right)/2;

    T *a=merge_sort(array, buff, left, middle);
    T *b=merge_sort(array, buff, middle + 1, right);
    T *c= a == array ? buff : array;

    int i=left, j=middle+1;
    for(int k=left;k<=right;k++)
    {
        if(i<=middle&&j<=right){
            if(a[i]>b[j]){
                c[k]=b[j];
                j++;
            }
            else{
                c[k]=a[i];
                i++;
            }
        }
        else{
            if(i<=middle){
                c[k]=a[i];
                i++;
            }
            else{
                c[k]=b[j];
                j++;
            }
        }
    }
    return c;
}

int main(){
    int n, i;
    cout << "Enter array length:";
    cin>>n;
    auto* a = new string[n];
    cout<<"Enter array elements:";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    auto* b = new string[n];
    a=merge_sort(a, b, 0, n-1);
    cout<<endl;
    for (i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
