#include <iostream>
using namespace std;
void resizeArray(int*& arr, int& currentSize) {
    int newSize = currentSize * 2;

    
    int* newArray = new int[newSize];

    // Copy elements from the old array to the new array
    for (int i = 0; i < currentSize; i++) {
        newArray[i] = arr[i];
    }

    // Deallocate memory of the old array
    delete[] arr;

    // Update the pointer to the new array and current size
    arr = newArray;
    currentSize = newSize;
}

int main() {
    int size = 5;
    int* myArray = new int[size] {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    resizeArray(myArray, size);

    cout << "Resized array: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

 
    delete[] myArray;

    return 0;
}
