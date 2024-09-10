#include<stdio.h>
void tower_of_hanoi(int n,char source, char help,char desdination){
    if(n==1){ // base case
        printf("Move disc 1 from %c rod to %c rod\n",source,desdination);
        return;
    }
    tower_of_hanoi(n-1,source,desdination,help); // A to B using C
    printf("Move disk %d from %c rod to %c rod\n",n,source,desdination); // A to C
    tower_of_hanoi(n-1,help,source,desdination);// B to C using A
}
int main(){
    int n=3;
    tower_of_hanoi(n,'A','B','C');
}