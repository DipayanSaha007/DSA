#include <stdio.h>

// Function to perform linear search on the array
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Return the index where the key is found
        }
    }
    return -1;  // Return -1 if the key is not found in the array
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int key;

    // Get the key to search from the user
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Call the linearSearch function to search for the key in the array
    int result = linearSearch(arr, n, key);

    // Display the result
    if (result != -1) {
        printf("Key found at index: %d\n", result);
    } else {
        printf("Key not found in the array.\n");
    }

    return 0;
}

