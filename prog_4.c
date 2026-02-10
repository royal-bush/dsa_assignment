#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node *prev;  // Pointer to previous node
    struct Node *next;  // Pointer to next node
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to insert a node after a given node
void insertAfter(Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node is NULL!\n");
        return;
    }
    
    Node *newNode = createNode(data);
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
}

// Function to insert a node before a given node
void insertBefore(Node **head, Node *nextNode, int data) {
    if (nextNode == NULL) {
        printf("Next node is NULL!\n");
        return;
    }
    
    Node *newNode = createNode(data);
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    
    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        *head = newNode;
    }
    
    nextNode->prev = newNode;
}

// Function to delete a node
void deleteNode(Node **head, Node *nodeToDelete) {
    if (nodeToDelete == NULL) {
        printf("Node to delete is NULL!\n");
        return;
    }
    
    // If node to delete is head
    if (nodeToDelete == *head) {
        *head = nodeToDelete->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        // Update previous node's next pointer
        if (nodeToDelete->prev != NULL) {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
        
        // Update next node's previous pointer
        if (nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
    }
    
    free(nodeToDelete);
}

// Function to delete node with specific value
void deleteByValue(Node **head, int value) {
    Node *current = *head;
    
    while (current != NULL) {
        if (current->data == value) {
            Node *temp = current;
            current = current->next;
            deleteNode(head, temp);
        } else {
            current = current->next;
        }
    }
}

// Function to find a node by value
Node* findNode(Node *head, int value) {
    Node *current = head;
    
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

// Function to display list in forward direction
void displayForward(Node *head) {
    printf("Forward:  ");
    Node *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display list in backward direction
void displayBackward(Node *head) {
    if (head == NULL) {
        printf("Backward: (empty list)\n");
        return;
    }
    
    // Find the last node
    Node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    printf("Backward: ");
    Node *current = last;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to get the count of nodes
int getCount(Node *head) {
    int count = 0;
    Node *current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Function to free the entire list
void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Demonstration function
void demonstrate() {
    Node *head = NULL;
    
    printf("=== Doubly Linked List Operations ===\n\n");
    
    // Insert elements
    printf("1. Inserting elements at the end: 10, 20, 30, 40, 50\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    displayForward(head);
    displayBackward(head);
    printf("Total nodes: %d\n\n", getCount(head));
    
    // Insert at beginning
    printf("2. Inserting 5 at the beginning\n");
    insertAtBeginning(&head, 5);
    displayForward(head);
    printf("Total nodes: %d\n\n", getCount(head));
    
    // Find a node and insert after it
    printf("3. Inserting 25 after node with value 20\n");
    Node *node20 = findNode(head, 20);
    if (node20 != NULL) {
        insertAfter(node20, 25);
        displayForward(head);
        printf("Total nodes: %d\n\n", getCount(head));
    }
    
    // Insert before a node
    printf("4. Inserting 15 before node with value 20\n");
    Node *node20_2 = findNode(head, 20);
    if (node20_2 != NULL) {
        insertBefore(&head, node20_2, 15);
        displayForward(head);
        printf("Total nodes: %d\n\n", getCount(head));
    }
    
    // Delete a node
    printf("5. Deleting node with value 25\n");
    deleteByValue(&head, 25);
    displayForward(head);
    displayBackward(head);
    printf("Total nodes: %d\n\n", getCount(head));
    
    // Delete multiple nodes
    printf("6. Deleting node with value 40\n");
    deleteByValue(&head, 40);
    displayForward(head);
    printf("Total nodes: %d\n\n", getCount(head));
    
    // Backward display
    printf("7. Backward traversal:\n");
    displayBackward(head);
    
    // Free memory
    freeList(head);
    printf("\nList freed successfully!\n");
}

int main() {
    demonstrate();
    return 0;
}
