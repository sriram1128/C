#include<stdio.h>
#include<stdlib.h>

struct Node 
{
int data;
struct Node *next;
};
void Traverse(struct Node *ptr)
{
    while(ptr!=NULL)
   {
        printf("The element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node *InsertBetween(struct Node *ptr,int data,int pos)
{
    struct Node *q;
    q=ptr;
    int i=0;
    while(i!=pos-1)
    {
        q=q->next;
        i++;
    }
    struct Node*p;
    p=(struct Node*)malloc(sizeof(struct Node*));
    p->data=data;
    p->next=q->next;
    q->next=p;
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

    third->data=40;
    third->next=NULL;

    Traverse(head);
    head=InsertBetween(head,30,2);
    printf("After insertion of node in between:\n");
    Traverse(head);
    return(0);
}