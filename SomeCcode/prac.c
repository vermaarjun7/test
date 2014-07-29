#include <stdio.h>
#include <stdlib.h>

struct sNode{
struct sNode *next;
int data;
};

int pop(struct sNode** top_ref)
{
  int res;
  struct sNode *top;
  
  /*If stack is empty then error */
  if(*top_ref == NULL)
  {
     printf("Stack overflow \n");
     
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}

void push(struct sNode** top_ref, int new_data)
{
  /* allocate node */
  struct sNode* new_node =
            (struct sNode*) malloc(sizeof(struct sNode));
  
  if(new_node == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }            
  
  /* put in the data  */
  new_node->data  = new_data;
  
  /* link the old list off the new node */
  new_node->next = (*top_ref);   
  
  /* move the head to point to the new node */
  (*top_ref)    = new_node;
}
void print(sNode **T) 
{ 
printf("\n"); 
while (*T!=NULL) 
{ 
printf("%d ",T->data); 
T=T->next; 
}

int pop(sNode **); 
void push(sNode **,int); 
void print(sNode **);
void main()
{
struct sNode *s;
*s = NULL

int x,op;

do 
{ 
printf("\n1)Push\n2)Pop\n3)Print\n4)Quit"); 
printf("\nEnter Your Choice : "); 
scanf("%d",&op); 
switch(op) 
{ 
case 1: printf("\nEnter a data : "); 
scanf("%d",&x); 
push(&s,x); 
break; 
case 2: 
{ 
x=pop(&s); 
printf("\nPopped data= %d",x);
case 3: print(&sNode); 
break; 
} 
}while(op!=4); 
}
} 













