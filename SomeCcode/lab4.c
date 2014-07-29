#include <stdio.h>

int main()
{
   int array[10];
   int i, N;

   

   printf("Enter the value of N\n");
   scanf("%d",&N);

   printf("Enter the elements one by one\n");
   for(i=0; i<N ; i++)
   {
	scanf("%d",&array[i]);
   }
   printf("Input array is\n");
   for(i=0; i<N ; i++)
   {
	printf("%d\n",array[i]);
   }
   
   MinHeap(array);
   printf("After min heap: \n");
   for(i=0; i<N ; i++)
   {
	printf("%d\n",array[i]);
   }
   return 0;
}


int Parent(i)
{
if (i%2==0)
    return i/2;
else
    return (i-1)/2;
}

int Left(i)
{
return 2i;
}

int Right(i)
{
return 2*i + 1;
}


void Swap(a,b)
{
int temp;
temp=a;
b=a;
a=temp;
}

int length(int A[])
{
int i;
for (i=0;i<10;i++) ;
return i;
}


void Heapify(int A[],int i)
{
int l,r,min;
int heap_size=length(A);
l=Left(i);
r=Right(i);
if (l<=heap_size)
    if (A[l]>A[i])
        min=i;
    else
        min=l;

else if (r<=heap_size && A[r]<A[min])
    min=r;

else if (min != i)
    Swap(&A[i],&A[min]);
    Heapify(A,min);
}

int MinHeap(int A[])
{
int b;
int heap_size;
heap_size = length(A);

for (b= heap_size/2;b<=1;b--){
    Heapify(A,b);
}
}


