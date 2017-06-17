#include<stdio.h>
#include<stdlib.h>
#define maxElements

struct node{
    int numElements;
    int array[maxElements];
    struct node* next;
};

int main()
{
   int M,N,i,block;
   scanf("%d", &M);
   for(i=0;i<M;i++)
   {
        scanf("%d", &N, &block);
        insert(N,block);
   }
   print();
}
