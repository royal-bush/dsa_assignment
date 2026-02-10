Program 7: Dijkstra's Algorithm - Shortest Path

Overview
This program implements Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a weighted, undirected graph. It uses a greedy approach to efficiently compute shortest paths.

Data Structures

Weighted Graph Structure
typedef struct {
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;
char vertexLabel[MAX_VERTICES];
} WeightedGraph;

adjMatrix: 2D array storing edge weights
numVertices: Number of vertices in the graph
vertexLabel: Labels for vertices (A, B, C, etc.)

Distance Information Structure
typedef struct {
int distance;
int parent;
} DistanceInfo;

distance: Shortest distance from the source
parent: Previous vertex in the shortest path

Functions Implemented

Graph Operations

1.initGraph(WeightedGraph *g, int vertices)
Purpose
Initialize a weighted graph

2.addEdge(WeightedGraph *g, int src, int dest, int weight)
Purpose
Add a weighted edge to the graph

Dijkstra's Algorithm

3.findMinDistanceVertex(int distance[], bool visited[], int numVertices) – HELPER
Purpose
Find the unvisited vertex with the minimum distance

4.dijkstra(WeightedGraph *g, int src, int distance[], int parent[]) – MAIN ALGORITHM
Purpose
Find the shortest paths from the source to all vertices

Path Display Functions

5.printDistances(WeightedGraph *g, int src, int distance[])
Purpose
Display the shortest distances from the source vertex

6.printPath(WeightedGraph *g, int parent[], int src, int dest)
Purpose
Reconstruct and print the path from source to destination

7.printAllPaths(WeightedGraph *g, int src, int distance[], int parent[])
Purpose
Display all shortest paths from the source

Utility Functions

8.displayMatrix(WeightedGraph *g)
Purpose
Display the weighted adjacency matrix

Algorithm Explanation

Dijkstra's Pseudocode
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

Sample Output

=== Dijkstra's Algorithm - Shortest Path ===

Adding edges to the graph:
A-B: 4, A-C: 2, B-C: 1, B-D: 5, C-D: 8
C-E: 10, D-E: 2, D-F: 6, E-F: 3

Weighted Adjacency Matrix:
A B C D E F
A: 0 4 2 INF 10 INF
B: 4 0 1 5 INF INF
C: 2 1 0 8 10 INF
...

=== Running Dijkstra's Algorithm ===

Shortest distances from vertex A:
Vertex Distance

A 0
B 3
C 2
D 8
E 10
F 13

Shortest paths from vertex A:
Destination Distance Path

B 3 A -> C -> B
C 2 A -> C
D 8 A -> C -> B -> D
E 10 A -> C -> B -> D -> E
F 13 A -> C -> B -> D -> E -> F

Compilation and Execution

gcc -o prog_7 prog_7.c
./prog_7
