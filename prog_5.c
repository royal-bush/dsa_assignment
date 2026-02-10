#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define MAX_QUEUE 100

// Queue structure for BFS
typedef struct {
    int items[MAX_QUEUE];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
bool isQueueEmpty(Queue *q) {
    return q->front > q->rear;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (q->rear < MAX_QUEUE - 1) {
        q->items[++q->rear] = value;
    }
}

// Dequeue operation
int dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        return q->items[q->front++];
    }
    return -1;
}

// Graph structure using adjacency matrix
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    char vertexLabel[MAX_VERTICES]; // For vertex labels
} Graph;

// Initialize graph
void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    
    // Initialize adjacency matrix with 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
        // Default labels are A, B, C, etc.
        g->vertexLabel[i] = 'A' + i;
    }
}

// Add edge to undirected graph
void addEdge(Graph *g, int src, int dest) {
    if (src < g->numVertices && dest < g->numVertices) {
        g->adjMatrix[src][dest] = 1;
        g->adjMatrix[dest][src] = 1; // For undirected graph
    }
}

// Remove edge from graph
void removeEdge(Graph *g, int src, int dest) {
    if (src < g->numVertices && dest < g->numVertices) {
        g->adjMatrix[src][dest] = 0;
        g->adjMatrix[dest][src] = 0;
    }
}

// Check if edge exists
bool hasEdge(Graph *g, int src, int dest) {
    if (src < g->numVertices && dest < g->numVertices) {
        return g->adjMatrix[src][dest] == 1;
    }
    return false;
}

// Get all neighbors of a vertex
void getNeighbors(Graph *g, int vertex, int *neighbors, int *count) {
    *count = 0;
    if (vertex < g->numVertices) {
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[vertex][i] == 1) {
                neighbors[(*count)++] = i;
            }
        }
    }
}

// Get degree of a vertex
int getDegree(Graph *g, int vertex) {
    int neighbors[MAX_VERTICES];
    int count;
    getNeighbors(g, vertex, neighbors, &count);
    return count;
}

// Display adjacency matrix
void displayMatrix(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%c ", g->vertexLabel[i]);
    }
    printf("\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%c: ", g->vertexLabel[i]);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Breadth-First Search (BFS)
void bfs(Graph *g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);
    
    visited[startVertex] = true;
    enqueue(&q, startVertex);
    
    printf("BFS Traversal: ");
    
    while (!isQueueEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%c ", g->vertexLabel[vertex]);
        
        // Get neighbors of current vertex
        int neighbors[MAX_VERTICES];
        int count;
        getNeighbors(g, vertex, neighbors, &count);
        
        // Enqueue unvisited neighbors
        for (int i = 0; i < count; i++) {
            int neighbor = neighbors[i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(&q, neighbor);
            }
        }
    }
    printf("\n");
}

// DFS Helper function (recursive)
void dfsHelper(Graph *g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%c ", g->vertexLabel[vertex]);
    
    // Visit all adjacent vertices
    int neighbors[MAX_VERTICES];
    int count;
    getNeighbors(g, vertex, neighbors, &count);
    
    for (int i = 0; i < count; i++) {
        int neighbor = neighbors[i];
        if (!visited[neighbor]) {
            dfsHelper(g, neighbor, visited);
        }
    }
}

// Depth-First Search (DFS)
void dfs(Graph *g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    printf("DFS Traversal: ");
    dfsHelper(g, startVertex, visited);
    printf("\n");
}

// Find connected components
void findConnectedComponents(Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    int componentNum = 0;
    
    printf("\nConnected Components:\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            componentNum++;
            printf("Component %d: ", componentNum);
            dfsHelper(g, i, visited);
            printf("\n");
        }
    }
}

// Check if graph is connected
bool isConnected(Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    dfsHelper(g, 0, visited);
    
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

// Display graph information
void displayGraphInfo(Graph *g) {
    printf("\n=== Graph Information ===\n");
    printf("Number of vertices: %d\n", g->numVertices);
    
    int edgeCount = 0;
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = i + 1; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }
    printf("Number of edges: %d\n", edgeCount);
    
    printf("\nDegree of each vertex:\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertex %c: %d\n", g->vertexLabel[i], getDegree(g, i));
    }
    
    printf("Is graph connected: %s\n", isConnected(g) ? "Yes" : "No");
}

int main() {
    printf("=== Undirected Graph - Adjacency Matrix Implementation ===\n\n");
    
    // Create a graph with 5 vertices (0-4)
    Graph g;
    initGraph(&g, 5);
    
    // Add edges
    printf("Adding edges to the graph:\n");
    addEdge(&g, 0, 1);  // A-B
    addEdge(&g, 0, 3);  // A-D
    addEdge(&g, 1, 2);  // B-C
    addEdge(&g, 2, 3);  // C-D
    addEdge(&g, 3, 4);  // D-E
    
    printf("Edge A-B added\n");
    printf("Edge A-D added\n");
    printf("Edge B-C added\n");
    printf("Edge C-D added\n");
    printf("Edge D-E added\n");
    
    // Display adjacency matrix
    displayMatrix(&g);
    
    // Display graph information
    displayGraphInfo(&g);
    
    // BFS traversal starting from vertex 0 (A)
    printf("\n=== Traversal Algorithms ===\n\n");
    bfs(&g, 0);
    
    // DFS traversal starting from vertex 0 (A)
    dfs(&g, 0);
    
    // Find connected components
    findConnectedComponents(&g);
    
    // Test edge operations
    printf("\n=== Edge Operations ===\n");
    printf("Edge A-B exists: %s\n", hasEdge(&g, 0, 1) ? "Yes" : "No");
    printf("Edge A-C exists: %s\n", hasEdge(&g, 0, 2) ? "Yes" : "No");
    
    // Remove an edge
    printf("\nRemoving edge A-D...\n");
    removeEdge(&g, 0, 3);
    
    printf("\nGraph after removing edge A-D:\n");
    displayMatrix(&g);
    
    printf("\nBFS after removing edge A-D: ");
    bfs(&g, 0);
    
    printf("\nConnected Components after removing edge A-D:\n");
    findConnectedComponents(&g);
    
    return 0;
}
