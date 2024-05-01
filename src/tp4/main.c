#include <stdio.h>

#include "/Users/antoine/Desktop/Cours/STD/std2024/lib/list/list.h"
#include "/Users/antoine/Desktop/Cours/STD/std2024/lib/graph/graph.h"

int main()
{
    Graph* graph = graph_create(5);
    graph_add_edge(graph, 0, 1, 5);
    graph_add_edge(graph, 0, 2, 20);
    graph_add_edge(graph, 0, 3, 25);
    graph_add_edge(graph, 0, 4, 50);
    graph_add_edge(graph, 1, 2, 10);
    graph_add_edge(graph, 1, 3, 30);
    graph_add_edge(graph, 2, 3, 10);
    graph_add_edge(graph, 2, 4, 20);
    graph_add_edge(graph, 3, 4, 20);
    graph_dijkstra(graph, 0, 4);
    graph_destroy(graph);
}
