typedef struct successors {
    int d;          /* number of successors */
    int len;        /* number of slots in array */
    char is_sorted; /* true if list is already sorted */
    int list[1];    /* actual list of successors */
} Successors;

typedef struct graph {
    int n;              /* number of vertices */
    int m;
    successors* alist[1];
} Graph;

Graph* graphCreate(int n);
void FreeGraph(Graph* g);
void AddGraphEdge(Graph* g, int u, int v);
int graph_vertex_count(Graph* g);
int graph_edge_count(Graph* g);
int graph_out_degree(Graph* g, int source);
static int intcmp(const void* a, const void* b);
int graph_has_edge(Graph* g, int source, int sink);
void graph_foreach(Graph* g, int source, void (*f)(Graph* g, int source, int sink, void* data), void* data);