#include <stdio.h>
int linearSearchIterative(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Key found at index i
        }
    }
    return -1;  // Key not found in the array
}
int linearSearchRecursive(int arr[], int start, int end, int key) {
    if (start > end) {
        return -1;  // Key not found in the array
    }
    
    if (arr[start] == key) {
        return start;  // Key found at index start
    }

    return linearSearchRecursive(arr, start + 1, end, key);
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 34;

    int result = linearSearchRecursive(arr, 0, size - 1, key);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
