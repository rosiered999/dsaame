#include<stdio.h>
#include<stdlib.h>

struct CLLnode{
    int data;
    struct CLLnode* next;
};

struct CLLnode* head = NULL;

void insert(int N, int pos)
{
    struct CLLnode* temp = head;
    struct CLLnode* newnode = malloc(sizeof(struct CLLnode));
    if(temp==NULL)
    {
        newnode->data = N;
        newnode->next = head;
        head = newnode;
    }
    else
    {
        int n=1;
        while(n<pos)
        {
            temp=temp->next;
            n++;
        }
        if(temp->next==head && temp==head)
        {
            newnode->next = head;
            newnode->data = N;
            newnode->next->next = newnode;
            head = newnode;
        }
        else if(temp->next==head)
        {
            newnode->next = head;
            newnode->data = N;
            temp->next = newnode;
        }
        else if(temp==head)
        {
            newnode->next = head;
            newnode->data = N;
            while(temp->next!=head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            head = newnode;
        }
        else
        {
            newnode->data = N;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void print()
{
    struct CLLnode* temp=head;
    if(temp==NULL)
        printf("empty\n");
    else
    {
        while(temp->next!=head)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
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
