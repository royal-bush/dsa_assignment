Program 6: Min and Max Heap Implementation

Overview
This program implements both min heap and max heap data structures using array representation. Min heap maintains the minimum element at the root, while max heap maintains the maximum element at the root. The program demonstrates heap construction, insertion, deletion, and heap sort.

Data Structures

Min Heap Structure
typedef struct {
int items[MAX_HEAP_SIZE];
int size;
} MinHeap;

Max Heap Structure
typedef struct {
int items[MAX_HEAP_SIZE];
int size;
} MaxHeap;

Both heaps use array representation where:The root is at index 0.The parent of node i is at index (i-1)/2.The left child of node i is at index 2i+1.The right child of node i is at index 2i+2.

Functions Implemented

Index Utility Functions

1.getParent(int index)
Purpose
Get the parent index of a node

2.getLeftChild(int index)
Purpose
Get the left child index

3.getRightChild(int index)
Purpose
Get the right child index

4.swap(int *a, int *b)
Purpose
Swap two integer values

MIN HEAP OPERATIONS

5.initMinHeap(MinHeap *heap)
Purpose
Initialize an empty min heap

6.minHeapifyUp(MinHeap *heap, int index) – KEY OPERATION
Purpose
Move an element up to maintain heap property after insertion

7.minHeapifyDown(MinHeap *heap, int index) – KEY OPERATION
Purpose
Move an element down to maintain heap property after deletion

8.minHeapInsert(MinHeap *heap, int value)
Purpose
Insert a new element into the min heap

9.minHeapExtractMin(MinHeap *heap)
Purpose
Remove and return the minimum element

10.minHeapGetMin(MinHeap *heap)
Purpose
Get the minimum element without removing it

11.buildMinHeap(MinHeap *heap, int array[], int size)
Purpose
Build a min heap from an unsorted array

MAX HEAP OPERATIONS

12.initMaxHeap(MaxHeap *heap)
Purpose
Initialize an empty max heap

13.maxHeapifyUp(MaxHeap *heap, int index)
Purpose
Move an element up (for max heap)

14.maxHeapifyDown(MaxHeap *heap, int index)
Purpose
Move an element down (for max heap)

15.maxHeapInsert(MaxHeap *heap, int value)
Purpose
Insert into the max heap

16.maxHeapExtractMax(MaxHeap *heap)
Purpose
Remove and return the maximum element

17.maxHeapGetMax(MaxHeap *heap)
Purpose
Get the maximum element without removing it

18.buildMaxHeap(MaxHeap *heap, int array[], int size)
Purpose
Build a max heap from an unsorted array

Display Functions

19.displayHeap(int heap[], int size, char *heapType)
Purpose
Display the heap in linear form

20.displayHeapStructure(int heap[], int size, char *heapType)
Purpose
Display the heap with parent-child relationships

Sample Output

=== Min and Max Heap Implementation ===

Unsorted array: 45 23 56 12 34 78 90 15 67 38

=== MIN HEAP ===
Min Heap: 12 15 34 23 38 78 90 45 67 56

Min Heap Tree Structure:
Index 0: 12 (Parent: -1)
Index 1: 15 (Parent: 12)
Index 2: 34 (Parent: 12)
...

Minimum (root): 12

Extracting elements from the min heap:
12 15 23 34 38 45 56 67 78 90

=== MAX HEAP ===
Max Heap: 90 78 56 45 67 23 34 12 15 38

Extracting elements from the max heap:
90 78 67 56 45 38 34 23 15 12

=== HEAP SORT ===

Sorted in ascending order (using min heap):
12 15 23 34 38 45 56 67 78 90

Sorted in descending order (using max heap):
90 78 67 56 45 38 34 23 15 12

=== HEAP OPERATIONS ===
Inserting values into the min heap: 5, 10, 15, 20, 25
Min Heap: 5 10 15 20 25

Inserting 2 into the min heap
Min Heap: 2 10 5 20 25 15

Extracting minimum: 2
Min Heap: 5 10 15 20 25

Compilation and Execution

gcc -o prog_6 prog_6.c
./prog_6
