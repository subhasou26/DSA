#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to find the length of a linked list
int findLength(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return 1 + findLength(node->next);
    }
}

// Function to insert a new node at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void display(struct Node**head){
    struct Node *temp=*head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 7);
    display(&head);
    // Calculate and print the length of the linked list
    int length = findLength(head);
    printf("\nLength of the linked list: %d\n", length);

    return 0;
}
