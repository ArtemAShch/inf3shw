#include <iostream>
#include <vector>

using namespace std;

int* merge_sort(int *array, int *buff, int left, int right)
{
    if (left==right){
        buff[left] = array[left];
        return buff;
    }

    int middle=(left+right)/2;

    int *a=merge_sort(array, buff, left, middle);
    int *b=merge_sort(array, buff, middle + 1, right);
    int *c= a == array ? buff : array;

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
    int* a = new int[n];
    cout<<"Enter array elements:";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int* b = new int[n];
    a=merge_sort(a, b, 0, n-1);
    cout<<endl;
    for (i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}