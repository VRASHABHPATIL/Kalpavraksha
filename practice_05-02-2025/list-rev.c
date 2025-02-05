#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    return newnode;
}

struct node* create_list(struct node** head,int data)
{
    struct node* newnode=createnode(data);
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        struct node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

struct node* revloop(struct node** head)
{
    struct node* prve=NULL;
    struct node* next=NULL;
    struct node* current=*head;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prve;
        prve=current;
        current=next;
    }
    *head=prve;
}

struct node* revrecurssion(struct node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;

    }
    struct node* rest=revrecurssion(head->next);

    head->next->next=head;
    head->next=NULL;

    return rest;

}

void print(struct node** head)
{
    struct node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct node* head=NULL;
    create_list(&head,10);
    create_list(&head,20);
    create_list(&head,30);
    create_list(&head,40);
    create_list(&head,50);
    create_list(&head,60);
    create_list(&head,70);

    print(&head);
    revloop(&head);
    print(&head);
    head=revrecurssion(head);
    print(&head);
    return 0;

}