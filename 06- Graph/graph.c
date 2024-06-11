#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// LET'S BEGIN WITH SOME HELPER FUNCTIONs

// Function to create a new adjacecy list node.
AdjListNode *new_adj_list_node(int dest)
{
    AdjListNode *new_node = (AdjListNode *)malloc(sizeof(AdjListNode));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// Function to check if a node already exists in the adjacency list.
bool node_exists(AdjListNode *head, int dest)
{
    AdjListNode *current = head;
    while (current)
    {
        if (current->dest == dest)
            return true;
        current = current->next;
    }
    return false;
}

// NOW, LET"S UTILIZE OUR HELPERS & IMPLEMENT OUR MAIN FUNCTIONs

// Function to create a graph with specific number of vertices.
Graph *create_graph(int num_vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = num_vertices;
    graph->array = (AdjList *)malloc(num_vertices * sizeof(AdjList));
    for (int i = 0; i < num_vertices; i++)
        graph->array->head = NULL;
    return graph;
}

// Function to add edge.
void add_edge(Graph *graph, int src, int dest)
{
    // Check if the edge is already exist.
    if (node_exists(graph->array[src].head, dest))
        return;
    AdjListNode *new_node = new_adj_list_node(dest);
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    // Since the graph is undirected, add an edge from dest to src.
    new_node = new_adj_list_node(src);
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}

// Function to print our graph.
void print_graph(Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        AdjListNode *current_node = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (current_node)
        {
            printf("-> %d", current_node->dest);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

// And final function to delete the graph and free the memory.
void delete_graph(Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        AdjListNode *current_node = graph->array[v].head;
        while (current_node)
        {
            AdjListNode *tmp = current_node;
            current_node = current_node->next;
            free(tmp);
        }
    }
    free(graph->array);
    free(graph);
}