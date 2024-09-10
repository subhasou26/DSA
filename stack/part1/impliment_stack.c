#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
int Stack[MAX_SIZE];
int top=-1;


// function to check if  the stack is empty or not
int isEmpty(){
    return top==-1;
}

// function to check if the stack is full or not
int isFull(){
    return top==MAX_SIZE-1;
}

// function to push ement into the stack
void push(int data){
    if(isFull()){
        printf("ERROR: The stack is full no element can't be inserted\n");
        return;
    }
    Stack[++top]=data;
}

// function to pop elemnt fro the stack
int pop(){
    if(isEmpty()){
        printf("Elemnt can't be poped \n");
        return -1;
    }
    return Stack[top--];
}

//display every element
void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: \n");
    for(int i=top;i>=0;i--){
        printf("%d \n",Stack[i]);
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