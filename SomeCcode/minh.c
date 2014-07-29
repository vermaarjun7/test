#include <stdio.h>
#include <stdlib.h>


void MaxHeap(int A[])
{
int b;
int heap_size;
heap_size = length(A);

for (b= fact(heap_size/2);b<1;b--){
    MaxHeapify(A,b);
}

}

int arr[] MaxHeapify(int A[],int i)
{
int l,r,largest;
int heap_size=length(A);
l=Left(i);
r=Right(i);
if (l<=heap_size)
    if (A[l]>A[i])
        largest=l;
    else
        largest=i;

else if (r<=heap_size && A[r]>A[largest])
    largest=r;

else if (largest != i)
    Swap(&A[i],&A[largest]);
    MaxHeapify(A,largest);
}

int Parent(i)
{
return fact(i/2);
}

int Left(i)
{
return 2i;
}

int Right(i)
{
return 2*i + 1;
}

int fact(i)
{
if (i==0 || i==1)
    return 1;

else 
return i*fact(i-1);
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
for (i=0;i<10;i++)
    ;
return i;
}

int main()
{
int heap_size[10];
heap_size = {18,5,9,14,11,2,7,6,12,3};
Maxheap(heap_size);
}


