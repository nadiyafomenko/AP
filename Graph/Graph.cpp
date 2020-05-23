#include <stdio.h>
#include <stdlib.h>

#define GRAPH_VERTEX 9

#include "graph.hpp"
#include "dijkstra.hpp"

void findBiggestPathes(Graph* graph);

int main() {
    Graph* graph = createGraph();

    addEdge(graph, 0, 1, 40);
    addEdge(graph, 0, 7, 100);
    addEdge(graph, 1, 2, 80);
    addEdge(graph, 1, 7, 110);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 2, 8, 10);
    addEdge(graph, 2, 5, 40);
    addEdge(graph, 3, 4, 90);
    addEdge(graph, 3, 5, 456);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);

    printGraph(graph);
    findBiggestPathes(graph);
}

void findBiggestPathes(Graph* graph) {
    ListNode* minPath = dijkstra(graph, 0);
    puts("\nTable of the longest pathes from the shortest:\n");
    for (int i = 0; i < GRAPH_VERTEX; i++) {
        ListNode* node = dijkstra(graph, i);
        node->from = i;
        printf("Max weight - %d on path (%d, %d)\n", node->weight, node->from, node->to);
        if (node->weight < minPath->weight) minPath = node;
    }
    printf("\n\nResult:\t");
    printf("Shortest path is on the way (%d,%d) and its weight - %d\n\n", minPath->from, minPath->to, minPath->weight);
}
