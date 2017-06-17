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
    if(temp==NULL)
    {
        newnode->next = NULL;
        newnode->data = N;
        head = newnode;
    }
    else
    {
        
    }
}
