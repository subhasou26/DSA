#include<stdio.h>
#include<stdlib.h>
#define MAX 4
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

    void insert(int item){
        if(isFull()){
            printf("Queue Overflow\n");
            return;
        }
        if(front==-1)
            front=0;
        if(rear==MAX-1)// rear is at last position
            rear=0;
        else
            rear++;
            arr[rear]=item;    
    }// end of insert

    int del(){
        int item;
        if(isEmpty()){
            printf("Queue is underflow\n");
            exit(1);
        }
        item=arr[front];
        if(front==rear) {// queue has only one element
            front=-1;
            rear=-1;
        }
        else if(front==MAX-1){ // if front at the last
            front=0;
        }
        else {
            front++;
        }
        return item;

    }// end of del

    int isEmpty(){
        if(front==-1){
            return 1;
        }
        else
            return 0;
    }// end of isempty

    int isFull(){
        if((front==0 && rear==MAX-1)||(front==rear+1)){
            return 1;
        }
        else 
            return 0;
    } // end of isfull

    int peek(){
        if(isEmpty()){
            printf("Queue is underflow\n");
            exit(1);
        }
        return arr[front];
    }// end of peek

    void display(){
        int i;
        if(isEmpty()){
            printf("quqeue is empty\n");
            return;
        }
        printf("Queue elements:  \n");
        i=front;
        if(front<rear){
            while (i<=rear)
            {
                printf("%d ",arr[i++]); // this will work only when front <rear
            }
            
        }
        else {
            while (i<=MAX-1)
            {
                printf("%d ",arr[i++]);  // if front>rear
            }
            i=0;
            while (i<=rear)
            {
                printf("%d ",arr[i++]); // printing the remainin part
            
            }
            
            
        }
        printf("\n");
    } // end of display

