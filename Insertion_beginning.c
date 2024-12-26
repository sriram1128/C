#include<stdio.h>
#include<stdlib.h>
//Here we give data and next because they are the elements present in the linked list.
struct Node   //defining the structure to define the nodes 
{
    int data;    //data variable of the node 
    struct Node *next;  //pointer to parse through the nodes 
};
void Traverse(struct Node *ptr)  //method to parse through nodes 
{
    while (ptr!=NULL)
    {
        printf("Element: %d \n",ptr->data);
        ptr=ptr->next;
    }  
}
struct Node *InsertBeg(struct Node *ptr,int data)   //method to insert nodes in begining 
{
    struct Node *p;
    p=(struct Node *)malloc(sizeof(struct Node*));
    p->data=data;
    p->next=ptr;
    return p;
}
int main()   //main method 
{
    struct Node *head;  
    struct Node *second;
    struct Node *third;

    //memory allocation for head second and third 
    head=(struct Node *)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct Node*));

    //adding the data and next values to the head 
    head->data=10;
    head->next=second;

    //adding the data and next values to the second 
    second->data=20;
    second->next=third;

    //adding the data and next values to the third
    third->data=30;
    third->next=NULL;

   //calling the traverse method with head as parameter
    Traverse(head);
    //inserting a new node at begning 
    head=InsertBeg(head,50);

    //prnting the list after insertion at begining 
    printf("After insertion of element in the beginning:\n");
    Traverse(head);
    return(0);
}
