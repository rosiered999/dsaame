#include<stdio.h>
#include<stdlib.h>

struct DLLnode{
    int data;
    struct DLLnode* prev;
    struct DLLnode* next;
};

struct DLLnode* head;

void insert(int N)
{
    struct DLLnode* temp = head;
    struct DLLnode* prev;
    struct DLLnode* newnode = malloc(sizeof(struct DLLnode));
    if(temp==NULL)
    {
        newnode->data = N;
        temp = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = temp;
    }
    else
    {
        while(temp->next!=NULL)
        {
            prev = temp;
            temp=temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next = NULL;
        newnode->data = N;
    }
}

void delete(int N)
{
    struct DLLnode* temp=head;
    if(temp==NULL)
    {
        printf("not there\n");
    }
    else
    {
        while(temp->next!=NULL&&temp->data!=N)
        {
            temp = temp->next;
        }
        if(temp->next==NULL && temp->prev==NULL)
        {
            head = NULL;
        }
        else if(temp->next==NULL)
        {
            temp->prev->next = NULL;
        }
        else if(temp->prev==NULL)
        {
            temp = temp->next;
            temp->prev = NULL;
            head = temp;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
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
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}

int main()
{
    int M,N;
    char c[1];
    scanf("%d",&M);
    int i;
    for(i=0;i<M;i++)
    {
        scanf("%d",&N);
        insert(N);
    }
    print();
    while(1)
    {
        scanf("%s", c);
        if(c[0]=='p')
            print();
        else if(c[0]=='d')
        {
            int d;
            scanf("%d", &d);
            delete(d);
        }
        else if(c[0]=='q')
            exit(0);
    }
}
