#include <stdio.h> 
#include <stdlib.h>
 
typedef struct stack 
{ 
int data; 
struct stack *next; 
} stack; 
void init(stack **); 
int empty(stack *); 
char pop(stack **); 
void push(stack **,int); 
void print(stack *); 
void main() 
{ 
stack *TOP; 
int x,op; 
init(&TOP); 
 
do 
{ 
printf("\n1)Push\n2)Pop\n3)Print\n4)Quit"); 
printf("\nEnter Your Choice : "); 
scanf("%d",&op); 
switch(op) 
{ 
case 1: printf("\nEnter a data : "); 
scanf("%d",&x); 
push(&TOP,x); 
break; 
case 2: if(!empty(TOP)) 
{ 
x=pop(&TOP); 
printf("\nPopped data= %d",x); 
} 
else 
printf("\nStack is empty ...."); 
break; 
case 3: print(TOP); 
break; 
} 
} while(op!=4); 
} 
 
void init(stack **T) 
{ 
*T=NULL; 
} 
int empty(stack *TOP) 
{ 
    if(TOP==NULL) 
        return(1); 
    return(0); 
} 
void push(stack **T,int x) 
{ 
stack *P; 
P=(stack *)malloc(sizeof(stack)); 
P->data=x; 
P->next=*T; 
*T=P; 
} 
char pop(stack **T) 
{ 
int x; 
stack * P; 
P=*T; 
*T=P->next; 
x=P->data; 
free(P); 
return(x); 
} 
void print(stack *T) 
{ 
printf("\n"); 
while (T!=NULL) 
{ 
printf("%d ",T->data); 
T=T->next; 
} 
} 
