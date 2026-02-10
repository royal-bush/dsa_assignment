# Program 7: Dijkstra's Algorithm - Shortest Path

## Overview
This program implements Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a weighted, undirected graph. It uses a greedy approach to efficiently compute shortest paths.

## Data Structures

### Weighted Graph Structure
```c
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    char vertexLabel[MAX_VERTICES];
} WeightedGraph;
```
- `adjMatrix`: 2D array storing edge weights
- `numVertices`: Number of vertices in graph
- `vertexLabel`: Labels for vertices (A, B, C, etc.)

### Distance Information Structure
```c
typedef struct {
    int distance;
    int parent;
} DistanceInfo;
```
- `distance`: Shortest distance from source
- `parent`: Previous vertex in shortest path

## Functions Implemented

### Graph Operations

#### 1. `initGraph(WeightedGraph *g, int vertices)`
- **Purpose**: Initialize weighted graph
- **Parameters**: Graph pointer, number of vertices
- **Initialization**: 
  - Self loops: 0
  - Other edges: INFINITY
  - Vertex labels: A, B, C, etc.

#### 2. `addEdge(WeightedGraph *g, int src, int dest, int weight)`
- **Purpose**: Add weighted edge to graph
- **Parameters**: Graph pointer, source, destination, weight
- **Note**: Creates undirected edges (bidirectional)
- **Validation**: Ensures positive weights

### Dijkstra's Algorithm

#### 3. `findMinDistanceVertex(int distance[], bool visited[], int numVertices)` - **HELPER**
- **Purpose**: Find unvisited vertex with minimum distance
- **Algorithm**: Linear search through all vertices
- **Time Complexity**: O(V)
- **Returns**: Index of vertex with minimum distance or -1

#### 4. `dijkstra(WeightedGraph *g, int src, int distance[], int parent[])` - **MAIN ALGORITHM**
- **Purpose**: Find shortest paths from source to all vertices
- **Algorithm**:
  1. Initialize distances to INFINITY except source (0)
  2. Mark all vertices as unvisited
  3. For each vertex (V-1 iterations):
     - Find unvisited vertex with minimum distance
     - Mark it as visited
     - Update distances of its unvisited neighbors:
       - If path through current vertex is shorter, update
       - Store parent for path reconstruction
- **Time Complexity**: O(V²)
  - O(V) iterations
  - Each iteration scans O(V) vertices plus O(V) edges
  - Can be O((V+E)logV) with min-heap
- **Space Complexity**: O(V²) for adjacency matrix
- **Greedy Approach**: Always processes closest unvisited vertex
- **Assumption**: No negative edge weights

### Path Display Functions

#### 5. `printDistances(WeightedGraph *g, int src, int distance[])`
- **Purpose**: Display shortest distances from source vertex
- **Output**: Formatted table of vertices and distances

#### 6. `printPath(WeightedGraph *g, int parent[], int src, int dest)`
- **Purpose**: Reconstruct and print path from source to destination
- **Algorithm**: Recursive backtracking through parent array
- **Base Case**: Reach source vertex
- **Handles**: No path (unreachable) case

#### 7. `printAllPaths(WeightedGraph *g, int src, int distance[], int parent[])`
- **Purpose**: Display all shortest paths from source
- **Output**: Table with destination, distance, and path
- **Format**: Shows path in readable form

### Utility Functions

#### 8. `displayMatrix(WeightedGraph *g)`
- **Purpose**: Display weighted adjacency matrix
- **Format**: Shows weights with labels

## Algorithm Explanation

### Dijkstra's Pseudocode
```
function Dijkstra(Graph, source):
    distance[source] = 0
    for each vertex v in Graph:
        if v ≠ source:
            distance[v] = INFINITY
    
    visited = empty set
    
    while visited ≠ all vertices:
        u = find unvisited vertex with min distance
        add u to visited
        
        for each neighbor v of u:
            if distance[u] + weight(u,v) < distance[v]:
                distance[v] = distance[u] + weight(u,v)
                parent[v] = u
```

### Key Concepts
1. **Greedy Choice**: Always process closest unvisited vertex
2. **Optimal Substructure**: Shortest path to v contains shortest path to intermediate vertices
3. **Relaxation**: Update distance if better path found
4. **Parent Tracking**: Reconstruct path using parent pointers

## Main Function Organization

The program demonstrates:
1. Create weighted graph with 6 vertices (A-F)
2. Add 9 weighted edges
3. Display adjacency matrix
4. Run Dijkstra from vertex A
   - Show distances from A
   - Show all shortest paths from A
5. Run Dijkstra from vertex B
   - Show distances from B
   - Show all shortest paths from B
6. Run Dijkstra from vertex D
   - Show distances from D
   - Show all shortest paths from D

## Sample Output

```
=== Dijkstra's Algorithm - Shortest Path ===

Adding edges to the graph:
A-B: 4, A-C: 2, B-C: 1, B-D: 5, C-D: 8
C-E: 10, D-E: 2, D-F: 6, E-F: 3

Weighted Adjacency Matrix:
    A  B  C  D  E  F
A:  0  4  2 INF 10 INF
B:  4  0  1  5 INF INF
C:  2  1  0  8 10 INF
...

=== Running Dijkstra's Algorithm ===

Shortest distances from vertex A:
Vertex   Distance
------   --------
A        0
B        3
C        2
D        8
E        10
F        13

Shortest paths from vertex A:
Destination  Distance  Path
-----------  --------  ----
B            3         A -> C -> B
C            2         A -> C
D            8         A -> C -> B -> D
E            10        A -> C -> B -> D -> E
F            13        A -> C -> B -> D -> E -> F
```

## Complexity Analysis

| Operation | Worst Case | With Min-Heap |
|-----------|-----------|---------------|
| Find min vertex | O(V²) | O(V log V) |
| Update distances | O(V) per iteration | O(log V) |
| Total Time | O(V²) | O((V+E) log V) |
| Space | O(V²) | O(V) |

## Requirements and Constraints

1. **No Negative Weights**: Algorithm fails with negative edge weights
2. **Non-Negative**: All weights must be ≥ 0
3. **Connected Graph**: Works with disconnected graphs (unreachable marked as INFINITY)
4. **Directed/Undirected**: Works with both (implementation uses undirected here)

## Advantages

1. Optimal solution guaranteed
2. Efficient greedy approach
3. Finds paths to all vertices in one run
4. Path reconstruction is simple

## Limitations

1. Cannot handle negative weights
2. O(V²) with simple implementation
3. Must process all vertices even if destination found
4. Requires non-negative weights

## Compilation and Execution

```bash
gcc -o prog_7 prog_7.c
./prog_7
```

## Applications

1. **GPS Navigation**: Find shortest routes
2. **Network Routing**: OSPF protocol
3. **Game AI**: Pathfinding for characters
4. **Social Networks**: Shortest connection path
5. **Robot Navigation**: Optimal path planning
6. **Network Flow**: Minimum cost paths
7. **Flight Path**: Shortest flight between cities

## Variations and Extensions

### Dijkstra's Variants
1. **With Min-Heap**: Better for sparse graphs
2. **With Fibonacci Heap**: O((V+E) log V) theoretical optimum
3. **One-to-One**: Stop when destination found
4. **A* Algorithm**: Add heuristic for faster convergence

### Related Algorithms
- **Bellman-Ford**: Handles negative weights
- **Floyd-Warshall**: All-pairs shortest paths
- **BFS**: Unweighted shortest path
- **A***: Heuristic-guided pathfinding

## Correctness Proof

The algorithm's correctness relies on:
1. When vertex u is selected for processing, distance[u] is optimal
2. All unvisited vertices at time of selection have ≥ distance[u]
3. Relaxation ensures no better path is overlooked
4. No negative weights guarantee monotonic distance increase
