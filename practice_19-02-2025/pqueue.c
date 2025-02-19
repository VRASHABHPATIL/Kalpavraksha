#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define qsize 5
typedef struct node
{
    int data;
    struct node* next;
}node;
int size(node** head)
{
    int count=0;
    node* temp=*head;
    while(temp!=NULL)
    {
        count=count+1;
        temp=temp->next;
    }
    return count;
}
node* create(int data)
{
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}
node* enqueue(node** head,int data)
{
    if(size(head)==qsize)
    {
        printf("queue is full can not enter %d.\n",data);
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
        node* prve=NULL;
        while(temp!=NULL && temp->data<newnode->data)
        {
            prve=temp;
            temp=temp->next;
        } 
        if(prve!=NULL)
        {
            prve->next=newnode;
            newnode->next=temp;
        }
        else
        {
            newnode->next=*head;
            *head=newnode;
        }
        
    }

}
node* dequeue(node** head)
{
    if(*head==NULL)
    {
        printf("queue is empty.\n");
        return NULL;
    }
    // if((*head)->next==NULL)
    // {
    //     printf("dequeued: %d\n",(*head)->data);
    //     *head=NULL;
    //     return NULL;
    // }
    printf("dequeued: %d\n",(*head)->data);
    node* temp=*head;
    *head=(*head)->next;
    free(temp);
}
void display(node** head)
{
    if(*head==NULL)
    {
        printf("queue is empty to print.\n");
        return ;
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
    node* front=NULL;
    node* rear=NULL;

    enqueue(&front,100);
    enqueue(&front,90);
    enqueue(&front,80);
    enqueue(&front,40);
    enqueue(&front,60);
    enqueue(&front,50);
    enqueue(&front,120);
    display(&front);
    dequeue(&front);
    display(&front);
    dequeue(&front);
    display(&front);
    dequeue(&front);
    display(&front);
    dequeue(&front);
    display(&front);
    dequeue(&front);
    display(&front);
    dequeue(&front);
    display(&front);
    enqueue(&front,50);
    enqueue(&front,120);
    enqueue(&front,20);
    display(&front);
    return 0;
}