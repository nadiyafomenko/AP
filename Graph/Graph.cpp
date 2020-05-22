#include <stdio.h>
#include <stdlib.h>

#define GRAPH_VERTEX 7

typedef struct ListNode {
    int weight;
    int to;
    int from;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
} List;

typedef struct {
    List* array;
} Graph;

Graph* createGraph();
void addEdge(Graph* graph, int from, int to, int weight);
ListNode* newListNode(int to);
void printGraph(Graph* graph);

int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1, 7);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 1, 3, 11);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 3, 34);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 5, 1, 8);
    addEdge(graph, 6, 4, 4);

    printGraph(graph);
    return 0;
}

int isPathExist(Graph* graph, int from, int to);

Graph* createGraph() {
    Graph* graph;
    graph = (Graph*)malloc(sizeof(Graph));

    graph->array = (List*)malloc(GRAPH_VERTEX * sizeof(List));
    for (int i = 0; i < GRAPH_VERTEX; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int from, int to, int weight) {
    ListNode* newNode = newListNode(to);
    newNode->next = graph->array[from].head;
    graph->array[from].head = newNode;

   newNode->weight = weight;
 

    newNode = newListNode(from);
    newNode->next = graph->array[to].head;
    graph->array[to].head = newNode;
    newNode->weight = weight;
}

ListNode* newListNode(int to) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->to = to;
    newNode->next = NULL;
    return newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < GRAPH_VERTEX; i++) {
        ListNode* list = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (list)
        {
            printf("-> %d", list->to);
            printf("(%d)", list->weight);
            list = list->next;
        }
        printf("\n");
    }
}

