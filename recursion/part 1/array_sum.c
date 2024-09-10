#include<stdio.h>
int arraySum(int arr[],int size){
    if(size<=0)return 0;
    
    return (arraySum(arr,size-1)+arr[size-1]);
}
int main(){
    int arr[5]={1,2,3,4,5};
    int sum=arraySum(arr,5);
    printf("%d",sum);
}