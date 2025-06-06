#ifndef GRAPH_H
#define GRAPH_H

#include "./../list/list.h"

typedef struct graph
{
    int size;
    List **nodes;
} Graph;

typedef struct graphnode
{
    int node;
    float weight;
}GraphNode;

Graph *graph_create(int size);
void graph_destroy(Graph *graph);
void graph_add_edge(Graph *graph, int node1, int node2, float weight);
float graph_dijkstra(Graph *graph, int node1, int node2);

#endif