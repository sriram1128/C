#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node*prev;
};

void Traverse(struct Node *ptr)
{
    struct Node *p=ptr;
    while(p!=NULL)
    {
        printf("Elements: %d\n",p->data);
        p=p->next;
    }
}

struct Node *Delbeg(struct Node *ptr)
{
    struct Node *p=ptr;
    ptr=ptr->next;
    ptr->prev=NULL;
    p->next=NULL;
    return ptr;
}

int main()
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node ));

    head->data=10;
    head->prev=NULL;
    head->next=second;

    second->data=20;
    second->prev=head;
    second->next=third;

    third->data=30;
    third->prev=second;
    third->next=NULL;

    Traverse(head);
    head=Delbeg(head);
    printf("After deletion :\n");
    Traverse(head);
    return(0);
}