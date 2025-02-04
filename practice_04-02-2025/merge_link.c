#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

node* remove_duplicates(node** head)
{
    if (*head==NULL || (*head)->next==NULL)
    {
        return NULL;
    }  
    node* temp=*head;
    node* temp1=NULL;
    while (temp!=NULL && temp->next!=NULL)  
    {
        temp1=temp->next;
        while (temp1!=NULL)  
        {
            if (temp->data == temp1->data)  
            {
                temp->next=temp1->next; 
                free(temp1);
                temp1=temp->next;  
            }
            else
            {
                temp1=temp1->next;  
            }
        }
        temp=temp->next;  
    }   
}

node* createnode(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;

}

void createlist(node** head,int data)
{
    node* newnode=createnode(data);
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void split(node** head,node** left,node** right)
{
    node* slow=*head;
    node* fast=(*head)->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    *left=*head;
    *right=slow->next;
    slow->next=NULL;

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
    node* result=NULL;
    if(left->data<=right->data)
    {
        result=left;
        result->next=merge(left->next,right);
    }
    else
    {
        result=right;
        result->next=merge(left,right->next);
    }
    return result;
}

node* mergesort(node** head)
{
    if(*head==NULL||(*head)->next==NULL)
    {
        return *head;
    }
    node *left,*right;
    split(head,&left,&right);

    mergesort(&left);
    mergesort(&right);
    *head=merge(left,right);
}
void printlist(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    node* head=NULL;
    createlist(&head,20);
    createlist(&head,10);
    createlist(&head,10);
    createlist(&head,10);
    createlist(&head,1);
    createlist(&head,11);
    printf("original list\n");
    printlist(&head);

    mergesort(&head);

    printf("Sorted list:\n");
    printlist(&head);

    printf("sorted after removal of duplicates\n");
    remove_duplicates(&head);

    printlist(&head);
}