#include<stdio.h>
#include<stdlib.h>

struct Node{ // user defined variable 
    int data;
    struct Node *next; // int a;
};

struct Node *new_node(){ // creating node
    int data;
    printf("Enter data\n");
    scanf("%d",&data);
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    return new;
}

void insert_big(struct Node **head){
    struct Node *temp=*head;
    struct Node *new=new_node();
    *head=new;
    new->next=temp;

}

void insert_last(struct Node **head){
    struct Node *temp=*head;
    struct Node *new=new_node();
    if(*head==NULL){
        *head=new;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    printf("Node insert at last\n");
    return;
}

void delete_node(struct Node **head){
    int key;
    printf("Enter key for which node to be deleted\n");
    scanf("%d",&key);
    struct Node *temp=*head,*prev;
    if(temp!=NULL&&temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL&&temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    // if key not present
    if(temp==NULL){
        printf("Key not present\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
    printf("Node is deleted\n");
    return;
}

void reverse(struct Node **head){
    struct Node *prev=NULL;
    struct Node *current=*head;
    struct Node *next=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
    printf("Node reversed\n");
}

void search(struct Node **head){
    int i=0,value;
    printf("Enter value which you want to serch\n");
    scanf("%d",&value);
    struct Node *temp=*head;
    while(temp!=NULL){
        if(temp ->data==value){
        printf("We found the node at index no %d",i);
        return;}
        i++;
        temp=temp->next;
    }
    printf("Node not found\n");

}
void displaylist(struct Node **head){
    struct Node *temp=*head;
    while(temp!=NULL){
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int j=1;
    struct Node* head=NULL;
    while(j){
int i;
printf("Enter 1 Insert a node at the end of the list\n");
printf("Enter 2 Delete a node by value\n");
printf("Enter 3 Display the list\n");
printf("Enter 4 Reverse the list\n");
printf("Enter 5 Search for a node\n");
printf("Enter 6 Exit the program\n");
printf("Enter 7 to insert at begining\n");
scanf("%d",&i);
switch (i)
{
case 1:
    insert_last(&head);
    break;
case 2:
      delete_node(&head);
      break;
case 3:
      displaylist(&head);  
      break;
case 4:
        reverse(&head);
        break;
case 5:
        search(&head); 
        break;
case 6:
        j=0;
        printf("Thanks for using\n");
        break;
case 7:
    insert_big(&head);      
    break;  

default:
    printf("Wrong input");
    break;
}

}
}    