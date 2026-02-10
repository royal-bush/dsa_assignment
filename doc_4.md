# Program 4: Doubly Linked List Implementation

## Overview
This program implements a doubly linked list data structure using dynamic memory allocation. It demonstrates insertion and deletion operations at various positions in the list, including insertion after/before specific nodes.

## Data Structures

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node *prev;  // Pointer to previous node
    struct Node *next;  // Pointer to next node
} Node;
```
- `data`: Stores integer value
- `prev`: Points to previous node (NULL for first node)
- `next`: Points to next node (NULL for last node)

## Functions Implemented

### Node Creation
#### 1. `createNode(int data)`
- **Purpose**: Create and initialize a new node
- **Parameters**: Integer data value
- **Returns**: Pointer to new node
- **Memory**: Dynamically allocated using malloc

### Insertion Operations

#### 2. `insertAtBeginning(Node **head, int data)`
- **Purpose**: Insert node at the beginning of the list
- **Parameters**: Pointer to head, data value
- **Time Complexity**: O(1)
- **Algorithm**:
  1. Create new node
  2. Set new node's next to current head
  3. Update head's prev to new node
  4. Update head to new node

#### 3. `insertAtEnd(Node **head, int data)`
- **Purpose**: Insert node at the end of the list
- **Parameters**: Pointer to head, data value
- **Time Complexity**: O(n)
- **Algorithm**:
  1. Create new node
  2. Traverse to last node
  3. Link new node to last node
  4. Update pointers for bidirectional linking

#### 4. `insertAfter(Node *prevNode, int data)`
- **Purpose**: Insert node after a given node (MAIN OPERATION)
- **Parameters**: Pointer to previous node, data value
- **Time Complexity**: O(1)
- **Algorithm**:
  1. Create new node
  2. Set new node's next to prevNode's next
  3. Set new node's prev to prevNode
  4. Update prevNode->next->prev to new node (if exists)
  5. Update prevNode->next to new node

#### 5. `insertBefore(Node **head, Node *nextNode, int data)`
- **Purpose**: Insert node before a given node
- **Parameters**: Pointer to head, pointer to next node, data value
- **Time Complexity**: O(1)
- **Algorithm**: Similar to insertAfter but in reverse direction

### Deletion Operations

#### 6. `deleteNode(Node **head, Node *nodeToDelete)`
- **Purpose**: Delete a specific node from the list (MAIN OPERATION)
- **Parameters**: Pointer to head, pointer to node to delete
- **Time Complexity**: O(1)
- **Algorithm**:
  1. If node is head, update head to next node
  2. Update prev node's next pointer
  3. Update next node's prev pointer
  4. Free the node's memory

#### 7. `deleteByValue(Node **head, int value)`
- **Purpose**: Delete all nodes with specific value
- **Parameters**: Pointer to head, value to delete
- **Time Complexity**: O(n)
- **Algorithm**: Traverse list and delete matching nodes

### Search Operations

#### 8. `findNode(Node *head, int value)`
- **Purpose**: Find and return node with specific value
- **Parameters**: Head pointer, value to find
- **Returns**: Pointer to node or NULL if not found
- **Time Complexity**: O(n)

### Display Operations

#### 9. `displayForward(Node *head)`
- **Purpose**: Display list in forward direction
- **Format**: `node1 <-> node2 <-> ... <-> NULL`

#### 10. `displayBackward(Node *head)`
- **Purpose**: Display list in backward direction
- **Algorithm**: 
  1. Find last node
  2. Traverse using prev pointers

### Utility Operations

#### 11. `getCount(Node *head)`
- **Purpose**: Count total number of nodes
- **Returns**: Integer count
- **Time Complexity**: O(n)

#### 12. `freeList(Node *head)`
- **Purpose**: Free all allocated memory
- **Prevents**: Memory leaks

## Main Function Organization

The `demonstrate()` function tests all operations:
1. Create list with values: 10, 20, 30, 40, 50
2. Insert 5 at beginning
3. Insert 25 after node 20
4. Insert 15 before node 20
5. Delete node with value 25
6. Delete node with value 40
7. Display backward traversal
8. Free memory

## Sample Output

```
=== Doubly Linked List Operations ===

1. Inserting elements at the end: 10, 20, 30, 40, 50
Forward:  10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
Backward: 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL
Total nodes: 5

2. Inserting 5 at the beginning
Forward:  5 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
Total nodes: 6

3. Inserting 25 after node with value 20
Forward:  5 <-> 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 <-> NULL
Total nodes: 7

4. Inserting 15 before node with value 20
Forward:  5 <-> 10 <-> 15 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 <-> NULL
Total nodes: 8

5. Deleting node with value 25
Forward:  5 <-> 10 <-> 15 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
Backward: 50 <-> 40 <-> 30 <-> 20 <-> 15 <-> 10 <-> 5 <-> NULL
Total nodes: 7

6. Deleting node with value 40
Forward:  5 <-> 10 <-> 15 <-> 20 <-> 30 <-> 50 <-> NULL
Total nodes: 6

7. Backward traversal:
Backward: 50 <-> 30 <-> 20 <-> 15 <-> 10 <-> 5 <-> NULL

List freed successfully!
```

## Advantages of Doubly Linked List

1. **Bidirectional Traversal**: Can traverse forward and backward
2. **Efficient Deletion**: Can delete with just node pointer
3. **Flexible Insertion**: Insert before or after any node
4. **Reverse Operations**: Easier to implement reverse operations
5. **Sorted Insert**: Easier to maintain sorted order

## Disadvantages

1. **Extra Memory**: Requires additional prev pointer
2. **More Complex**: Operations are more complex than singly linked list
3. **Slower Initialization**: Takes more time to create nodes

## Comparison with Singly Linked List

| Operation | Singly LL | Doubly LL |
|-----------|-----------|-----------|
| Insert at beginning | O(1) | O(1) |
| Insert at end | O(n) | O(n) |
| Insert after node | O(1) | O(1) |
| Delete node | O(n)* | O(1)** |
| Backward traversal | O(n)* | O(n) |

*Need to find prev node
**Can delete directly with node pointer

## Compilation and Execution

```bash
gcc -o prog_4 prog_4.c
./prog_4
```

## Applications

- Deque (Double-ended queue) implementation
- Undo/Redo functionality
- Browser history (back/forward navigation)
- Two-way iterators
- LRU Cache implementation
