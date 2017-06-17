//stacks using linked lists
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void push(int N)
{
    struct node* newnode = malloc(sizeof(struct node));
    if(head==NULL)
    {
        newnode->data = N;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        newnode->data = N;
        head = newnode;
    }
}

void pop()
{
    struct node* temp=head;
    if(temp==NULL)
    {
        printf("empty\n");
    }
    else
    {
        printf("%d\n", temp->data);
        temp = temp->next;
        head = temp;
    }
}

void top()
{
    if(head!=NULL)
        printf("%d\n", head->data);
    else
        printf("empty\n");
}

void isEmpty()
{
    if(head==NULL)
        printf("empty\n");
}

void delete(int N)
{
    ;
}

int main()
{
    int N,M,i;
    char str[1];
    scanf("%d", &M);
    for(i=0;i<M;i++)
    {
        scanf("%d", &N);
        push(N);
    }
    printf("o t e d u \n");
    while(1)
    {
        scanf("%s", str);
        if(str[0]=='o')
            pop();
        else if(str[0]=='t')
            top();
        else if(str[0]=='e')
            isEmpty();
        else if(str[0]=='d')
        {
            scanf("%d", &N);
            delete(N);
        }
        else if(str[0]=='u')
        {
            scanf("%d", &N);
            push(N);
        }
    }
}
