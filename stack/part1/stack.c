#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
int stack[MAX_SIZE];
int top=-1;

int isEmpty(){
    return top==-1;
}

int isFull(){
    return top==MAX_SIZE-1;
}

void push(int data){
    if(isFull()){
        printf("Stack is full no memory to insert\n");
        return;
    }
    stack[++top]=data;

}

int pop(){
    if(isEmpty()){
        printf("Stack is empty  no item to pop");
        return -1;
    }
    return stack[top--];

}

void display(){
    if(isEmpty()){
        printf("Nothing to display stack is empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
    printf("\n");
}

int main(){

    push(5);
    push(10);
    push(2);
    push(6);
    push(9);
    display();

    printf("pop Elment %d \n",pop());
    printf("pop Elment %d \n",pop());
    display();

    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");
        printf("Pushing more elements onto the stack...\n");
    push(30);
    push(35);

    // Print the updated stack
    display();
    
    return 0;
}