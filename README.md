Data Structures and Algorithms Assignment

This repository contains implementations of 8 comprehensive data structures and algorithms problems. Each program is implemented in C with documentation covering the data structures used, algorithms implemented, and examples.

Projects Overview

Balanced Parentheses Checker (prog_1.c)
Concept: Stack data structure
Task: Check if mathematical expressions have balanced parentheses
Run: gcc -o prog_1 prog_1.c && ./prog_1

Infix to Postfix Conversion and Evaluation (prog_2.c)
Concept: Stack, operator precedence, Shunting Yard algorithm
Task: Convert infix expressions to postfix and evaluate them
Run: gcc -o prog_2 prog_2.c -lm && ./prog_2

Linked List Reverse Traversal (prog_3.c)
Concept: Singly linked list, recursion
Task: Implement reverse traversal without reversing the list
Run: gcc -o prog_3 prog_3.c && ./prog_3

Doubly Linked List (prog_4.c)
Concept: Doubly linked list with bidirectional traversal
Task: Insert after or before nodes and delete nodes
Run: gcc -o prog_4 prog_4.c && ./prog_4

Graph BFS and DFS (prog_5.c)
Concept: Undirected graph using adjacency matrix
Task: Implement BFS and DFS traversal algorithms
Run: gcc -o prog_5 prog_5.c && ./prog_5

Min and Max Heaps (prog_6.c)
Concept: Heap data structure using array representation
Task: Build, insert, and delete in min and max heaps
Run: gcc -o prog_6 prog_6.c && ./prog_6

Dijkstra’s Algorithm (prog_7.c)
Concept: Shortest path algorithm on weighted graphs
Task: Find shortest paths from source to all vertices
Run: gcc -o prog_7 prog_7.c && ./prog_7

Sorting Algorithms with Statistics (prog_8.c)
Concept: Multiple sorting algorithms with performance analysis
Task: Implement and compare Bubble Sort, Selection Sort, Insertion Sort, and Merge Sort
Run: gcc -o prog_8 prog_8.c && ./prog_8

Documentation

Each program has a corresponding documentation file named doc_<q>.md containing:
Overview of the data structure or algorithm
Data structure definitions
Function descriptions with complexity analysis
Algorithm explanation with pseudocode
Sample output
Applications and use cases
Compilation and execution instructions

Building and Running All Programs

Compile all programs
gcc -o prog_1 prog_1.c
gcc -o prog_2 prog_2.c -lm
gcc -o prog_3 prog_3.c
gcc -o prog_4 prog_4.c
gcc -o prog_5 prog_5.c
gcc -o prog_6 prog_6.c
gcc -o prog_7 prog_7.c
gcc -o prog_8 prog_8.c

Run individual programs
./prog_1
./prog_2
./prog_3
./prog_4
./prog_5
./prog_6
./prog_7
./prog_8
