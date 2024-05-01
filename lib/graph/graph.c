#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "./../list/list.h"

#define FloatMax 3.40282e+38F

Graph *graph_create(int size){
    Graph *graph = malloc(sizeof(Graph));
    graph->size = size;
    graph->nodes = malloc(size*sizeof(List));

    for(int i = 0; i < size; i++){
       graph->nodes[i] = list_create();
    }

    return graph;
}

void graph_destroy(Graph *graph){
    for (int i = 0; i < graph->size; i++){
        list_destroy(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}

void graph_add_edge(Graph *graph, int source, int target, float weight){
    GraphNode *graphnode = malloc(sizeof(GraphNode));
    
    graphnode->node = target;
    graphnode->weight = weight;
 
    list_append(graph->nodes[source], graphnode);
}

float graph_dijkstra(Graph *graph, int source, int target){
    float distances[graph->size];
    int visited[graph->size];
    // add checking if table is not null, source and target are valid numbers
    for(int i = 0; i < graph->size; i++){
        distances[i] = FloatMax;
        visited[i] = 0;
    }
    
    distances[source] = 0;
    visited[source] = 1;

    int currentnode = source;
    int shortestpathindex = 0;

    while(shortestpathindex != -1){
        // update the table of distance
        List *currentnodelist = graph->nodes[currentnode];

        for(int i = 0; i < list_size(currentnodelist); i++){
            GraphNode *currentnearbynode = list_get(currentnodelist, i);
            int index = currentnearbynode->node;
            
            float total_distance = distances[currentnode] + currentnearbynode->weight;

            if(visited[index] == 0 && total_distance < distances[index]){
                distances[index] = total_distance;
            }
        }

        // find the shortest path from the current node to all the possible nodes
        // to set the next currentnode
        float shortestpath = FloatMax;
        // shortestpath is to used to take the minimum distance from every node in the graph
        shortestpathindex = -1;

        for(int i = 0; i < graph->size; i++){
            if(visited[i] == 0 && distances[i] < shortestpath){
                shortestpath = distances[i];
                shortestpathindex = i;
            }
        }
        
        //Remove the currentnode from the unvisited nodes and update the currentnode
        if(shortestpathindex >= 0){
            visited[shortestpathindex] = 1;
            currentnode = shortestpathindex;
        }
    }

    return distances[target];
}