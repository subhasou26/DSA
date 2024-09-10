#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to find the middle node of a linked list
struct Node* findMiddle(struct Node* slow, struct Node* fast) {
    if (fast == NULL || fast->next == NULL) {
        return slow;
    }
    
    return findMiddle(slow->next, fast->next->next);
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

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 7);

    // Find the middle node using the recursive function
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* middle = findMiddle(slow, fast);

    printf("Middle Node: %d\n", middle->data);

    return 0;
}
