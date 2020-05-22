#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_VERTEX 7

typedef struct {
    int from;
    int to;
    int pathWeight;
} MinPath;

typedef struct {
    int pos = 0;
    MinPath* head;
} BiggestPathes;

#include "graph.hpp"
#include "dijkstra.hpp"

int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);

    printGraph(graph);
    BiggestPathes* biggestPathes = (BiggestPathes*)malloc(sizeof(BiggestPathes));
    dijkstra(biggestPathes, graph, 0);
    //dijkstra(biggestPathes, graph, 1);

}


