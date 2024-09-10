#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    struct Node* result = NULL;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }

    return result;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first sorted list
    insert(&list1, 1);
    insert(&list1, 3);
    insert(&list1, 5);

    // Insert elements into the second sorted list
    insert(&list2, 2);
    insert(&list2, 4);
    insert(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge the two sorted lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
