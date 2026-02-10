Program 3: Linked List – Reverse Traversal

Overview
This program implements a singly linked list and demonstrates three different methods to traverse the list in reverse order without actually reversing the linked list itself.

Data Structures

Node Structure:    
typedef struct Node {
int data;
struct Node *next;
} Node;

The node stores an integer data value and a pointer to the next node in the list.

Functions Implemented

Basic Operations:

1.createNode(int data)
Purpose
Create a new node with the given data value

2.insertAtEnd(Node **head, int data)
Purpose
Insert a node at the end of the linked list

Display Functions

3.displayForward(Node *head)
Purpose
Display the linked list in forward direction

Reverse Traversal Methods

4.reverseTraversalRecursive(Node *head)
Purpose
Recursively traverse and print the linked list in reverse order

5.displayReverse(Node *head)
Purpose
Wrapper function that calls the recursive reverse traversal function

6.reverseIterative(Node *head)
Purpose
Reverse traversal using node counting technique

Helper Functions

7.getLength(Node *head)
Purpose
Calculate the total number of nodes in the linked list

8.getNthNode(Node *head, int n)
Purpose
Retrieve a pointer to the nth node from the beginning (zero indexed)

9.freeList(Node *head)
Purpose
Free all dynamically allocated memory in the linked list

Sample Output

Linked List – Reverse Traversal

Inserting elements: 10, 20, 30, 40, 50

Forward traversal
10 20 30 40 50

Method 1 Recursive Traversal
Reverse traversal
50 40 30 20 10

Method 2 Iterative Traversal using position-based method
Reverse traversal
50 40 30 20 10

Method 3 Node-counting iterative traversal
Reverse traversal
50 40 30 20 10

Additional Operations
Length of list: 5
Third node value: 30

List freed successfully

Compilation and Execution

gcc -o prog_3 prog_3.c
./prog_3
