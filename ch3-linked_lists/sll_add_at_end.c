#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int N)
{
    struct node* tempo = malloc(sizeof(struct node));
    struct node* temp = head;
    if(temp==NULL)
    {
        tempo->data = N;
        tempo->next = NULL;
        head = tempo;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = tempo;
        tempo->data = N;
        tempo->next = NULL;
    }
}

void print()
{
    struct node* temp = head;
    if(temp==NULL)
    {
        printf("empty\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d\n", temp->data);
            temp=temp->next;
        }
        printf("%d\n", temp->data);
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
