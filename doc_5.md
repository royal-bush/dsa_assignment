Program 5: Undirected Graph – Adjacency Matrix Implementation

Overview
This program implements an undirected graph using an adjacency matrix representation. It demonstrates graph operations including construction, traversal using BFS and DFS, edge manipulation, and connectivity analysis.

Data Structures

Queue Structure for BFS
typedef struct {
int items[MAX_QUEUE];
int front;
int rear;
} Queue;

The queue is used for Breadth First Search.
Front stores the index of the front element.
Rear stores the index of the rear element.

Graph Structure
typedef struct {
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;
char vertexLabel[MAX_VERTICES];
} Graph;

The adjacency matrix is a two dimensional array where adjMatrix[i][j] is 1 if an edge exists between vertices i and j.
numVertices stores the total number of vertices in the graph.
vertexLabel stores labels such as A, B, C, etc.

Functions Implemented

Queue Operations

1.initQueue
Initializes an empty queue

2.isQueueEmpty
Checks whether the queue is empty

3.enqueue
Adds an element to the rear of the queue

4.dequeue
Removes an element from the front of the queue

Graph Creation and Modification

5.initGraph(Graph *g, int vertices)
Purpose
Initialize the graph with a given number of vertices

6.addEdge(Graph *g, int src, int dest)
Purpose
Add an undirected edge between two vertices

7.removeEdge(Graph *g, int src, int dest)
Purpose
Remove the edge between two vertices

8.hasEdge(Graph *g, int src, int dest)
Purpose
Check whether an edge exists between two vertices

Graph Analysis

9.getNeighbors(Graph *g, int vertex, int *neighbors, int *count)
Purpose
Retrieve all adjacent vertices of a given vertex

10.getDegree(Graph *g, int vertex)
Purpose
Calculate the degree of a vertex

11.displayMatrix(Graph *g)
Purpose
Display the adjacency matrix in a formatted manner

Traversal Algorithms

12.bfs(Graph *g, int startVertex)
Purpose
Perform Breadth First Search traversal

13.dfsHelper(Graph *g, int vertex, bool visited[])
Purpose
Recursive helper function for Depth First Search

14.dfs(Graph *g, int startVertex)
Purpose
Perform Depth First Search traversal

Graph Analysis Operations

16.findConnectedComponents(Graph *g)
Purpose
Identify all connected components in the graph

17.isConnected(Graph *g)
Purpose
Check whether the entire graph is connected

18.displayGraphInfo(Graph *g)
Purpose
Display detailed information about the graph

Sample Output

Undirected Graph – Adjacency Matrix Implementation

Adding edges to the graph
Edge A-B added
Edge A-D added
Edge B-C added
Edge C-D added
Edge D-E added

Adjacency Matrix
A B C D E
A 0 1 0 1 0
B 1 0 1 0 0
C 0 1 0 1 0
D 1 0 1 0 1
E 0 0 0 1 0

Graph Information
Number of vertices: 5
Number of edges: 5

Degree of each vertex
Vertex A: 2
Vertex B: 2
Vertex C: 2
Vertex D: 3
Vertex E: 1

Graph connected: Yes

Traversal Algorithms

BFS Traversal
A B D C E

DFS Traversal
A B C D E

Connected Components
Component 1
A B C D E

Edge Operations

Edge A-B exists: Yes
Edge A-C exists: No

Removing edge A-D

Graph after removing edge A-D
A B C D E
A 0 1 0 0 0
B 1 0 1 0 0
C 0 1 0 1 0
D 0 0 1 0 1
E 0 0 0 1 0

BFS after removing edge A-D
A B C D E

Connected Components after removing edge A-D
Component 1
A B C D E

Compilation and Execution

gcc -o prog_5 prog_5.c
./prog_5
