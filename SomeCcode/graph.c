#include <stdio.h>
#include <stdlib.h>
 

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 

struct AdjList
{
    struct AdjListNode *head;  
};
 
struct Graph
{
    int num_of_nodes;
    struct AdjList* array;
};
 

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 

struct Graph* createGraph(int num_of_nodes)
{
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_of_nodes = num_of_nodes;
 
    
    graph->array = (struct AdjList*) malloc(num_of_nodes * sizeof(struct AdjList));
 
     
    int i;
    for (i = 0; i < num_of_nodes; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 

void addEdge(struct Graph* g, int src, int dest)
{
    
    
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = g->array[src].head;
    g->array[src].head = newNode;
 
    
    newNode = newAdjListNode(src);
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;
}

void DeleteEdge(struct Graph *g,int i, int j)
{
struct AdjListNode *tmp = g->array[i].head;
struct AdjListNode *prev = NULL;
while (tmp!=NULL)
{
printf("%d ->",temp->dest);
if (tmp->dest==j){
    if (prev!=NULL){
        printf("deleting "%d" "%d",tmp->id,prev->id)
        prev->next=tmp->next;
    }
    break;
}  
prev=tmp;
tmp=tmp->next;
}

tmp = g->array[j].head;
while (tmp!=NULL)
{
printf("%d ->",temp->dest);
if (tmp->dest==j){
    if (prev!=NULL){
        printf("deleting "%d" "%d",tmp->id,prev->id)
        prev->next=tmp->next;
    }
    break;

}

void DestroyGraph(graph* G)
{
int i;

for(i=0;i<G->num_of_nodes;i++){
    struct AdjListNode *temp =G->array[i].head;
    while(temp!=NULL)
    {
    struct AdjListNode *temp2;
    temp2=temp->next;
    free(temp);
    temp=temp2;
    }
}
free(G->array);
free(G);
}


int BFS(graph *g,int v)
{
queue init();
//create a set v
enqueue(Q,v);
//add v to V
while(IsEmpty(Q))
{
t=dequeue(Q);
if t ==




