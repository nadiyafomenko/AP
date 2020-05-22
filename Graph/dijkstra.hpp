typedef struct {
    int  v;
    int dist;
} MinHeapNode;

// Structure to represent a min heap 
typedef struct {
    int size;      // Number of heap nodes present currently 
    int capacity;  // Capacity of min heap 
    int* pos;     // This is needed for decreaseKey() 
    MinHeapNode** array;
} MinHeap;

MinHeap* createMinHeap(int capacity);
MinHeapNode* newMinHeapNode(int v, int dist);
void dijkstra(BiggestPathes* biggestPathes, Graph* graph, int src);
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
void decreaseKey(MinHeap* minHeap, int v, int dist);
int isEmpty(MinHeap* minHeap);
MinHeapNode* extractMin(MinHeap* minHeap);
bool isInMinHeap(MinHeap* minHeap, int v);
void minHeapify(MinHeap* minHeap, int idx);
void printArr(int dist[]);
int findMaxPathfromShortest(BiggestPathes* biggestPathes, int dist[]);

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

void dijkstra(BiggestPathes* biggestPathes, Graph* graph, int src)
{
    int dist[GRAPH_VERTEX];      // dist values used to pick minimum weight edge in cut 

    // minHeap represents set E 
    MinHeap* minHeap = createMinHeap(GRAPH_VERTEX);

    // Initialize min heap with all vertices. dist value of all vertices  
    for (int v = 0; v < GRAPH_VERTEX; ++v)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    // Make dist value of src vertex as 0 so that it is extracted first 
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    // Initially size of min heap is equal to V 
    minHeap->size = GRAPH_VERTEX;

    // In the followin loop, min heap contains all nodes 
    // whose shortest distance is not yet finalized. 
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum distance value 
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number 

        // Traverse through all adjacent vertices of u (the extracted 
        // vertex) and update their distance values 
        ListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->to;

            // If shortest distance to v is not finalized yet, and distance to v 
            // through u is less than its previously calculated distance 
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;

                // update distance value in min heap also 
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    // print the calculated shortest distances 
    printArr(dist);
    findMaxPathfromShortest(biggestPathes, dist);
}

// A utility function to swap two nodes of min heap. Needed for min heapify 
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
{
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void decreaseKey(MinHeap* minHeap, int v, int dist)
{
    // Get the index of v in  heap array 
    int i = minHeap->pos[v];

    // Get the node and update its dist value 
    minHeap->array[i]->dist = dist;

    // Travel up while the complete tree is not hepified. 
    // This is a O(Logn) loop 
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        // Swap this node with its parent 
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        // move to parent index 
        i = (i - 1) / 2;
    }
}

int isEmpty(MinHeap* minHeap)
{
    return minHeap->size == 0;
}

MinHeapNode* extractMin(MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node 
    MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node 
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node 
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root 
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

bool isInMinHeap(MinHeap* minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

void printArr(int dist[])
{
    printf("Vertex  Distance from Source\n");
    for (int i = 0; i < GRAPH_VERTEX; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int findMaxPathfromShortest(BiggestPathes* biggestPath, int dist[]) {
    int max = dist[0];
    int i = biggestPath->pos;
    biggestPath->pos = i++;
    MinPath* minPath = (MinPath*)malloc(sizeof(MinPath));

    for (int i = 0; i < GRAPH_VERTEX; ++i)
        if (dist[i] > max) {
            max = dist[i];
            minPath->to = i;
        }
    minPath->pathWeight = max;
    printf("Max Weight - %d on path to %d", minPath->pathWeight, minPath->to);
    return max;
}

// Position is needed for decreaseKey() 
void minHeapify(MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx)
    {
        // The nodes to be swapped in min heap 
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        // Swap positions 
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}