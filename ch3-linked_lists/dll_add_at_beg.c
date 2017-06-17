#include<stdio.h>
#include<stdlib.h>

struct DLLnode{
    int data;
    struct DLLnode* next;
    struct DLLnode* prev;
};

struct DLLnode* head = NULL;

void insert(int N)
{
    struct DLLnode* temp = head;
    struct DLLnode* newnode = malloc(sizeof(struct DLLnode));
    if(temp==NULL)
    {
        temp = newnode;
        temp->next = NULL;
        temp->prev = NULL;
        temp-> data = N;
        head = temp;
    }
    else
    {
        newnode->data = N;
        temp->prev = newnode;
        temp->prev->next = temp;
        temp->prev->prev = NULL;
        head = temp->prev;
    }
}

void print()
{
    struct DLLnode* temp = head;
    if(temp==NULL)
        printf("empty\n");
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
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
