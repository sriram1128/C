



#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node*ptr)
{
    while(ptr != NULL)
    {
        printf("Element is: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node *Delete_beg(struct Node *ptr)
{
    struct Node *p=ptr;
    ptr=ptr->next;
    free(p);
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

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
    fourth->next=NULL;

    Traverse(head);
    head=Delete_beg(head);
    printf("After deletion of the first node:\n");
    Traverse(head);
    return(0);
}