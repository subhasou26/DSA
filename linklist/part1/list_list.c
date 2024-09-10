#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};



 struct Node* new_node(){ // this function return a node
    int data;
    printf("Enter your data: \n");
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
 void insert_last(struct Node **head){ // for insert at last
    struct Node *temp=*head;
    struct Node* new=new_node();
    if(*head==NULL){
        *head=new;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    printf("Node inserted\n");
    return;
 }
void delete(struct Node **head){ // for delete a node
    int key;
    printf("Enter a value which you need to delete\n");
    scanf("%d",&key);
    struct Node *temp=*head,*prev;
    if(temp!=NULL &&temp->data==key){
            *head=temp->next;
            free(temp);
            return;
    }
 // Find the key to be deleted
while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }
 
  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp); 
  printf("Node deleted\n");
}
// reverce a list
 void reverse(struct Node **head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        
        next = current->next;
 
        current->next = prev;
 
        prev = current;
        current = next;
    }
    *head = prev;
    printf("Node reversed\n");
}
void search(struct Node **head){ // search in the listt
    int i=0,value;
    printf("Enter the number which you want to search\n");
    scanf("%d",&value);

    struct Node *temp=*head;
    while(temp!=NULL){
        if(temp->data==value){
            printf("The value is in %d index\n",i+1);
            return;
        }

        temp=temp->next;
        i++;
    }
    printf("The element not found\n");

}
void displaylist(struct Node **head){ // displayiing full list
    struct Node *ptr=*head;
    while(ptr!=NULL){
        printf("%d-->",ptr->data);
        ptr=ptr->next;
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
scanf("%d",&i);
switch (i)
{
case 1:
    insert_last(&head);
    break;
case 2:
      delete(&head);
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

default:
    printf("Wrong input");
    break;
}

}
}    