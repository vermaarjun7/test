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
    int V;
    struct AdjList* array;
};
 

typedef struct _node {
      int element;
      struct _node *next;
   } node;

typedef struct {
      node *front;
      node *back;
   } queue;

int isFull( queue Q )
   {
      return 0;
   }


int IsEmpty(queue Q)
{
return Q.front==Q.back;
    
}

queue dequeue ( queue Q )
   {
      if (isEmpty(Q)) {
         printf("dequeue: Queue is empty\n");
         return Q;
      }

      /* Make the front of the queue the new dummy node */
      Q.front = Q.front -> next;
      Q.front -> element = '\0';

      return Q;
   }

queue enqueue ( queue Q ,int ch )
   {
      node *C;
      if (isFull(Q)) {
         printf("enqueue: Queue is full\n");
         return Q;
      }

      
      C = (node *)malloc(sizeof(node));
      C -> element = ch;
      C -> next = NULL;

      
      Q.back -> next = C;
      Q.back = C;

      return Q;
   }


struct Graph* BFS(int s)
{
char visited[4]; 
int i;
for (i=0;i<4;i++)
{
    visited[i] ="false";
}
struct queue q1;

visited[s]="true";
enqueue(q1,s);

struct AdjList *i;
dequeue(q1);

while(!IsEmpty(q1))
{
s=dequeue(q1);
int i;
int v=0;
for (i=graph->array[v++].head;i!=NULL;++i)
{
    if (!visited[*i])
    {
        visited[*i]="true";
        dequeue(*i);
    }
}
}
}

int main()
{
   
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    printf("Following is Breadth First Traversal (starting from vertex 2) \n");
    BFS(2);
 
    return 0;
}


