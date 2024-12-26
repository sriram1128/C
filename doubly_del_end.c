#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void Traverse(struct Node *ptr)
{
    struct Node*p=ptr;
    while(p!=NULL)
    {
        printf("Element: %d\n",p->data);
        p=p->next;
    }
}

struct Node *DelEnd(struct Node *ptr)
{
    struct Node *p=ptr;
    struct Node *q=ptr->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    q->prev=NULL;
    return ptr;
}

int main()
{
    struct Node *head=(struct Node *)malloc(sizeof(struct Node*));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node*));

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
    head=DelEnd(head);
    printf("After Deletion:\n");
    Traverse(head);
    return(0);
}