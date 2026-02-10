#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
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
}

// Function to display linked list (forward traversal)
void displayForward(Node *head) {
    printf("Forward:  ");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Recursive function to traverse in reverse
void reverseTraversalRecursive(Node *head) {
    if (head == NULL) {
        return;
    }
    
    // First recursively call for the rest of the list
    reverseTraversalRecursive(head->next);
    
    // Print the data as we return from recursion
    printf("%d ", head->data);
}

// Function to display linked list in reverse using recursion
void displayReverse(Node *head) {
    printf("Reverse:  ");
    reverseTraversalRecursive(head);
    printf("\n");
}

// Function to reverse the linked list (using iteration)
// This creates a new reversed structure without modifying original
void reverseIterative(Node *head) {
    if (head == NULL) {
        printf("Reverse:  (empty list)\n");
        return;
    }
    
    printf("Reverse:  ");
    
    // Count nodes first
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // Access nodes from end
    for (int i = count - 1; i >= 0; i--) {
        temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
}

// Function to find the length of linked list
int getLength(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to get the Nth node from beginning (for reverse traversal)
Node* getNthNode(Node *head, int n) {
    Node *current = head;
    for (int i = 0; i < n && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

// Alternative reverse traversal using position-based access
void reverseTraversalByPosition(Node *head) {
    int length = getLength(head);
    printf("Reverse:  ");
    
    for (int i = length - 1; i >= 0; i--) {
        Node *node = getNthNode(head, i);
        if (node != NULL) {
            printf("%d ", node->data);
        }
    }
    printf("\n");
}

// Function to free the linked list
void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    printf("=== Linked List - Reverse Traversal ===\n\n");
    
    Node *head = NULL;
    
    // Insert elements into the list
    printf("Inserting elements: 10, 20, 30, 40, 50\n\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // Display forward
    displayForward(head);
    
    // Display reverse using recursion
    printf("\nMethod 1 - Recursive Traversal:\n");
    displayReverse(head);
    
    // Display reverse using iteration
    printf("\nMethod 2 - Iterative Traversal (Position-based):\n");
    reverseTraversalByPosition(head);
    
    // Display reverse using iterative method
    printf("\nMethod 3 - Node-counting Iterative Traversal:\n");
    reverseIterative(head);
    
    // Additional operations
    printf("\n=== Additional Operations ===\n");
    printf("Length of list: %d\n", getLength(head));
    
    Node *thirdNode = getNthNode(head, 2);
    if (thirdNode != NULL) {
        printf("Third node value: %d\n", thirdNode->data);
    }
    
    // Free memory
    freeList(head);
    printf("\nList freed successfully!\n");
    
    return 0;
}
