#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

// Definition of the structure for the vertix.
typedef struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
} AdjListNode;

// Definition of the structure for the adjacency list.
typedef struct AdjList
{
    AdjListNode *head;
} AdjList;

// Definition of the structure for the graph
typedef struct Graph
{
    int numVertices;
    AdjList *array;
} Graph;

Graph *create_graph(int numVertices);

void add_edge(Graph *graph, int src, int dest);

void print_graph(Graph *graph);

void delete_graph(Graph *graph);

bool node_exists(AdjListNode *head, int dest);

#endif