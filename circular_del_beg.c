
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
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

struct Node *Delbeg(struct Node*ptr)
{
    struct Node*p=ptr;
    while(p->next!=ptr)
    {
        p=p->next;
    }
    struct Node *q=ptr->next;
    p->next=q;
    free(ptr);
    return q;

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

    Traverse(head);
    head=Delbeg(head);
    printf("After deletion of 1st node:\n");
    Traverse(head);
    return(0);
}