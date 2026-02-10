#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

// Statistics structure
typedef struct {
    long long comparisons;
    long long swaps;
    double executionTime;
} SortStats;

// Function to print array
void printArray(int arr[], int n, int limit) {
    printf("[ ");
    for (int i = 0; i < n && i < limit; i++) {
        printf("%d ", arr[i]);
    }
    if (n > limit) {
        printf("... ");
    }
    printf("]\n");
}

// ===== BUBBLE SORT =====
SortStats bubbleSort(int arr[], int n) {
    SortStats stats = {0, 0, 0};
    clock_t start = clock();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            stats.comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                stats.swaps++;
            }
        }
    }
    
    clock_t end = clock();
    stats.executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    
    return stats;
}

// ===== SELECTION SORT =====
SortStats selectionSort(int arr[], int n) {
    SortStats stats = {0, 0, 0};
    clock_t start = clock();
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            stats.comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            // Swap
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            stats.swaps++;
        }
    }
    
    clock_t end = clock();
    stats.executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    
    return stats;
}

// ===== INSERTION SORT =====
SortStats insertionSort(int arr[], int n) {
    SortStats stats = {0, 0, 0};
    clock_t start = clock();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            stats.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats.swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    
    clock_t end = clock();
    stats.executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    
    return stats;
}

// ===== MERGE SORT =====
void merge(int arr[], int left, int mid, int right, SortStats *stats) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];
    
    while (i <= mid && j <= right) {
        stats->comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
        stats->swaps++;
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSortHelper(int arr[], int left, int right, SortStats *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortHelper(arr, left, mid, stats);
        mergeSortHelper(arr, mid + 1, right, stats);
        merge(arr, left, mid, right, stats);
    }
}

SortStats mergeSort(int arr[], int n) {
    SortStats stats = {0, 0, 0};
    clock_t start = clock();
    
    mergeSortHelper(arr, 0, n - 1, &stats);
    
    clock_t end = clock();
    stats.executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    
    return stats;
}

// Fill array with random numbers
void fillRandomArray(int arr[], int n, int minVal, int maxVal) {
    for (int i = 0; i < n; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// Copy array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Display statistics
void displayStats(char *sortName, int n, SortStats stats) {
    printf("\n=== %s Statistics ===\n", sortName);
    printf("Array Size:        %d\n", n);
    printf("Comparisons:       %lld\n", stats.comparisons);
    printf("Swaps:             %lld\n", stats.swaps);
    printf("Execution Time:    %.6f seconds\n", stats.executionTime);
}

// Menu for sorting algorithm selection
int showMenu() {
    printf("\n=== Select Sorting Algorithm ===\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
    
    int choice;
    scanf("%d", &choice);
    return choice;
}

int main() {
    printf("=== Sorting Algorithm Comparison with Statistics ===\n\n");
    
    srand(time(NULL));
    
    // Get number of elements from user
    int n;
    printf("Enter the number of random integers to generate (1-1000): ");
    scanf("%d", &n);
    
    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid size! Using default size: 100\n");
        n = 100;
    }
    
    // Generate random array
    int *originalArray = (int *)malloc(n * sizeof(int));
    if (originalArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    fillRandomArray(originalArray, n, 1, 1000);
    
    printf("\nGenerated %d random numbers in range [1, 1000]\n", n);
    printf("Original Array (first 20 elements): ");
    printArray(originalArray, n, 20);
    
    int *sortedArray = (int *)malloc(n * sizeof(int));
    int choice;
    
    while ((choice = showMenu()) != 5) {
        if (choice < 1 || choice > 4) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }
        
        // Copy original array for sorting
        copyArray(originalArray, sortedArray, n);
        
        SortStats stats;
        char *sortName;
        
        // Perform selected sorting
        switch (choice) {
            case 1:
                stats = bubbleSort(sortedArray, n);
                sortName = "Bubble Sort";
                break;
            case 2:
                stats = selectionSort(sortedArray, n);
                sortName = "Selection Sort";
                break;
            case 3:
                stats = insertionSort(sortedArray, n);
                sortName = "Insertion Sort";
                break;
            case 4:
                stats = mergeSort(sortedArray, n);
                sortName = "Merge Sort";
                break;
            default:
                continue;
        }
        
        // Display results
        printf("\n");
        printf("Original Array (first 20 elements): ");
        printArray(originalArray, n, 20);
        
        printf("\nSorted Array (first 20 elements):   ");
        printArray(sortedArray, n, 20);
        
        displayStats(sortName, n, stats);
        
        // Validate sorted array
        int isSorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (sortedArray[i] > sortedArray[i + 1]) {
                isSorted = 0;
                break;
            }
        }
        printf("Sorted Correctly: %s\n", isSorted ? "YES" : "NO");
    }
    
    // Demonstration with all algorithms
    printf("\n\n=== Comparison of All Algorithms ===\n");
    printf("Sorting %d elements...\n\n", n);
    
    int *demoArray = (int *)malloc(n * sizeof(int));
    
    // Bubble Sort
    copyArray(originalArray, demoArray, n);
    SortStats bubbleStats = bubbleSort(demoArray, n);
    displayStats("Bubble Sort", n, bubbleStats);
    
    // Selection Sort
    copyArray(originalArray, demoArray, n);
    SortStats selectionStats = selectionSort(demoArray, n);
    displayStats("Selection Sort", n, selectionStats);
    
    // Insertion Sort
    copyArray(originalArray, demoArray, n);
    SortStats insertionStats = insertionSort(demoArray, n);
    displayStats("Insertion Sort", n, insertionStats);
    
    // Merge Sort
    copyArray(originalArray, demoArray, n);
    SortStats mergeStats = mergeSort(demoArray, n);
    displayStats("Merge Sort", n, mergeStats);
    
    // Comparison table
    printf("\n\n=== Performance Comparison ===\n");
    printf("Algorithm          Comparisons      Swaps           Time (seconds)\n");
    printf("----------         -----------      -----           ---------------\n");
    printf("Bubble Sort        %-15lld %-15lld %f\n", 
           bubbleStats.comparisons, bubbleStats.swaps, bubbleStats.executionTime);
    printf("Selection Sort     %-15lld %-15lld %f\n", 
           selectionStats.comparisons, selectionStats.swaps, selectionStats.executionTime);
    printf("Insertion Sort     %-15lld %-15lld %f\n", 
           insertionStats.comparisons, insertionStats.swaps, insertionStats.executionTime);
    printf("Merge Sort         %-15lld %-15lld %f\n", 
           mergeStats.comparisons, mergeStats.swaps, mergeStats.executionTime);
    
    // Free memory
    free(originalArray);
    free(sortedArray);
    free(demoArray);
    
    printf("\nProgram completed successfully!\n");
    
    return 0;
}
