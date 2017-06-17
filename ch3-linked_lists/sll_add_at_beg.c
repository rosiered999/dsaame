#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int N)
{
    struct node* temp = head;
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = N;
    if(temp==NULL)
    {
        temp = newnode;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        //overwrites the first one and only one is lef
        //dumbass didnt reassign head to temp in prev section
        newnode->next = head;
        head = newnode;
    }
}

void print()
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    int M,N;
    scanf("%d", &M);
    int i;
    for(i=0;i<M;i++)
    {
        scanf("%d", &N);
        insert(N);
    }
    print();
}
