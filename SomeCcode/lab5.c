#include <stdio.h>
#include <stdlib.h>


struct AdjListNode 
{
	int vertex_num;
	struct AdjListNode *next;
};


struct AdjList
{
	struct AdjListNode *head;
};


struct Graph
{
	int noofvertex;
	struct AdjList* array;
};


struct AdjListNode* newAdjListNode(int v)
{
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->vertex_num = v;
	newNode->next = NULL;
	
	return newNode;
}


struct Graph* createGraph(int n)
{
	int i;
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->noofvertex = n;
	
	
	graph->array = (struct AdjList*)malloc(n * sizeof(struct AdjList));
	
	
	for(i=0;i<n;i++)
	{
		graph->array[i].head = NULL;
	}
	
	return graph;
}


void addEdge(struct Graph *graph, int src, int dest)
{
	
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	newNode = newAdjListNode(src);
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
}


void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->noofvertex; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->vertex_num);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}



int main()
{

    int V = 5;
    int visited[5] = {0};
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

  
    
    printGraph(graph);

return 0;
}




