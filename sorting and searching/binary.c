#include <stdio.h>
int binarySearchIterative(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;  // Key found at index mid
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Key not found in the array
}
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;  // Key found at index mid
        }
        if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, right, key);
        } else {
            return binarySearchRecursive(arr, left, mid - 1, key);
        }
    }

    return -1;  // Key not found in the array
}

int main() {
    int arr[] = {12, 34, 45, 67, 78, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 45;

    int result = binarySearchIterative(arr, size - 1, key);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
