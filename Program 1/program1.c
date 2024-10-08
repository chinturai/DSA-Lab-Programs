#include <stdio.h>
#include <stdlib.h>  // For malloc() and free()

// Function to perform insertion sort
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform selection sort
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, choice;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {  // Check if malloc failed
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }

    // Ask the user to input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for sorting choice
    printf("Choose sorting method:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Perform the chosen sorting method
    if (choice == 1) {
        insertionSort(arr, n);
        printf("Array sorted using Insertion Sort:\n");
    } else if (choice == 2) {
        selectionSort(arr, n);
        printf("Array sorted using Selection Sort:\n");
    } else {
        printf("Invalid choice! Exiting...\n");
        free(arr);  // Free allocated memory before exiting
        return 1;
    }

    // Display the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
