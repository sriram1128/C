#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("The element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node *InsertEnd(struct Node *ptr,int data)
{
    struct Node*p;
    struct Node*q=ptr;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    p=(struct Node*)malloc(sizeof(struct Node*));
    p->data=data;
    q->next=p;
    p->next=NULL;
    
    return ptr;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head=(struct Node*)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct Node*));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    Traverse(head);
    head=InsertEnd(head,40);
    printf("After insertion of node at the end:\n");
    Traverse(head);
    return(0);
    
}