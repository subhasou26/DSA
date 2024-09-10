#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to reverse a linked list
struct Node* reverseList(struct Node* current, struct Node* prev) {
    if (current == NULL) {
        return prev; // New head of the reversed list
    }

    struct Node* nextNode = current->next;
    current->next = prev;

    return reverseList(nextNode, current);
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

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original List: ");
    printList(head);

    // Reverse the linked list using the recursive function
    struct Node* reversedHead = reverseList(head, NULL);

    printf("Reversed List: ");
    printList(reversedHead);

    return 0;
}
