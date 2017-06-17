#include<stdio.h>
#include<stdlib.h>
#define maxElements

struct node{
    int numElements;
    int array[maxElements];
    struct node* next;
};

int numblock = 0;
struct node* head = NULL;

void insert(int N, int block)
{
    int num = 1;
    struct node* temp = head;
    struct node* newnode = malloc(sizeof(struct node));
    int i;
    newnode->numElements = 0;
    for(i=0;i<maxElements;i++)
    {
        newnode->array[i] = 0;
    }
    if(temp==NULL)
    {
        newnode->numElements = 0;
        newnode->array[numElements] = N;
        newnode->numElements++;
        head = newnode;
        head->next = NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
            temp->next = newnode;
            newnode->array[newnode->numElements] = N;
            newnode->numElements++;
    }
}

void print()
{
    int i;
    struct node* temp = head;

    if(temp==NULL)
    {
        printf("empty\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            int num = temp->numElements;
            for(i=0;i<num;i++)
            {
                printf("%d ", temp->array[num]);
            }
            printf("\n");
        }
    }
}

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
