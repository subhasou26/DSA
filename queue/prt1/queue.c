#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int arr[MAX];
int rear=-1;
int front=-1;
void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main(){
		int choice,item;
		while(1){
			printf("1.Insert\n");
			printf("2.Delete\n");
			printf("3.Display element at the front\n");
			printf("4.Display all element in the queue\n");
			printf("5.Quit\n");
			printf("Enter your choice: ");
			scanf("%d",&choice);
			
			switch(choice){
			case 1:
				printf("Input the element for adding: ");
				scanf("%d",&item);
				insert(item);
				break;
			
			case 2:
				item=del();
				printf("Delted elemet is %d\n",item);
				break;
			
			case 3:
				printf("Element at the front is %d\n",peek());
				break;
			
			case 4:
				display();
				break;
			case 5:
				exit(1);
			default:
				printf("Wrong choice\n");					
			}// end of switch
			
		} // end of while	
	
	}
	// end of main
	void insert(int item){
		if(isFull()){
			printf("Queue overflow\n");
			return;
		}
		
		if(front==-1){
			front=0;
		}
		rear++;
		arr[rear]=item;
	}// end of insert
	
	int del(){
		int item;
		if(isEmpty()){
			printf("Stack underflow\n");
			exit(1);
			
		}
		item=arr[front];
		front++;
		return item;
	} //return of del
	
	int peek(){
	if(isEmpty()){
		printf("Stack underflow\n");
		exit(1);
	}
		return arr[front];
	}// end of peek
	
	int isEmpty(){
		if(front==-1||front==rear+1)
		return 1;
		else return 0;
	}// end of isempty
	
	int isFull(){
	if(rear==MAX-1)
	return 1;
	else 
	return 0;
	}// end of is full
	
	void display(){
		int i;
		if(isEmpty()){
			printf("Quque is empty\n");
			return;
		}
		printf("Queue is: \n\n");
		for(i=front;i<=rear;i++){
			printf("%d ",arr[i]);
			printf("\t\t");
			
		} 
	}
