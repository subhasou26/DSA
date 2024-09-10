#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a character is an opening parenthesis
bool isOpenParenthesis(char c) {
    return (c == '(');
}

// Forward declaration of the isBalanced function
bool isBalanced(const char* str, int index);

// Function to check if a given substring within parentheses is balanced
bool isOpenParenthesisBalanced(const char* str, int index) {
    if (str[index] == '\0') {
        return false; // No closing parenthesis found for the opening parenthesis
    }

    if (str[index] == '(') {
        return isBalanced(str, index + 1); // Check the substring within parentheses
    } else if (str[index] == ')') {
        return true; // A closing parenthesis found
    }

    return isOpenParenthesisBalanced(str, index + 1); // Continue checking the substring
}

// Function to check if a given string of parentheses is balanced
bool isBalanced(const char* str, int index) {
    if (str[index] == '\0') {
        return true; // End of string reached without any imbalance
    }

    if (str[index] == '(') {
        return isOpenParenthesisBalanced(str, index + 1); // Check the substring within parentheses
    } else if (str[index] == ')') {
        return false; // Unbalanced closing parenthesis found
    }

    return isBalanced(str, index + 1); // Continue checking the string
}

int main() {
    char input[100];
    printf("Enter a string containing parentheses: ");
    scanf("%s", input);

    if (isBalanced(input, 0)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
