#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

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
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->data = N;
        newnode->next = NULL;
    }
}

void print()
{
    printf("printing\n");
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
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

void delete(int N)
{
    struct node* temp = head;
    struct node* prev=NULL;
    if(temp==NULL)
    {
        printf("empty\n");
    }
    else
    {
        while(temp->next!=NULL && temp->data!=N)
        {
            prev = temp;
            temp=temp->next;
        }
        if(temp->data==N)
        {
            if(prev==NULL && temp->next == NULL)
            {
                head = NULL;
            }
            else if(temp->next ==NULL)
            {
                prev->next = NULL;
            }
            else if(prev == NULL)
            {
                temp=temp->next;
                head = temp;
            }
            else
            {
                prev->next = temp->next;
            }
        }
        else
        {
            printf("not there\n");
        }
    }
}

int main()
{
    int M,N;
    char c[1];
    scanf("%d", &M);
    int i,d;
    for(i=0;i<M;i++)
    {
        scanf("%d",&N);
        insert(N);
    }
    print();

    while(1)
    {
        printf("in while\n");
        scanf("%s", c);
        if(c[0]=='p')
        {
            print();
        }
        else if(c[0]=='d')
        {
            scanf("%d",&d);
            delete(d);
        }
        else if(c[0]=='q')
        {
            exit(0);
        }
    }
}
