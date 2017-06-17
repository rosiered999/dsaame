#include<stdio.h>
#include<stdlib.h>

struct CLLnode{
    int data;
    struct CLLnode* next;
};

struct CLLnode* head = NULL;

void insert(int N)
{
    struct CLLnode* temp = head;
    struct CLLnode* newnode = malloc(sizeof(struct CLLnode));
    if(temp==NULL)
    {
        newnode->data = N;
        temp=newnode;
        temp->next = newnode;
        head = temp;
    }
    else
    {
        newnode->next = head;
        newnode->data = N;
        while(temp->next!=head)
            temp = temp->next;
        temp->next = newnode;
        head = newnode;
    }
}

void print()
{
    struct CLLnode* temp = head;
    while(temp->next!=head)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    int M,N,i;
    scanf("%d", &M);
    for(i=0;i<M;i++)
    {
        scanf("%d", &N);
        insert(N);
    }
    print();
}
