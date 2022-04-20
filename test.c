#include <stdio.h>
#include <stdlib.h>

// Structure declarations ***************************************** //
typedef struct Edge
{
    int from, to;
    float weight;
} EDGE;

typedef struct EdgeListNode
{
    EDGE info;
    struct EdgeListNode *next;
} NODE;

typedef struct EdgeListQueue
{
    NODE *front, *rear;
} QUEUE;

typedef struct Graph
{
    int numVertex;
    QUEUE *array;
} GRAPH;

// Function to check whether the given queue is empty.
int isEmpty(QUEUE *q)
{
    return (q->rear == NULL || q->front == NULL);
}

// Function to insert an edge for the given queue.
int enqueue(QUEUE *q, EDGE e)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));

    if (temp == NULL)
    {
        printf("Memory allocation failed in enqueue.\n");
        return -1;
    }

    temp->info = e;
    temp->next = NULL;

    if (isEmpty(q))
    {
        q->front = temp;
    }
    else
    {
        q->rear->next = temp;
    }

    q->rear = temp;
    return 0;
}

// Function to delete an edge from the given queue.
int dequeue(QUEUE *q)
{
    NODE *temp;
    int vertex;
    temp = (NODE *)malloc(sizeof(NODE));

    if (temp == NULL)
    {
        printf("Memory allocation failed in dequeue.\n");
        return -1;
    }

    if (isEmpty(q))
    {
        printf("Queue empty.\n");
        return -1;
    }

    temp = q->front;
    vertex = temp->info.from;
    q->front = q->front->next;
    free(temp);
    return vertex;
}

// Function to insert a vertex for Breadth First Search traversal.
int BFSenqueue(QUEUE *q, int vertex)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));

    if (temp == NULL)
    {
        printf("Memory allocation failed in BFSenqueue.\n");
        return -1;
    }

    temp->info.from = vertex;
    temp->next = NULL;

    if (isEmpty(q))
    {
        q->front = temp;
    }
    else
    {
        q->rear->next = temp;
    }

    q->rear = temp;
    return 0;
}

// Function to return the number of vertices for a graph.
int returnVertex()
{
    int v;
    printf("\nEnter the number of vertices for the graph: ");
    scanf("%d", &v);
    return v;
}

// Function to initialize the graph i.e to create the empty queues.
int initialize(GRAPH *g)
{
    int i, v;
    v = g->numVertex;

    if (v < 0)
    {
        printf("Vertices cannot be less than 0\n");
        g->numVertex = returnVertex();
        initialize(g);
        return -1;
    }

    if (v == 0)
    {
        printf("Empty Graph.\n");
        g->numVertex = returnVertex();
        initialize(g);
        return -1;
    }

    if (v == 1)
    {
        printf("Null Graph.\n");
        g->numVertex = returnVertex();
        initialize(g);
        return -1;
    }

    g->array = (QUEUE *)malloc(sizeof(QUEUE) * v);

    if (g->array == NULL)
    {
        printf("Memory allocation failed in array initialization.\n");
        return -1;
    }

    for (i = 0; i < v; i++)
    {
        g->array[i].front = NULL;
        g->array[i].rear = NULL;
    }

    return v;
}

// Function to add an edge for the given graph.
int addEdge(GRAPH *g, EDGE e)
{
    NODE *temp;
    int cg, status;
    temp = (NODE *)malloc(sizeof(NODE));

    if (temp == NULL)
    {
        printf("Memory allocation failed in addEdge.\n");
        return -1;
    }

    temp = g->array[e.from].front;

    while (temp != NULL)
    {
        if (temp->info.to == e.to)
        {
            printf("\nEdge already exist.\n");
            return -1;
        }
        temp = temp->next;
    }

    status = enqueue(&g->array[e.from], e);

    if (status == -1)
    {
        return -1;
    }

    cg = e.from;
    e.from = e.to;
    e.to = cg;

    status = enqueue(&g->array[e.from], e);

    if (status == -1)
    {
        return -1;
    }

    return 0;
}

// Function for Breadth First Search for the given graph.
int BFS(GRAPH *g, int startVertex)
{
    QUEUE q;
    char *status;
    int i, cur;
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));

    if (temp == NULL)
    {
        printf("Memory allocation failed in BFS.\n");
        return -1;
    }

    q.front = NULL;
    q.rear = NULL;
    status = (char *)malloc(sizeof(char) * g->numVertex);

    if (status == NULL)
    {
        printf("Memory allocation failed in BFS queue.\n");
        return -1;
    }

    for (i = 0; i < g->numVertex; i++)
    {
        status[i] = 0;
    }

    BFSenqueue(&q, startVertex);

    printf("\nBreadth First Search: \n");
    printf("\n");
    while (!isEmpty(&q))
    {
        cur = dequeue(&q);
        if (status[cur] == 0)
        {
            status[cur] = 1;
            printf("Explored vertex: %d.\n", cur);
            temp = g->array[cur].front;
            while (temp != NULL)
            {
                if (status[temp->info.to] == 0)
                {
                    BFSenqueue(&q, temp->info.to);
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}

// ******************************************************* // main()
int main()
{
    GRAPH *g1;
    EDGE e;
    NODE *temp;
    int choice, status, status2;

    temp = (NODE *)malloc(sizeof(NODE));

    if (temp == NULL)
    {
        return -1;
    }

    g1 = (GRAPH *)malloc(sizeof(GRAPH));
    if (g1 == NULL)
    {
        printf("Memory not available.\n");
        return -1;
    }

    g1->numVertex = returnVertex();
    g1->array = NULL;
    status = initialize(g1);

    while (status)
    {
        printf("\n1 Add edge\n");
        printf("2 BFT\n");
        printf("3 Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the edge to add\n");
            printf("\nFrom: ");
            scanf("%d", &e.from);
            printf("To: ");
            scanf("%d", &e.to);
            printf("Weight: ");
            scanf("%f", &e.weight);
            if (e.from != e.to && e.from >= 0 && e.from < g1->numVertex && e.to >= 0 && e.to < g1->numVertex && e.weight > 0)
            {
                status2 = addEdge(g1, e);
                if (status2 == 0)
                {
                    printf("\nEdge added.\n");
                }
                break;
            }
            printf("\nInvalid Edge\n");
            break;
        case 2:
            printf("\nEnter the starting vertex for BFS: ");
            scanf("%d", &e.from);
            if (e.from >= 0 && e.from < g1->numVertex)
            {
                BFS(g1, e.from);
                break;
            }
            printf("\nInvalid Vertex\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}