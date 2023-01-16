#ifndef GRAPH_H
#define GRAPH_H

#define INFINITY 100000

typedef struct Edge *p_edge; //for struct Node

//**********************STRUCTURIES*********************//

//-------Node-------//
typedef struct Node {
    int nodeId;
    p_edge edges;
    struct Node *next;
} node, *p_node;

//-------Dijkstra-------//
typedef struct Dijkstra {
    p_node node;
    int weight;
    int tag;
    struct Dijkstra *next;
} dijkstra, *p_dijkstra;

//-------Edge-------//
typedef struct Edge {
    int weight;
    p_node dest;
    struct Edge *next;
} edge, *p_edge;



//**********************GRPAH'S FUNCTIONS DECLARATION*********************//
p_node createGraph(int nodes);

void addNode(p_node *head, int src);

p_node getNode(int id, p_node *head);

void addEdge(p_node temp, int dest, int w, p_node *head);

void addNode_B(p_node *head);

void freeEdges(p_node p);

void deleteNode(p_node *head);

void deleteGraph(p_node *head);

void printGraph(p_node head);

void deleteEdge(p_node *head, int nodeId);

void TSP(p_node head);


//**********************DIJKSTRA'S FUNCTIONS DECLARATION*********************//
p_dijkstra createDijkstra(p_node start, int src);

p_dijkstra getPointerDijkstra(p_dijkstra head, int id);

void deleteDijkstra(p_dijkstra dijkstra);

p_dijkstra minVertical(p_dijkstra head);

int shortestPath(p_node head, int src, int dest);


//**********************TSP'S FUNCTIONS DECLARATION*********************//
void TSP(p_node head);

#endif //GRAPH_H
