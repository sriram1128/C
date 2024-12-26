#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr)
{
    struct Node *p=ptr;
    do
    {
        printf("The element is: %d\n",p->data);
        p=p->next;
    }while(p!=ptr);
}

struct Node*delend(struct Node*ptr)
{
    struct Node *p=ptr;
    struct Node *q=ptr->next;
    while(q->next!=ptr)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return ptr;
    
}

int main()
{
    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;

    head=(struct Node*)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct Node*));
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
    head=delend(head);
    printf("After deletion of the node:\n");
    Traversal(head);

    return(0);
}