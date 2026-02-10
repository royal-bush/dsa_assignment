# Program 6: Min and Max Heap Implementation

## Overview
This program implements both min heap and max heap data structures using array representation. Min heap maintains minimum element at root while max heap maintains maximum element at root. The program demonstrates heap construction, insertion, deletion, and heap sort.

## Data Structures

### Min Heap Structure
```c
typedef struct {
    int items[MAX_HEAP_SIZE];
    int size;
} MinHeap;
```

### Max Heap Structure
```c
typedef struct {
    int items[MAX_HEAP_SIZE];
    int size;
} MaxHeap;
```

Both use array representation where:
- Root at index 0
- Parent of node i at index (i-1)/2
- Left child of node i at index 2i+1
- Right child of node i at index 2i+2

## Functions Implemented

### Index Utility Functions

#### 1. `getParent(int index)`
- **Purpose**: Get parent index of a node
- **Formula**: (index - 1) / 2
- **Time Complexity**: O(1)

#### 2. `getLeftChild(int index)`
- **Purpose**: Get left child index
- **Formula**: 2 * index + 1
- **Time Complexity**: O(1)

#### 3. `getRightChild(int index)`
- **Purpose**: Get right child index
- **Formula**: 2 * index + 2
- **Time Complexity**: O(1)

#### 4. `swap(int *a, int *b)`
- **Purpose**: Swap two integer values
- **Time Complexity**: O(1)

### MIN HEAP OPERATIONS

#### 5. `initMinHeap(MinHeap *heap)`
- **Purpose**: Initialize empty min heap
- **Sets**: size = 0

#### 6. `minHeapifyUp(MinHeap *heap, int index)` - **KEY OPERATION**
- **Purpose**: Move element up to maintain heap property after insertion
- **Algorithm**:
  1. While index > 0 and parent > current:
     - Swap parent with current
     - Move up to parent's position
- **Time Complexity**: O(log n)
- **Used in**: Insertion

#### 7. `minHeapifyDown(MinHeap *heap, int index)` - **KEY OPERATION**
- **Purpose**: Move element down to maintain heap property after deletion
- **Algorithm**:
  1. Find smallest among node and its children
  2. If smallest is not current node:
     - Swap with smallest
     - Recursively heapify down from that position
- **Time Complexity**: O(log n)
- **Used in**: Extraction

#### 8. `minHeapInsert(MinHeap *heap, int value)`
- **Purpose**: Insert new element into min heap
- **Algorithm**:
  1. Add element at end
  2. Call minHeapifyUp on new element's position
- **Time Complexity**: O(log n)

#### 9. `minHeapExtractMin(MinHeap *heap)`
- **Purpose**: Remove and return minimum element
- **Algorithm**:
  1. Store root (minimum)
  2. Replace root with last element
  3. Reduce size
  4. Call minHeapifyDown from root
- **Time Complexity**: O(log n)
- **Returns**: Minimum value removed

#### 10. `minHeapGetMin(MinHeap *heap)`
- **Purpose**: Get minimum without removing it
- **Returns**: Root element (minimum)
- **Time Complexity**: O(1)

#### 11. `buildMinHeap(MinHeap *heap, int array[], int size)`
- **Purpose**: Build min heap from unsorted array
- **Algorithm**: Insert all elements one by one
- **Time Complexity**: O(n log n)

### MAX HEAP OPERATIONS

#### 12. `initMaxHeap(MaxHeap *heap)`
- **Purpose**: Initialize empty max heap

#### 13. `maxHeapifyUp(MaxHeap *heap, int index)`
- **Purpose**: Move element up (for max heap)
- **Condition**: parent < current (opposite of min heap)
- **Time Complexity**: O(log n)

#### 14. `maxHeapifyDown(MaxHeap *heap, int index)`
- **Purpose**: Move element down (for max heap)
- **Condition**: Find largest among node and children
- **Time Complexity**: O(log n)

#### 15. `maxHeapInsert(MaxHeap *heap, int value)`
- **Purpose**: Insert into max heap
- **Time Complexity**: O(log n)

#### 16. `maxHeapExtractMax(MaxHeap *heap)`
- **Purpose**: Remove and return maximum element
- **Time Complexity**: O(log n)

#### 17. `maxHeapGetMax(MaxHeap *heap)`
- **Purpose**: Get maximum without removing
- **Time Complexity**: O(1)

#### 18. `buildMaxHeap(MaxHeap *heap, int array[], int size)`
- **Purpose**: Build max heap from unsorted array
- **Time Complexity**: O(n log n)

### Display Functions

#### 19. `displayHeap(int heap[], int size, char *heapType)`
- **Purpose**: Display heap in linear form

#### 20. `displayHeapStructure(int heap[], int size, char *heapType)`
- **Purpose**: Display heap with parent-child relationships

## Heap Properties

### Min Heap Property
- Parent ≤ Children
- Minimum element at root
- Used for: Priority queues (ascending), finding minimum

### Max Heap Property
- Parent ≥ Children
- Maximum element at root
- Used for: Priority queues (descending), finding maximum

## Main Function Organization

The program demonstrates:
1. **Heap Construction**: Build min and max heaps from unsorted array
2. **Heap Display**: Show array representation and tree structure
3. **Extraction**: Empty heaps by extracting elements in order
4. **Heap Sort**: Sort using both min and max heaps
5. **Dynamic Operations**: Insert and delete with new values

## Sample Output

```
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

Extracting elements from min heap:
12 15 23 34 38 45 56 67 78 90 

=== MAX HEAP ===
Max Heap: 90 78 56 45 67 23 34 12 15 38 

Extracting elements from max heap:
90 78 67 56 45 38 34 23 15 12 

=== HEAP SORT ===

Sorted in ascending order (using min heap):
12 15 23 34 38 45 56 67 78 90

Sorted in descending order (using max heap):
90 78 67 56 45 38 34 23 15 12

=== HEAP OPERATIONS ===
Inserting values into min heap: 5, 10, 15, 20, 25
Min Heap: 5 10 15 20 25

Inserting 2 into min heap
Min Heap: 2 10 5 20 25 15

Extracting minimum:  2
Min Heap: 5 10 15 20 25
```

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Insert | O(log n) | O(1) |
| Extract Min/Max | O(log n) | O(1) |
| Get Min/Max | O(1) | O(1) |
| Heapify Up | O(log n) | O(1) |
| Heapify Down | O(log n) | O(1) |
| Build Heap | O(n log n)* | O(1) |
| Heap Sort | O(n log n) | O(1) |

*Actual complexity for buildHeap is O(n) using bottom-up approach

## Array Representation vs Other Representations

### Advantages
- O(1) space - no pointers needed
- Cache-friendly - contiguous memory
- Simple parent-child navigation with formulas

### Disadvantages
- Fixed maximum size
- May waste space in dynamic scenarios

## Applications

1. **Priority Queues**: Process elements by priority
2. **Heap Sort**: O(n log n) sorting algorithm
3. **Dijkstra's Algorithm**: Finding shortest paths
4. **Huffman Coding**: Building optimal binary trees
5. **Median Finding**: Using two heaps
6. **Load Balancing**: Scheduling tasks
7. **Top K Elements**: Finding K largest/smallest elements

## Compilation and Execution

```bash
gcc -o prog_6 prog_6.c
./prog_6
```

## Limitations

1. Fixed heap size
2. Only supports integer elements
3. No dynamic resizing
4. No removing arbitrary elements (only min/max)

## Extensions

Could be extended to support:
- Generic data types
- Dynamic array resizing
- Custom comparators
- Remove by value or position
- Heap decrease key operation
