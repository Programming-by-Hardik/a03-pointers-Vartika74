// pointers_assignment.c
// This program implements three functions using pointers: swap, findMax, and reverseArray.

#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void swap(int *a, int *b);
int findMax(int *arr, int length);
void reverseArray(int *arr, int length);

// Test functions
bool testSwap();
bool testFindMax();
bool testReverseArray();

int main() {
    // Run tests
    if (testSwap()) {
        printf("testSwap PASSED\n");
    } else {
        printf("testSwap FAILED\n");
    }

    if (testFindMax()) {
        printf("testFindMax PASSED\n");
    } else {
        printf("testFindMax FAILED\n");
    }

    if (testReverseArray()) {
        printf("testReverseArray PASSED\n");
    } else {
        printf("testReverseArray FAILED\n");
    }

    return 0;
}

//---------------------------------
// COMPLETE THE FUNCTION DEFINITIONS BELOW 
//---------------------------------


#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    
    // Call the swap function
    swap(&x, &y);
    
    printf("After swapping: x = %d, y = %d\n", x, y);
    
    return 0;
}





}
#include <stdio.h>

// Function to find the maximum value in an array using pointers
int findMax(int *arr, int length) {
    int max = *arr;  // Initialize max with the first element of the array
    for (int i = 1; i < length; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);  // Update max if current element is greater
        }
    }
    return max;
}

int main() {
    int arr[] = {3, 5, 7, 2, 8, -1, 4, 10, 12};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    int maxVal = findMax(arr, length);  // Find the maximum value
    printf("Maximum value in the array is: %d\n", maxVal);
    
    return 0;
}





  
}

#include <stdio.h>

// Function to reverse an array using pointers
void reverseArray(int *arr, int length) {
    int *start = arr;           // Pointer to the beginning of the array
    int *end = arr + length - 1; // Pointer to the end of the array
    int temp;

    // Swap the elements from the start and end using a loop
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;  // Move start pointer forward
        end--;    // Move end pointer backward
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    reverseArray(arr, length);  // Reverse the array

    printf("Reversed array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}




}

//---------------------------------
// TEST CASES - Don't change the code below this.
//---------------------------------

// Test case for swap function
bool testSwap() {
    int x = 5, y = 10;
    swap(&x, &y);

    if (x == 10 && y == 5) {
        return true;
    } else {
        return false;
    }
}

// Test case for findMax function
bool testFindMax() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int maxValue = findMax(arr, length);

    if (maxValue == 9) {
        return true;
    } else {
        return false;
    }
}

// Test case for reverseArray function
bool testReverseArray() {
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};
    int length = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, length);

    // Check if the array matches the expected reversed array
    for (int i = 0; i < length; i++) {
        if (arr[i] != expected[i]) {
            return false;
        }
    }
    return true;
}