#pragma once

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


Graph* createGraph() {
    Graph* graph;
    graph = (Graph*)malloc(sizeof(Graph));

    graph->array = (List*)malloc(GRAPH_VERTEX * sizeof(List));
    for (int i = 0; i < GRAPH_VERTEX; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

ListNode* newListNode(int to) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->to = to;
    newNode->next = NULL;
    return newNode;
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



