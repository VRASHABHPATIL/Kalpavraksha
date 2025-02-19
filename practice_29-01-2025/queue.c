#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->data=data;
    return newnode;
}
node* enqueue(node** head,int data)
{
    node* newnode=create(data);
    node* temp=*head;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

node* dequeue(node** head)
{
    if(*head==NULL)
    {
        printf("Nothing is there to print\n");
        return NULL;
    }
    if((*head)->next==NULL)
    {
        *head=NULL;
        return NULL;
    }

    node* temp=*head;
    *head=(*head)->next;
    free(temp);
}

node* print(node** head)
{
    node* temp=*head;
    if(*head==NULL)
    {
        printf("nothing is there to print here\n");
        return NULL;
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;

        }
        printf("\n");

    }
}

int main()
{
    node* head=NULL;
    enqueue(&head,10);
    enqueue(&head,20);
    enqueue(&head,30);
    enqueue(&head,40);
    
    print(&head);
    dequeue(&head);
    print(&head);
    dequeue(&head);
    print(&head);
    dequeue(&head);
    print(&head);
    dequeue(&head);
    print(&head);
    return 0;
}

