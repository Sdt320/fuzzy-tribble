# fuzzy-tribble
Write a program to find the Kth largest and Kth smallest element in an array
To find the Kth largest and Kth smallest elements in an array, we can use sorting as an efficient approach. Here’s how we can achieve this in C:

1. **Sorting Approach**:
   - Sort the array in ascending order to find the Kth smallest element.
   - Sort the array in descending order to find the Kth largest element.

2. **Steps**:
   - Read the size of the array (`n`) and its elements.
   - Sort the array.
   - Access the Kth element for smallest and largest from the sorted array.

3. **Implementation**:
   Below is the C program that implements this approach:

```c
#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform partition for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find Kth smallest element
int findKthSmallest(int arr[], int n, int k) {
    // Sort the array
    quickSort(arr, 0, n - 1);
    // Return the Kth smallest element
    return arr[k - 1];
}

// Function to find Kth largest element
int findKthLargest(int arr[], int n, int k) {
    // Sort the array
    quickSort(arr, 0, n - 1);
    // Return the Kth largest element
    return arr[n - k];
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    // Finding Kth smallest element
    int kth_smallest = findKthSmallest(arr, n, k);
    printf("Kth smallest element: %d\n", kth_smallest);

    // Finding Kth largest element
    int kth_largest = findKthLargest(arr, n, k);
    printf("Kth largest element: %d\n", kth_largest);

    return 0;
}
```

### Explanation:
- **swap**: Helper function to swap two integers.
- **partition**: Part of the QuickSort algorithm, which partitions the array and returns the index of the pivot element.
- **quickSort**: Recursive function to sort the array using the QuickSort algorithm.
- **findKthSmallest**: Uses `quickSort` to sort the array and returns the Kth smallest element by accessing `arr[k - 1]`.
- **findKthLargest**: Similarly uses `quickSort` and returns the Kth largest element by accessing `arr[n - k]`.
- **main**: 
  - Reads the size of the array (`n`) and its elements.
  - Reads the value of `K`.
  - Calls `findKthSmallest` and `findKthLargest` functions to find and print the Kth smallest and largest elements respectively.

### Usage:
- Compile the program using a C compiler (e.g., `gcc`).
- Run the executable and enter the required inputs (size of array, elements of array, and value of K).
- The program will output the Kth smallest and Kth largest elements of the array.

This approach is efficient with a time complexity of \(O(n \log n)\) due to sorting, followed by \(O(1)\) for accessing the Kth smallest or largest element.
