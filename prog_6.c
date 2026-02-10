#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Min Heap structure
typedef struct {
    int items[MAX_HEAP_SIZE];
    int size;
} MinHeap;

// Max Heap structure
typedef struct {
    int items[MAX_HEAP_SIZE];
    int size;
} MaxHeap;

// Utility functions for Min Heap

// Get parent index
int getParent(int index) {
    return (index - 1) / 2;
}

// Get left child index
int getLeftChild(int index) {
    return 2 * index + 1;
}

// Get right child index
int getRightChild(int index) {
    return 2 * index + 2;
}

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ===== MIN HEAP FUNCTIONS =====

// Initialize min heap
void initMinHeap(MinHeap *heap) {
    heap->size = 0;
}

// Heapify up for min heap (for insertion)
void minHeapifyUp(MinHeap *heap, int index) {
    while (index > 0 && heap->items[getParent(index)] > heap->items[index]) {
        swap(&heap->items[getParent(index)], &heap->items[index]);
        index = getParent(index);
    }
}

// Heapify down for min heap (for deletion)
void minHeapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);
    
    if (leftChild < heap->size && heap->items[leftChild] < heap->items[smallest]) {
        smallest = leftChild;
    }
    
    if (rightChild < heap->size && heap->items[rightChild] < heap->items[smallest]) {
        smallest = rightChild;
    }
    
    if (smallest != index) {
        swap(&heap->items[index], &heap->items[smallest]);
        minHeapifyDown(heap, smallest);
    }
}

// Insert element into min heap
void minHeapInsert(MinHeap *heap, int value) {
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Min heap overflow!\n");
        return;
    }
    
    heap->items[heap->size] = value;
    minHeapifyUp(heap, heap->size);
    heap->size++;
}

// Extract minimum element from min heap
int minHeapExtractMin(MinHeap *heap) {
    if (heap->size == 0) {
        printf("Min heap is empty!\n");
        return -1;
    }
    
    int min = heap->items[0];
    heap->items[0] = heap->items[heap->size - 1];
    heap->size--;
    
    if (heap->size > 0) {
        minHeapifyDown(heap, 0);
    }
    
    return min;
}

// Get minimum element from min heap
int minHeapGetMin(MinHeap *heap) {
    if (heap->size == 0) {
        printf("Min heap is empty!\n");
        return -1;
    }
    return heap->items[0];
}

// ===== MAX HEAP FUNCTIONS =====

// Initialize max heap
void initMaxHeap(MaxHeap *heap) {
    heap->size = 0;
}

// Heapify up for max heap (for insertion)
void maxHeapifyUp(MaxHeap *heap, int index) {
    while (index > 0 && heap->items[getParent(index)] < heap->items[index]) {
        swap(&heap->items[getParent(index)], &heap->items[index]);
        index = getParent(index);
    }
}

// Heapify down for max heap (for deletion)
void maxHeapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);
    
    if (leftChild < heap->size && heap->items[leftChild] > heap->items[largest]) {
        largest = leftChild;
    }
    
    if (rightChild < heap->size && heap->items[rightChild] > heap->items[largest]) {
        largest = rightChild;
    }
    
    if (largest != index) {
        swap(&heap->items[index], &heap->items[largest]);
        maxHeapifyDown(heap, largest);
    }
}

// Insert element into max heap
void maxHeapInsert(MaxHeap *heap, int value) {
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Max heap overflow!\n");
        return;
    }
    
    heap->items[heap->size] = value;
    maxHeapifyUp(heap, heap->size);
    heap->size++;
}

// Extract maximum element from max heap
int maxHeapExtractMax(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Max heap is empty!\n");
        return -1;
    }
    
    int max = heap->items[0];
    heap->items[0] = heap->items[heap->size - 1];
    heap->size--;
    
    if (heap->size > 0) {
        maxHeapifyDown(heap, 0);
    }
    
    return max;
}

// Get maximum element from max heap
int maxHeapGetMax(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Max heap is empty!\n");
        return -1;
    }
    return heap->items[0];
}

// Build min heap from array
void buildMinHeap(MinHeap *heap, int array[], int size) {
    heap->size = 0;
    
    for (int i = 0; i < size; i++) {
        minHeapInsert(heap, array[i]);
    }
}

// Build max heap from array
void buildMaxHeap(MaxHeap *heap, int array[], int size) {
    heap->size = 0;
    
    for (int i = 0; i < size; i++) {
        maxHeapInsert(heap, array[i]);
    }
}

// Display heap
void displayHeap(int heap[], int size, char *heapType) {
    printf("%s: ", heapType);
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Display heap in tree structure
void displayHeapStructure(int heap[], int size, char *heapType) {
    printf("\n%s Tree Structure:\n", heapType);
    
    for (int i = 0; i < size; i++) {
        printf("Index %d: %d (Parent: %d)\n", 
            i, heap[i], 
            i == 0 ? -1 : heap[getParent(i)]);
    }
}

int main() {
    printf("=== Min and Max Heap Implementation ===\n\n");
    
    // Unsorted array
    int array[] = {45, 23, 56, 12, 34, 78, 90, 15, 67, 38};
    int arraySize = sizeof(array) / sizeof(array[0]);
    
    printf("Unsorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    // Build Min Heap
    MinHeap minHeap;
    initMinHeap(&minHeap);
    buildMinHeap(&minHeap, array, arraySize);
    
    printf("=== MIN HEAP ===\n");
    displayHeap(minHeap.items, minHeap.size, "Min Heap");
    displayHeapStructure(minHeap.items, minHeap.size, "Min");
    
    printf("\nMin Heap Extract Operations:\n");
    printf("Minimum (root): %d\n", minHeapGetMin(&minHeap));
    
    printf("\nExtracting elements from min heap:\n");
    MinHeap tempMinHeap = minHeap;
    while (tempMinHeap.size > 0) {
        printf("%d ", minHeapExtractMin(&tempMinHeap));
    }
    printf("\n");
    
    // Build Max Heap
    MaxHeap maxHeap;
    initMaxHeap(&maxHeap);
    buildMaxHeap(&maxHeap, array, arraySize);
    
    printf("\n=== MAX HEAP ===\n");
    displayHeap(maxHeap.items, maxHeap.size, "Max Heap");
    displayHeapStructure(maxHeap.items, maxHeap.size, "Max");
    
    printf("\nMax Heap Extract Operations:\n");
    printf("Maximum (root): %d\n", maxHeapGetMax(&maxHeap));
    
    printf("\nExtracting elements from max heap:\n");
    MaxHeap tempMaxHeap = maxHeap;
    while (tempMaxHeap.size > 0) {
        printf("%d ", maxHeapExtractMax(&tempMaxHeap));
    }
    printf("\n");
    
    // Heap Sort using both heaps
    printf("\n=== HEAP SORT ===\n");
    
    printf("\nSorted in ascending order (using min heap):\n");
    MinHeap sortedMinHeap;
    initMinHeap(&sortedMinHeap);
    buildMinHeap(&sortedMinHeap, array, arraySize);
    while (sortedMinHeap.size > 0) {
        printf("%d ", minHeapExtractMin(&sortedMinHeap));
    }
    printf("\n");
    
    printf("\nSorted in descending order (using max heap):\n");
    MaxHeap sortedMaxHeap;
    initMaxHeap(&sortedMaxHeap);
    buildMaxHeap(&sortedMaxHeap, array, arraySize);
    while (sortedMaxHeap.size > 0) {
        printf("%d ", maxHeapExtractMax(&sortedMaxHeap));
    }
    printf("\n");
    
    // Heap operations
    printf("\n=== HEAP OPERATIONS ===\n");
    
    MinHeap operationHeap;
    initMinHeap(&operationHeap);
    
    printf("Inserting values into min heap: 5, 10, 15, 20, 25\n");
    minHeapInsert(&operationHeap, 5);
    minHeapInsert(&operationHeap, 10);
    minHeapInsert(&operationHeap, 15);
    minHeapInsert(&operationHeap, 20);
    minHeapInsert(&operationHeap, 25);
    
    displayHeap(operationHeap.items, operationHeap.size, "Min Heap after insertions");
    
    printf("\nInserting 2 into min heap\n");
    minHeapInsert(&operationHeap, 2);
    displayHeap(operationHeap.items, operationHeap.size, "Min Heap after inserting 2");
    
    printf("\nExtracting minimum:  %d\n", minHeapExtractMin(&operationHeap));
    displayHeap(operationHeap.items, operationHeap.size, "Min Heap after extraction");
    
    return 0;
}
