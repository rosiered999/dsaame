//nth node from the end of linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int N)
{
    struct node* temp=head;
    struct node* newnode = malloc(sizeof(struct node));
    if(temp==NULL)
    {
        newnode->data = N;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        while(temp->next)
        {
            temp = temp->next;
        }
        newnode->data = N;
        newnode->next = NULL;
        temp->next = newnode;
    }
}

void find(int n)
{
    int count = 0;
    struct node* temp = head;
    while(temp->next!=NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    int num = 0, new;
    while(temp->next!=NULL && new!=n)
    {
        new = count - num;
        temp = temp->next;
        num++;
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

    int n;
    scanf("%d", &n);
    find(n);
}
