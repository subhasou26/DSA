#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to search for a specific value in a linked list
struct Node* searchValue(struct Node* node, int target) {
    if (node == NULL) {
        return NULL; // Target value not found in the list
    } else if (node->data == target) {
        return node; // Target value found
    } else {
        return searchValue(node->next, target);
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

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    int target = 3;
    
    // Search for the target value in the linked list
    struct Node* result = searchValue(head, target);
    
    if (result != NULL) {
        printf("Target value %d found in the linked list.\n", target);
    } else {
        printf("Target value %d not found in the linked list.\n", target);
    }

    return 0;
}
