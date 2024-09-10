#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack structure with top pointing to the topmost element of the stack
struct Stack {
    struct Node* top;
};

// Function to initialize an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty, cannot pop element\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create an empty stack
    printf("Creating an empty stack...\n");
    struct Stack* stack = createStack();

    // Push some integer values onto the stack
    printf("Pushing elements onto the stack...\n");
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20);
    push(stack, 25);

    // Print the elements of the stack
    display(stack);

    // Pop elements from the stack and print the popped elements
    printf("Popping elements from the stack...\n");
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    // Check if the stack is empty
    printf("Is the stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");

    // Push additional elements onto the stack
    printf("Pushing more elements onto the stack...\n");
    push(stack, 30);
    push(stack, 35);

    // Print the updated stack
    display(stack);

    return 0;
}
