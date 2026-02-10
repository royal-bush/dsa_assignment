Program 8: Sorting Algorithms with Statistics

Overview
This program implements four different sorting algorithms and provides comprehensive performance statistics including the number of comparisons, swaps, and execution time. It allows users to generate random integer arrays and choose their preferred sorting algorithm.

Data Structures

Statistics Structure
typedef struct {
    long long comparisons;
    long long swaps;
    double executionTime;
} SortStats;

comparisons: Total number of key comparisons performed
swaps: Total number of element exchanges
executionTime: Execution time in seconds

Functions Implemented

Utility Functions

1.printArray(int arr[], int n, int limit)
Purpose
Display array with limit on elements shown

2.fillRandomArray(int arr[], int n, int minVal, int maxVal)
Purpose
Fill array with random integers in the specified range

3.copyArray(int src[], int dest[], int n)
Purpose
Copy one array to another (for reusing original)

4.displayStats(char *sortName, int n, SortStats stats)
Purpose
Display sorting statistics in a formatted output

5.showMenu()
Purpose
Display algorithm selection menu

Sorting Algorithms

6.bubbleSort(int arr[], int n) – ALGORITHM 1
Purpose
Sort using bubble sort

7.selectionSort(int arr[], int n) – ALGORITHM 2
Purpose
Sort using selection sort

8.insertionSort(int arr[], int n) – ALGORITHM 3
Purpose
Sort using insertion sort

9.merge(int arr[], int left, int mid, int right, SortStats *stats) – HELPER
Purpose
Merge two sorted subarrays

10.mergeSortHelper(int arr[], int left, int right, SortStats *stats) – HELPER
Purpose
Recursive helper for merge sort

11.mergeSort(int arr[], int n) – ALGORITHM 4
Purpose
Sort using merge sort

Sample Output

=== Sorting Algorithm Comparison with Statistics ===

Enter the number of random integers to generate (1-1000): 50  
Generated 50 random numbers in range [1, 1000]  
Original Array (first 20 elements): [ 456 234 789 123 567 890 345 ... ]

=== Select Sorting Algorithm ===  
...

Original Array (first 20 elements): [ 456 234 789 123 567 890 345 ... ]  
Sorted Array (first 20 elements):   [ 123 234 345 456 567 789 890 ... ]

=== Bubble Sort Statistics ===  
Array Size:        50  
Comparisons:       1225  
Swaps:             450  
Execution Time:    0.000123 seconds  
Sorted Correctly: YES

=== Performance Comparison ===  
Algorithm          Comparisons      Swaps           Time (seconds)  
----------         -----------      -----           ---------------  
Bubble Sort        1225             450             0.000123  
Selection Sort     1225             49              0.000098  
Insertion Sort     625              450             0.000087  
Merge Sort         405              0               0.000056  

Compilation and Execution
gcc -o prog_8 prog_8.c  
./prog_8

