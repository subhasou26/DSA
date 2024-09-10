#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num=20;
    int *ptr=&num;
    cout<<"value of num "<<num<<endl;
    cout<<"value of ptr "<<*ptr<<endl;
    *ptr=50;
    cout<<"Updated value "<<num<<endl;
    cout<<"Updated value of ptr is "<<*ptr;
    return 0;
}