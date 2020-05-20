#include <stdio.h>
#include <stdlib.h>

#define GRAPH_VERTEX 5

typedef struct ListNode {
    int destinationVertex;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
} List;

typedef struct {
    List* array;
} Graph;

Graph* createGraph();
void addEdge(Graph* graph, int from, int to);
ListNode* newListNode(int to);
void printGraph(Graph* graph);


int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 1, 0);

    printGraph(graph);

    return 0;
}

Graph* createGraph() {

    Graph* graph;
    graph = (Graph*)malloc(sizeof(Graph));

    graph->array = (List*)malloc(GRAPH_VERTEX * sizeof(List));
    for (int i = 0; i < GRAPH_VERTEX; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int from, int to) {
    ListNode* newNode = newListNode(to);
    newNode->next = graph->array[from].head;

    graph->array[from].head = newNode;

    newNode = newListNode(from);
    newNode->next = graph->array[to].head;
    graph->array[to].head = newNode;
}

ListNode* newListNode(int to) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->destinationVertex = to;
    newNode->next = NULL;
    return newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < GRAPH_VERTEX; i++) {
        ListNode* list = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (list)
        {
            printf("-> %d", list->destinationVertex);
            list = list->next;
        }
        printf("\n");
    }
}