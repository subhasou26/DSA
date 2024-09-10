#include <bits/stdc++.h>
using namespace std;
string reverseString(string str){
    if(str.size()==0){
        return "";
    }
    return reverseString(str.substr(1,str.size()))+str[0];
}
int main()
{
    cout<<reverseString("are");
    
    return 0;
}

