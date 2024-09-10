#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define a structure for StackNode
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new StackNode
struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack structure with top pointer
struct Stack {
    struct StackNode* top;
};

// Function to initialize an empty stack
struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    struct StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// Function to evaluate a postfix expression
int evaluatePostfixExpression(char* expression) {
    struct Stack* stack = initializeStack();
    int length = strlen(expression);

    for (int i = 0; i < length; i++) {
        char currentChar = expression[i];

        if (isdigit(currentChar)) {
            int operand=currentChar - '0';
            push(stack, operand); // Convert character to integer
        } else if (currentChar == ' ') {
            continue; // Skip spaces
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;

            switch (currentChar) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error.\n");
                        exit(EXIT_FAILURE);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid character in expression.\n");
                    exit(EXIT_FAILURE);
            }
            push(stack, result);
        }
    }

    if (!isEmpty(stack)) {
        int finalResult = pop(stack);
        if (isEmpty(stack)) {
            return finalResult;
        } else {
            printf("Invalid expression.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Empty expression.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    gets(expression); // You can use fgets for safer input handling

    int result = evaluatePostfixExpression(expression);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}
