#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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

struct Node *DelBtw(struct Node *ptr,int pos)
{
    int i=0;
    struct Node *p=ptr;
    struct Node *q=p->next;
    struct Node *r=q->next;
    while(i!=pos-1)
    {
        r=r->next;
        q=q->next;
        p=p->next;
        i++;
    }
    
    p->next=r;
    q->prev=NULL;
    q->next=NULL;
    r->prev=p;
    free(q);
    return ptr;
}

int main()
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node*));

    head->data=10;
    head->next=second;
    head->prev=NULL;

    second->data=20;
    second->next=third;
    second->prev=head;

    third->data=30;
    third->next=fourth;
    third->prev=third;

    fourth->data=40;
    fourth->next=NULL;
    fourth->prev=third;

    Traverse(head);
    head=DelBtw(head,2);
    printf("After deletion: \n");
    Traverse(head);
    return(0);
}