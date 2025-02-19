#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5
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

int stack_size(node** head)
{
    int count=0;
    node* temp=*head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count=count+1;
    }
    return count;

}
node* push(node** head,int data)
{
    if(stack_size(head)==size)
    {
        printf("stck is full canot enter value %d.\n",data);
        return NULL;
    }
    node* newnode=create(data);
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
node* pop(node** head)
{
    if(*head==NULL)
    {
        printf("Stack is empty.\n");
        return NULL;
    }
    if((*head)->next==NULL)
    {
        printf("Popped: %d\n",(*head)->data);
        *head=NULL;
        return NULL;
    }
    node*prve=NULL;
    node* temp=*head;
    while(temp->next!=NULL)
    {
        prve=temp;
        temp=temp->next;
    }
    printf("Popped: %d\n",temp->data);
    if(prve!=NULL)
    {
        prve->next=NULL;
        
    }
    free(temp);
    
    
}
void display(node** head)
{
    if(*head==NULL)
    {
        printf("nothing is there to printe in the stack.\n");
        return;
    }
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    node* head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    push(&head,60);
    push(&head,70);
    display(&head);
    pop(&head);
    display(&head);
    pop(&head);
    display(&head);
    pop(&head);
    display(&head);
    pop(&head);
    display(&head);
    pop(&head);
    display(&head);
    pop(&head);
    display(&head);
    return 0;
}
