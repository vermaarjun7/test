#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct recordlist{
   char *name;
   int no;
   struct recordlist *next;
}record;

void swap(record **first, record **second){
record *temp;
temp->name = (*first)->name;
temp->no = (*first)->no;

(*first)->name = (*second)->name;
(*first)->no = (*second)->no;

(*second)->name = temp->name;
(*second)->no = temp->no;
}

sorting(record **first){
//record *q;
record *p,*top;
top = *first;
int changed = 1;
while( changed ){
   //q = *first;
   p = top;
   changed = 0;
   while(p->next != NULL){
      if(p->no > p->next->no){
         swap(&(p), &(p->next));
         changed = 1;
      }
      //q = p;
      if(p->next != NULL)
         p = p->next;
   }
}
}

int insert(FILE **fp, record **first){
int bekaar = fgetc(*fp);
int c = fgetc(*fp);
int i;
//int temp;
record *new;
new = (record*)malloc(sizeof(record));
new->next = NULL;
int option;
if(c != EOF){
   
   new->name = (char*)malloc(sizeof(char)*100);
   new->name[0] = c;
   i = 1;
   while((c = fgetc(*fp)) != 32 ){
      new->name[i] = c;
      i += 1;
   }
   
   new->name[i] = '\0';
   fscanf(*fp, "%d", &(new->no));
   //printf("%d----%d\n",temp,new->no);
}
else
   return(-1);

new->next = *first;
*first = new;
return(1);
}  

void printing(record** first){
record *temp;
temp = *first;
while(temp->next != NULL){
   printf("%s ",temp->name);
   printf("%d\n",temp->no);
   temp = temp->next;
}
printf("%s ",temp->name);
printf("%d\n",temp->no);
}

int main(){
FILE *fp;
fp = fopen("text.txt", "r");
//int temp; //for name
int c;
int i = 0; //character array index.
int option;

record *first;
first = (record*)malloc(sizeof(record));
first->next = NULL;
first->name = (char*)malloc(sizeof(char)*100);

if(fp != NULL){
      i = 0;   
      while((c = fgetc(fp)) != 32 ){
         first->name[i] = c;
         i += 1;
         }
      first->name[i] = '\0';
      
      //printf("%s ", first->name);
      fscanf(fp,"%d", &first->no);
      //printf("--%d---%d\n",temp,first->no);
}
else
   printf("file hi nahi khuli...\n");
   
while(1){
   if((insert(&fp,&first)) == -1)
      break;
   }  

printing(&first);

printf("sort according to? : 2) no");
scanf("%d",&option);

if(option == 2){
   sorting(&first);
   printf("printing the sorted list..:\n");
   printing(&first);
}

else
   printf("incorrect option list wont be sorted.");
   
fclose(fp);
return 0;
}