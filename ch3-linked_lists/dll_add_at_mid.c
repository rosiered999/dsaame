#include<stdio.h>
#include<stdlib.h>

struct DLLnode{
    int data;
    struct DLLnode* next;
    struct DLLnode* prev;
};

struct DLLnode* head = NULL;

void insert(int N,int pos)
{
    struct DLLnode* newnode = malloc(sizeof(struct DLLnode));
    struct DLLnode* temp = head;
    if(temp==NULL)
    {
        newnode->data = N;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        int n=1;
        while(temp->next!=NULL && n<pos)
        {
            temp=temp->next;
            n++;
        }
        if(temp->next==NULL && n==pos)
        {
            newnode->data = N;
            temp->next = newnode;
            temp->next->prev = temp;
            temp->next->next = NULL;
        }
        else if(temp->next==NULL)
        {
            newnode->data = N;
            temp->next = newnode;
            temp->next->prev = temp;
            temp->next->next = NULL;
        }
        else if(n==pos)
        {
            newnode->data = N;
            temp->next->prev = newnode;
            temp->next->next = temp->next;
            temp->next = newnode;
            temp->next->prev = temp;
        }
    }
}

void print()
{
    struct DLLnode* temp=head;
    if(temp==NULL)
    {
        printf("empty\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

int main()
{
    int M,N,i,pos;
    scanf("%d", &M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d", &N, &pos);
        insert(N,pos);
    }
    print();
}
