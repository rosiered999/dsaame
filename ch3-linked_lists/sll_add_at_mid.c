#include<stdio.h>
#include<stdlib.h>

int M;

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int N, int pos)
{
    struct node* temp=head;
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = N;
    int i;
    if(temp==NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else if(pos==1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        for(i=0;i<pos;i++)
        {
            if(temp->next!=NULL)
                temp = temp->next;
            else
                break;
        }
        if(temp->next!=NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
}

void print()
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
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
