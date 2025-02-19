#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* create(int data)
{
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}
node* create_list(node** head,int data)
{
    node* new=create(data);
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}

void print(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
node* merge(node* left,node* right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    node* res=NULL;
    if(left->data<=right->data)
    {
        res=left;
        res->next=merge(left->next,right);
    }
    else
    {
        res=right;
        res->next=merge(left,right->next);
    }
    return res;
}
node* split(node** head,node** left,node** right)
{
    node* slow=*head;
    node* fast=(*head)->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    *left=*head;
    *right=slow->next;
    slow->next=NULL;
}
node* mergesort(node** head)
{
    if(*head==NULL || (*head)->next==NULL)
    {
        return *head;
    }
    node* left=NULL;
    node* right=NULL;
    split(head,&left,&right);
    mergesort(&left);
    mergesort(&right);
    *head=merge(left,right);
}

int main()
{
    node* head=NULL;
    create_list(&head,90);
    create_list(&head,80);
    create_list(&head,70);
    create_list(&head,40);
    create_list(&head,50);
    create_list(&head,60);
    print(&head);
    mergesort(&head);
    print(&head);
    
}