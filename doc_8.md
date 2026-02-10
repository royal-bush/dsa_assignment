# Program 8: Sorting Algorithms with Statistics

## Overview
This program implements four different sorting algorithms and provides comprehensive performance statistics including number of comparisons, swaps, and execution time. It allows users to generate random integer arrays and choose their preferred sorting algorithm.

## Data Structures

### Statistics Structure
```c
typedef struct {
    long long comparisons;
    long long swaps;
    double executionTime;
} SortStats;
```
- `comparisons`: Total number of key comparisons performed
- `swaps`: Total number of element exchanges
- `executionTime`: Execution time in seconds

## Functions Implemented

### Utility Functions

#### 1. `printArray(int arr[], int n, int limit)`
- **Purpose**: Display array with limit on elements shown
- **Shows**: First `limit` elements, then "..." if more

#### 2. `fillRandomArray(int arr[], int n, int minVal, int maxVal)`
- **Purpose**: Fill array with random integers in range
- **Uses**: Standard `rand()` function with seed from current time

#### 3. `copyArray(int src[], int dest[], int n)`
- **Purpose**: Copy one array to another (for reusing original)

#### 4. `displayStats(char *sortName, int n, SortStats stats)`
- **Purpose**: Display sorting statistics in formatted output
- **Shows**: Algorithm name, size, comparisons, swaps, time

#### 5. `showMenu()`
- **Purpose**: Display algorithm selection menu
- **Returns**: User's choice (1-5)

### Sorting Algorithms

#### 6. `bubbleSort(int arr[], int n)` - **ALGORITHM 1**
- **Purpose**: Sort using bubble sort
- **Algorithm**:
  1. Compare adjacent elements
  2. Swap if left > right
  3. Repeat for remaining unsorted portion
  4. Continue until no swaps occur
- **Time Complexity**: 
  - Best: O(n) with optimization
  - Average: O(n²)
  - Worst: O(n²)
- **Space Complexity**: O(1)
- **Characteristic**: Stable, simple, inefficient
- **Comparisons**: n(n-1)/2
- **Swaps**: Up to n(n-1)/2

#### 7. `selectionSort(int arr[], int n)` - **ALGORITHM 2**
- **Purpose**: Sort using selection sort
- **Algorithm**:
  1. Find minimum element in unsorted portion
  2. Swap with first unsorted element
  3. Move boundary of sorted portion
  4. Repeat until entire array sorted
- **Time Complexity**: 
  - All cases: O(n²)
- **Space Complexity**: O(1)
- **Characteristic**: Not stable, simple, consistent
- **Comparisons**: n(n-1)/2
- **Swaps**: n-1 maximum
- **Advantage**: Minimum number of swaps

#### 8. `insertionSort(int arr[], int n)` - **ALGORITHM 3**
- **Purpose**: Sort using insertion sort
- **Algorithm**:
  1. Start from second element
  2. Compare with sorted portion
  3. Shift larger elements right
  4. Insert current element in correct position
  5. Repeat for remaining elements
- **Time Complexity**:
  - Best: O(n) when already sorted
  - Average: O(n²)
  - Worst: O(n²)
- **Space Complexity**: O(1)
- **Characteristic**: Stable, efficient for small arrays, adaptive
- **Comparisons**: n(n-1)/4 average
- **Swaps**: n(n-1)/4 average
- **Advantage**: Efficient for nearly sorted data

#### 9. `merge(int arr[], int left, int mid, int right, SortStats *stats)` - **HELPER**
- **Purpose**: Merge two sorted subarrays
- **Algorithm**:
  1. Create temporary array
  2. Compare elements from both halves
  3. Place smaller element in result
  4. Copy remaining elements
  5. Copy result back to original array
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) temporary array

#### 10. `mergeSortHelper(int arr[], int left, int right, SortStats *stats)` - **HELPER**
- **Purpose**: Recursive helper for merge sort
- **Algorithm**:
  1. Find middle point
  2. Recursively sort left half
  3. Recursively sort right half
  4. Merge sorted halves
- **Time Complexity**: O(n log n)

#### 11. `mergeSort(int arr[], int n)` - **ALGORITHM 4**
- **Purpose**: Sort using merge sort
- **Algorithm**:
  1. Divide array into two halves
  2. Recursively sort each half
  3. Merge sorted halves
  4. Return merged result
- **Time Complexity**: All cases O(n log n)
- **Space Complexity**: O(n) for temporary array
- **Characteristic**: Stable, divide-and-conquer, consistent
- **Comparisons**: n log n approximately
- **Swaps**: n log n (in merge operation)
- **Advantage**: Guaranteed O(n log n), stable sort

### Main Program Features

The `main()` function:
1. Prompts user for array size (1-1000)
2. Generates random array in range [1, 1000]
3. Displays original array (first 20 elements)
4. Provides interactive menu for algorithm selection
5. For each algorithm:
   - Sorts the array
   - Displays before/after (first 20 elements)
   - Shows comprehensive statistics
   - Validates correctness
6. After user exits, runs all algorithms for comparison
7. Displays performance comparison table

## Performance Characteristics

| Algorithm | Best Case | Avg Case | Worst Case | Space | Stable | Adaptive |
|-----------|-----------|----------|-----------|-------|--------|----------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | No | No |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No |

## Statistics Interpretation

### Comparisons
- Count of key comparison operations
- Lower is better
- Related to number of decisions made

### Swaps
- Count of element exchanges
- Lower is better
- Not applicable for all algorithms
- Some algorithms shift instead of swap

### Execution Time
- Actual wall-clock time
- Depends on system performance
- May vary between runs
- Useful for relative comparison

## Sample Output

```
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
```

## Complexity Comparison

### Time Complexity Growth
- **O(n²)**: Bubble, Selection, Insertion
  - Quadratic growth
  - For n=1000: ~1,000,000 operations
  - For n=10,000: ~100,000,000 operations

- **O(n log n)**: Merge Sort
  - Much better scaling
  - For n=1000: ~10,000 operations
  - For n=10,000: ~130,000 operations

## When to Use Each Algorithm

### Bubble Sort
- Small arrays
- Educational purposes
- Nearly sorted data (with optimization)
- **Avoid**: Large datasets

### Selection Sort
- Minimize swaps is important
- Simple implementation needed
- Small arrays
- **Avoid**: Large datasets

### Insertion Sort
- Already sorted or nearly sorted data
- Small to medium arrays
- Online sorting (sorting stream)
- Efficient for small arrays
- **Avoid**: Large unsorted datasets

### Merge Sort
- Large datasets
- Guaranteed O(n log n)
- Stable sort needed
- External sorting
- **Disadvantage**: Extra space required

## Compilation and Execution

```bash
gcc -o prog_8 prog_8.c
./prog_8
```

### Example Run
```bash
$ ./prog_8
=== Sorting Algorithm Comparison with Statistics ===

Enter the number of random integers to generate (1-1000): 100
```

## Key Features

1. **Interactive Menu**: Choose algorithm to test
2. **Random Generation**: Generate custom-sized test data
3. **Comprehensive Statistics**: Compare different metrics
4. **Validation**: Verify sorted output correctness
5. **Batch Comparison**: Run all algorithms at once
6. **Performance Table**: Side-by-side comparison

## Extensions and Improvements

Possible enhancements:
1. Quick Sort algorithm
2. Heap Sort algorithm
3. Shell Sort algorithm
4. Radix Sort for integers
5. Bucket Sort
6. Visualization of sorting process
7. Test with different distributions (sorted, reverse, random)
8. Save results to file
9. Timing with high precision timer
10. 3-way partitioning for duplicates

## Important Notes

1. **Statistics are for this implementation**: Different implementations may have different operation counts
2. **Timing is system-dependent**: Multiple runs may show variations
3. **Comparisons don't include function calls**: Overhead varies by compiler
4. **Memory is not freed in some paths**: Add cleanup for production code
5. **Overflow possible**: For very large arrays with long long counters not enough
