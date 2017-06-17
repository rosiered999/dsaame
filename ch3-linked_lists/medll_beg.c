#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

struct node{
    int data;
    struct node* ptrdiff;
};

struct node* XOR(struct node* a, struct node* b)
{
    return (struct node*)((unsigned int)(a) ^ (unsigned int)(b));
}

struct node* head = NULL;

void insert(int N)
{
    struct node* temp = head;
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = N;
    newnode->ptrdiff = XOR(temp,NULL);
    if(temp==NULL)
    {
        head = newnode;
    }
    else
    {
        struct node* next = XOR(head->ptrdiff,NULL);
        head->ptrdiff = XOR(newnode,next);
        head = newnode;
    }
}

void print()
{
    struct node* curr=head, *next,*prev;
    if(curr==NULL)
    {
        printf("empty\n");
    }
    else
    {
        while(curr!=NULL)
        {
            printf("%d\n",curr->data);
            next = XOR(prev, curr->ptrdiff);
            prev = curr;
            curr = next;
        }
    }
}

int main()
{
    int M,N,i;
    scanf("%d",&M);
    for(i=0;i<M;i++)
    {
        scanf("%d", &N);
        insert(N);
    }
    print();
}
