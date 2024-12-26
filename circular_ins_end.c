#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node *ptr)
{
    struct Node*p=ptr;
    do
    {
        printf("The element: %d\n",p->data);
        p=p->next;
    }while(p!=ptr);
}

struct Node *Ins_End(struct Node*ptr,int data)
{
    struct Node *p=ptr;
    while(p->next!=ptr)
    {
        p=p->next;
    }
    struct Node*q=(struct Node*)malloc(sizeof(struct Node*));
    q->data=data;
    q->next=p->next;
    p->next=q;
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head=(struct Node *)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct Node*));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=head;

    Traverse(head);
    head=Ins_End(head,60);
    printf("After insertion in the end:\n");
    Traverse(head);
}