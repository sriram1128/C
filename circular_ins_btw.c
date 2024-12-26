#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};

void Traversal(struct Node*ptr)
{
    struct Node *p=ptr;
    do
    {
        printf("The element: %d\n",p->data);
        p=p->next;
    }while(p!=ptr);
}

struct Node *Insbtw(struct Node *ptr,int data,int pos)
{
    int i=0;
    struct Node*p=ptr;
    while(i!=pos-1)
    {
        p=p->next;
        i++;
    }
    struct Node *q;
    q=(struct Node*)malloc(sizeof(struct Node*));
    q->data=data;
    q->next=p->next;
    p->next=q;
    return ptr;
}

int main()
{
    struct Node*head;
    struct Node*second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node*)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct  Node*));
    fourth=(struct Node*)malloc(sizeof(struct Node*));
   

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=head;

    Traversal(head);
    head=Insbtw(head,66,2);
    printf("After insertion in between:\n");
    Traversal(head);
    return(0);
}