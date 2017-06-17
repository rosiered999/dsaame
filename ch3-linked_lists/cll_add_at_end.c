#include<stdio.h>
#include<stdlib.h>

struct CLLnode{
    int data;
    struct CLLnode* next;
};

struct CLLnode* head = NULL;

void insert(int N)
{
    struct CLLnode* newnode = malloc(sizeof(struct CLLnode));
    struct CLLnode* temp = head;
    if(temp==NULL)
    {
        temp = newnode;
        temp->data = N;
        temp->next = temp;
        head = temp;
    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next = head;
        newnode->data = N;
        temp->next = newnode;
    }
}
    
void print()
{
    struct CLLnode* temp = head;
    if(temp==NULL)
    {
        printf("empty\n");
    }
    else
    {
        while(temp->next!=head)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void delete(int N)
{
    struct CLLnode* temp = head;
    struct CLLnode* prev;
    if(temp==NULL)
    {
        printf("empty\n");
    }
    else
    {
        while(temp->next!=head && temp->data!=N)
        {
            prev = temp;
            temp=temp->next;
        }
        if(temp==head && temp->next==head)
        {
            head = NULL;
        }
        else if(temp==head && temp->data==N || temp==head)
        {
            prev->next = temp->next;
            head = temp->next;
        }
        else if(temp->next==head)
            prev->next = head;
        else
        {
            prev->next = temp->next;
        }
    }
}

int main()
{
    int M,N,i;
    char s[1];
    int pos;
    scanf("%d", &M);
    for(i=0;i<M;i++)
    {
        scanf("%d", &N);
        insert(N);
    }
    print();

    while(1)
    {
        scanf("%s", s);
        if(s[0]=='p')
            print();
        else if(s[0]=='d')
        {
            scanf("%d %d", &N,&pos);
            delete(N);
        }
        else if(s[0]=='q')
            exit(0);
    }
}
