Program 4: Doubly Linked List Implementation

Overview
This program implements a doubly linked list data structure using dynamic memory allocation. It demonstrates insertion and deletion operations at various positions in the list, including insertion after and before specific nodes.

Data Structures

Node Structure:
typedef struct Node {
int data;
struct Node *prev;
struct Node *next;
} Node;

The data field stores the integer value. The prev pointer points to the previous node and is NULL for the first node. The next pointer points to the next node and is NULL for the last node.

Functions Implemented

Node Creation

1.createNode(int data)
Purpose
Create and initialize a new node

Insertion Operations

2.insertAtBeginning(Node **head, int data)
Purpose
Insert a node at the beginning of the list

3.insertAtEnd(Node **head, int data)
Purpose
Insert a node at the end of the list

4.insertAfter(Node *prevNode, int data)
Purpose
Insert a node after a given node

5.insertBefore(Node **head, Node *nextNode, int data)
Purpose
Insert a node before a given node

Deletion Operations

6.deleteNode(Node **head, Node *nodeToDelete)
Purpose
Delete a specific node from the list

7.deleteByValue(Node **head, int value)
Purpose
Delete all nodes that contain a specific value

Search Operations

8.findNode(Node *head, int value)
Purpose
Search for a node containing a specific value

Display Operations

9.displayForward(Node *head)
Purpose
Display the linked list in forward direction

10.displayBackward(Node *head)
Purpose
Display the linked list in backward direction

Utility Operations

11.getCount(Node *head)
Purpose
Count the total number of nodes in the list

12.freeList(Node *head)
Purpose
Free all dynamically allocated memory in the list

Sample Output

Doubly Linked List Operations

Inserting elements at the end: 10, 20, 30, 40, 50
Forward traversal
10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

Backward traversal
50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL

Total nodes: 5

Inserting 5 at the beginning
Forward traversal
5 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

Total nodes: 6

Inserting 25 after node with value 20
Forward traversal
5 <-> 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 <-> NULL

Total nodes: 7

Inserting 15 before node with value 20
Forward traversal
5 <-> 10 <-> 15 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 <-> NULL

Total nodes: 8

Deleting node with value 25
Forward traversal
5 <-> 10 <-> 15 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

Backward traversal
50 <-> 40 <-> 30 <-> 20 <-> 15 <-> 10 <-> 5 <-> NULL

Total nodes: 7

Deleting node with value 40
Forward traversal
5 <-> 10 <-> 15 <-> 20 <-> 30 <-> 50 <-> NULL

Total nodes: 6

Backward traversal
50 <-> 30 <-> 20 <-> 15 <-> 10 <-> 5 <-> NULL

List freed successfully


Compilation and Execution

gcc -o prog_4 prog_4.c
./prog_4
