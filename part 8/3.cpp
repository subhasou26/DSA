#include <bits/stdc++.h>
using namespace std;

int *fun(int arr[],int size){
    
    int *array_max=&arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>*array_max){
            array_max=&arr[i];
        }
    }
    return array_max;
}
int main()
{
    int arr[]={1,10,6,4,2,3,50};
    int size=sizeof(arr)/sizeof(int);
    int *ptr=fun(arr,size);
    cout<<"The maximum value is "<<*ptr;
    
    return 0;
}