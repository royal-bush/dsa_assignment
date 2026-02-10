# Program 5: Undirected Graph - Adjacency Matrix Implementation

## Overview
This program implements an undirected graph using an adjacency matrix representation. It demonstrates graph operations including construction, traversal using BFS and DFS, edge manipulation, and connectivity analysis.

## Data Structures

### Queue Structure (for BFS)
```c
typedef struct {
    int items[MAX_QUEUE];
    int front;
    int rear;
} Queue;
```
- Used for Breadth-First Search
- `front`: Index of front element
- `rear`: Index of rear element

### Graph Structure
```c
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    char vertexLabel[MAX_VERTICES];
} Graph;
```
- `adjMatrix`: 2D array where adjMatrix[i][j] = 1 if edge exists between vertices i and j
- `numVertices`: Number of vertices in graph
- `vertexLabel`: Labels for vertices (A, B, C, etc.)

## Functions Implemented

### Queue Operations
- **`initQueue()`**: Initialize empty queue
- **`isQueueEmpty()`**: Check if queue is empty
- **`enqueue()`**: Add element to queue rear
- **`dequeue()`**: Remove element from queue front

### Graph Creation and Modification

#### 1. `initGraph(Graph *g, int vertices)`
- **Purpose**: Initialize graph with given number of vertices
- **Parameters**: Graph pointer, number of vertices
- **Initializes**: Adjacency matrix with all 0s, vertex labels A-Z

#### 2. `addEdge(Graph *g, int src, int dest)`
- **Purpose**: Add undirected edge between two vertices
- **Parameters**: Graph pointer, source vertex, destination vertex
- **Method**: Set adjMatrix[src][dest] = 1 and adjMatrix[dest][src] = 1
- **Time Complexity**: O(1)

#### 3. `removeEdge(Graph *g, int src, int dest)`
- **Purpose**: Remove edge between two vertices
- **Time Complexity**: O(1)

#### 4. `hasEdge(Graph *g, int src, int dest)`
- **Purpose**: Check if edge exists between two vertices
- **Returns**: true if edge exists, false otherwise
- **Time Complexity**: O(1)

### Graph Analysis

#### 5. `getNeighbors(Graph *g, int vertex, int *neighbors, int *count)`
- **Purpose**: Get all adjacent vertices of a given vertex
- **Parameters**: Graph pointer, vertex, output array, output count
- **Returns**: Array of neighbors and their count

#### 6. `getDegree(Graph *g, int vertex)`
- **Purpose**: Get degree (number of neighbors) of a vertex
- **Returns**: Integer degree value
- **Time Complexity**: O(V)

#### 7. `displayMatrix(Graph *g)`
- **Purpose**: Display adjacency matrix in formatted way
- **Output**: Matrix with vertex labels on axes

### Traversal Algorithms

#### 8. `bfs(Graph *g, int startVertex)` - **MAIN ALGORITHM**
- **Purpose**: Breadth-First Search traversal
- **Algorithm**:
  1. Create queue and mark start vertex visited
  2. Enqueue start vertex
  3. While queue not empty:
     - Dequeue vertex and print it
     - Find all unvisited neighbors
     - Mark them visited and enqueue them
- **Time Complexity**: O(V + E), where V = vertices, E = edges
- **Space Complexity**: O(V) for queue
- **Output**: BFS order of vertices

#### 9. `dfsHelper(Graph *g, int vertex, bool visited[])`
- **Purpose**: Recursive helper for DFS
- **Algorithm**:
  1. Mark current vertex visited and print it
  2. For each unvisited neighbor:
     - Recursively call dfsHelper
- **Time Complexity**: O(V + E)

#### 10. `dfs(Graph *g, int startVertex)` - **MAIN ALGORITHM**
- **Purpose**: Depth-First Search traversal
- **Algorithm**: Uses recursive dfsHelper
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V) for recursion stack

### Graph Analysis Operations

#### 11. `findConnectedComponents(Graph *g)`
- **Purpose**: Find all connected components in graph
- **Algorithm**:
  1. Maintain visited array
  2. For each unvisited vertex:
     - Perform DFS
     - Print all vertices in this component
- **Output**: Separate connected components

#### 12. `isConnected(Graph *g)`
- **Purpose**: Check if entire graph is connected
- **Algorithm**: Perform DFS from vertex 0 and check if all vertices are visited
- **Returns**: true if all vertices reachable, false otherwise

#### 13. `displayGraphInfo(Graph *g)`
- **Purpose**: Display comprehensive graph statistics
- **Includes**: 
  - Number of vertices
  - Number of edges
  - Degree of each vertex
  - Connectivity status

## Main Function Organization

The program demonstrates:
1. Create graph with 5 vertices (A, B, C, D, E)
2. Add 5 edges: A-B, A-D, B-C, C-D, D-E
3. Display adjacency matrix
4. Show graph information
5. Perform BFS traversal from A
6. Perform DFS traversal from A
7. Find connected components
8. Test edge operations
9. Remove edge and show changes
10. Update traversals after modification

## Sample Output

```
=== Undirected Graph - Adjacency Matrix Implementation ===

Adding edges to the graph:
Edge A-B added
Edge A-D added
Edge B-C added
Edge C-D added
Edge D-E added

Adjacency Matrix:
   A B C D E 
A: 0 1 0 1 0 
B: 1 0 1 0 0 
C: 0 1 0 1 0 
D: 1 0 1 0 1 
E: 0 0 0 1 0 

=== Graph Information ===
Number of vertices: 5
Number of edges: 5

Degree of each vertex:
Vertex A: 2
Vertex B: 2
Vertex C: 2
Vertex D: 3
Vertex E: 1
Is graph connected: Yes

=== Traversal Algorithms ===

BFS Traversal: A B D C E 
DFS Traversal: A B C D E 

Connected Components:
Component 1: A B C D E 

=== Edge Operations ===
Edge A-B exists: Yes
Edge A-C exists: No

Removing edge A-D...

Graph after removing edge A-D:
   A B C D E 
A: 0 1 0 0 0 
B: 1 0 1 0 0 
C: 0 1 0 1 0 
D: 0 0 1 0 1 
E: 0 0 0 1 0 

BFS after removing edge A-D: A B C D E 
Connected Components after removing edge A-D:
Component 1: A B C D E 
```

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Initialize | O(V²) | O(V²) |
| Add Edge | O(1) | - |
| Remove Edge | O(1) | - |
| Check Edge | O(1) | - |
| BFS | O(V+E) | O(V) |
| DFS | O(V+E) | O(V) |
| Get Neighbors | O(V) | O(V) |
| Get Degree | O(V) | O(V) |

## Adjacency Matrix Properties

- **Symmetric**: adjMatrix[i][j] = adjMatrix[j][i] for undirected graph
- **Sparse vs Dense**: 
  - Efficient for dense graphs (many edges)
  - Less efficient for sparse graphs (few edges)
- **Quick Edge Lookup**: O(1) edge existence check
- **High Memory**: O(V²) regardless of edge count

## Compilation and Execution

```bash
gcc -o prog_5 prog_5.c
./prog_5
```

## Applications

- Social Network Analysis
- Web Page Linking
- Route Planning
- Game Maps
- Network Routing
- Relation Mapping
- Reachability Analysis

## Alternative Approach: Adjacency List

Can be more efficient for sparse graphs with O(V+E) space instead of O(V²).
