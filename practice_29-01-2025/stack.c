#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

node* createnode(int data)
{
     node* newnode=(node*)malloc(sizeof(node));
     newnode->next=NULL;
     newnode->data=data;
     return newnode; 
}
node* push(node** head, int data)
{
    
    node* newnode=createnode(data);
    node* temp=*head;
    if(*head==NULL)
    {
        (*head)=newnode;
        
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

node* pop(node** head)
{
    node* temp=*head;
    node* previous=NULL;
    if(*head==NULL)
    {
        printf("There is nothing to delete in stack");
        return NULL;
    }

    if((*head)->next==NULL)
    {
        *head=NULL;
        return NULL;
    }
  
    while(temp->next->next!=NULL)
    {
            
        temp=temp->next;
    }
    temp->next=NULL;
        

}

node* print(node** head)
{
    node* temp=*head;
    if((*head)==NULL)
    {
        printf("nothing is there to print in the stack\n");
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
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    print(&head);
    pop(&head);
    print(&head);
    pop(&head);
    print(&head);
    pop(&head);
    print(&head);
    pop(&head);
    print(&head);
    push(&head,40);
    print(&head);
    return 0;
}