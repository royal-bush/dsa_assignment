#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INFINITY INT_MAX

// Graph structure with weighted edges
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    char vertexLabel[MAX_VERTICES];
} WeightedGraph;

// Structure to store distance and parent information
typedef struct {
    int distance;
    int parent;
} DistanceInfo;

// Initialize weighted graph
void initGraph(WeightedGraph *g, int vertices) {
    g->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                g->adjMatrix[i][j] = 0;
            } else {
                g->adjMatrix[i][j] = INFINITY;
            }
        }
        g->vertexLabel[i] = 'A' + i;
    }
}

// Add weighted edge to the graph
void addEdge(WeightedGraph *g, int src, int dest, int weight) {
    if (src < g->numVertices && dest < g->numVertices && weight > 0) {
        g->adjMatrix[src][dest] = weight;
        g->adjMatrix[dest][src] = weight; // For undirected graph
    }
}

// Find the vertex with minimum distance that hasn't been visited
int findMinDistanceVertex(int distance[], bool visited[], int numVertices) {
    int minDistance = INFINITY;
    int minVertex = -1;
    
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && distance[i] < minDistance) {
            minDistance = distance[i];
            minVertex = i;
        }
    }
    
    return minVertex;
}

// Dijkstra's Algorithm to find shortest path from source to all vertices
void dijkstra(WeightedGraph *g, int src, int distance[], int parent[]) {
    bool visited[MAX_VERTICES] = {false};
    
    // Initialize distances and parent
    for (int i = 0; i < g->numVertices; i++) {
        distance[i] = INFINITY;
        parent[i] = -1;
    }
    
    // Distance to source is 0
    distance[src] = 0;
    
    // Process each vertex
    for (int count = 0; count < g->numVertices - 1; count++) {
        // Find unvisited vertex with minimum distance
        int u = findMinDistanceVertex(distance, visited, g->numVertices);
        
        if (u == -1) break;  // No more reachable vertices
        
        visited[u] = true;
        
        // Update distances of adjacent vertices
        for (int v = 0; v < g->numVertices; v++) {
            // Check if edge exists and v is not visited
            if (g->adjMatrix[u][v] != INFINITY && !visited[v]) {
                // If path through u is shorter
                if (distance[u] != INFINITY && 
                    distance[u] + g->adjMatrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + g->adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

// Print shortest distances from source
void printDistances(WeightedGraph *g, int src, int distance[]) {
    printf("\nShortest distances from vertex %c:\n", g->vertexLabel[src]);
    printf("Vertex   Distance\n");
    printf("------   --------\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        if (distance[i] == INFINITY) {
            printf("%c        INFINITY (unreachable)\n", g->vertexLabel[i]);
        } else {
            printf("%c        %d\n", g->vertexLabel[i], distance[i]);
        }
    }
}

// Print path from source to destination
void printPath(WeightedGraph *g, int parent[], int src, int dest) {
    if (dest == src) {
        printf("%c", g->vertexLabel[src]);
        return;
    }
    
    if (parent[dest] == -1) {
        printf("No path");
        return;
    }
    
    printPath(g, parent, src, parent[dest]);
    printf(" -> %c", g->vertexLabel[dest]);
}

// Print all shortest paths
void printAllPaths(WeightedGraph *g, int src, int distance[], int parent[]) {
    printf("\nShortest paths from vertex %c:\n", g->vertexLabel[src]);
    printf("Destination  Distance  Path\n");
    printf("-----------  --------  ----\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        if (i != src) {
            printf("%c            %d         ", g->vertexLabel[i], 
                   distance[i] == INFINITY ? -1 : distance[i]);
            
            if (distance[i] == INFINITY) {
                printf("No path");
            } else {
                printPath(g, parent, src, i);
            }
            printf("\n");
        }
    }
}

// Display adjacency matrix
void displayMatrix(WeightedGraph *g) {
    printf("\nWeighted Adjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("  %c", g->vertexLabel[i]);
    }
    printf("\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%c:", g->vertexLabel[i]);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == INFINITY) {
                printf("  INF");
            } else {
                printf("  %d", g->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Demonstration
void demonstrate() {
    printf("=== Dijkstra's Algorithm - Shortest Path ===\n\n");
    
    WeightedGraph g;
    initGraph(&g, 6);
    
    // Add weighted edges
    printf("Adding edges to the graph:\n");
    addEdge(&g, 0, 1, 4);   // A-B: 4
    addEdge(&g, 0, 2, 2);   // A-C: 2
    addEdge(&g, 1, 2, 1);   // B-C: 1
    addEdge(&g, 1, 3, 5);   // B-D: 5
    addEdge(&g, 2, 3, 8);   // C-D: 8
    addEdge(&g, 2, 4, 10);  // C-E: 10
    addEdge(&g, 3, 4, 2);   // D-E: 2
    addEdge(&g, 3, 5, 6);   // D-F: 6
    addEdge(&g, 4, 5, 3);   // E-F: 3
    
    printf("A-B: 4, A-C: 2, B-C: 1, B-D: 5, C-D: 8\n");
    printf("C-E: 10, D-E: 2, D-F: 6, E-F: 3\n");
    
    // Display graph matrix
    displayMatrix(&g);
    
    // Test Dijkstra's algorithm from different source vertices
    int distance[MAX_VERTICES];
    int parent[MAX_VERTICES];
    
    // From vertex A (0)
    printf("\n");
    printf("=== Running Dijkstra's Algorithm ===\n");
    dijkstra(&g, 0, distance, parent);
    
    printDistances(&g, 0, distance);
    printAllPaths(&g, 0, distance, parent);
    
    // From vertex B (1)
    printf("\n");
    dijkstra(&g, 1, distance, parent);
    printDistances(&g, 1, distance);
    printAllPaths(&g, 1, distance, parent);
    
    // From vertex D (3)
    printf("\n");
    dijkstra(&g, 3, distance, parent);
    printDistances(&g, 3, distance);
    printAllPaths(&g, 3, distance, parent);
}

int main() {
    demonstrate();
    return 0;
}
