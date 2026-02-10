# Data Structures and Algorithms Assignment

This repository contains implementations of 8 comprehensive data structures and algorithms problems. Each program is implemented in C with detailed documentation covering the data structures used, algorithms implemented, and complete examples.

## Projects Overview

### 1. Balanced Parentheses Checker (prog_1.c)
- **Concept**: Stack data structure
- **Task**: Check if mathematical expressions have balanced parentheses
- **Features**: Handles three types of brackets: `()`, `[]`, `{}`
- **Run**: `gcc -o prog_1 prog_1.c && ./prog_1`

### 2. Infix to Postfix Conversion & Evaluation (prog_2.c)
- **Concept**: Stack, operator precedence, Shunting Yard algorithm
- **Task**: Convert infix expressions to postfix and evaluate them
- **Features**: Handles +, -, *, /, ^ operators with proper precedence
- **Run**: `gcc -o prog_2 prog_2.c -lm && ./prog_2`

### 3. Linked List - Reverse Traversal (prog_3.c)
- **Concept**: Singly linked list, recursion
- **Task**: Implement reverse traversal without reversing the list
- **Features**: Three different reverse traversal methods
- **Run**: `gcc -o prog_3 prog_3.c && ./prog_3`

### 4. Doubly Linked List (prog_4.c)
- **Concept**: Doubly linked list with bidirectional traversal
- **Task**: Insert after/before nodes and delete nodes
- **Features**: Insert at beginning/end, insert after/before, delete operations
- **Run**: `gcc -o prog_4 prog_4.c && ./prog_4`

### 5. Graph - BFS & DFS (prog_5.c)
- **Concept**: Undirected graph using adjacency matrix
- **Task**: Implement BFS and DFS traversal algorithms
- **Features**: Breadth-First Search, Depth-First Search, connected components
- **Run**: `gcc -o prog_5 prog_5.c && ./prog_5`

### 6. Min and Max Heaps (prog_6.c)
- **Concept**: Heap data structure using array representation
- **Task**: Build, insert, delete in min and max heaps
- **Features**: Min heap, Max heap, heap sort
- **Run**: `gcc -o prog_6 prog_6.c && ./prog_6`

### 7. Dijkstra's Algorithm (prog_7.c)
- **Concept**: Shortest path algorithm on weighted graphs
- **Task**: Find shortest paths from source to all vertices
- **Features**: Path reconstruction, distance computation, path display
- **Run**: `gcc -o prog_7 prog_7.c && ./prog_7`

### 8. Sorting Algorithms with Statistics (prog_8.c)
- **Concept**: Multiple sorting algorithms with performance analysis
- **Task**: Implement and compare Bubble, Selection, Insertion, Merge Sort
- **Features**: 
  - Generate random arrays
  - Count comparisons and swaps
  - Measure execution time
  - Interactive algorithm selection
  - Performance comparison
- **Run**: `gcc -o prog_8 prog_8.c && ./prog_8`

## Documentation

Each program has a corresponding documentation file (`doc_<q>.md`) containing:
- Overview of the data structure/algorithm
- Data structure definitions
- Function descriptions with complexity analysis
- Algorithm explanation with pseudocode
- Sample output
- Applications and use cases
- Compilation and execution instructions

## Building and Running All Programs

```bash
# Compile all programs
gcc -o prog_1 prog_1.c
gcc -o prog_2 prog_2.c -lm
gcc -o prog_3 prog_3.c
gcc -o prog_4 prog_4.c
gcc -o prog_5 prog_5.c
gcc -o prog_6 prog_6.c
gcc -o prog_7 prog_7.c
gcc -o prog_8 prog_8.c

# Run individual programs
./prog_1
./prog_2
./prog_3
./prog_4
./prog_5
./prog_6
./prog_7
./prog_8
```

## File Structure

```
dsa_assignment/
├── README.md                 (This file)
├── prog_1.c / doc_1.md      (Balanced Parentheses)
├── prog_2.c / doc_2.md      (Infix to Postfix)
├── prog_3.c / doc_3.md      (Linked List Reverse)
├── prog_4.c / doc_4.md      (Doubly Linked List)
├── prog_5.c / doc_5.md      (Graph BFS/DFS)
├── prog_6.c / doc_6.md      (Min/Max Heaps)
├── prog_7.c / doc_7.md      (Dijkstra's Algorithm)
└── prog_8.c / doc_8.md      (Sorting Algorithms)
```

## Key Concepts Covered

### Data Structures
- Stack
- Linked List (Singly and Doubly)
- Graph (Adjacency Matrix)
- Heap (Min and Max)
- Queue (implicit in BFS)

### Algorithms
- Bracket Balancing (Stack application)
- Expression Conversion (Shunting Yard)
- Graph Traversal (BFS, DFS)
- Shortest Path (Dijkstra's)
- Sorting (4 algorithms with analysis)

### Complexity Analysis
- Time Complexity
- Space Complexity
- Comparison and swap counting
- Performance measurements

## Requirements

- GCC compiler
- Linux/Unix environment (or any POSIX-compliant system)
- No external libraries (except math.h for prog_2)

## Submission Guidelines

1. All source files are implemented as `prog_<q>.c`
2. Each program has detailed documentation in `doc_<q>.md`
3. Code is properly structured with comments
4. Functions are modular and reusable
5. Each program includes a main() demonstrating usage
6. Programs are tested and working correctly

## Author

Data Structures and Algorithms Assignment
February 2026

## License

Educational use only