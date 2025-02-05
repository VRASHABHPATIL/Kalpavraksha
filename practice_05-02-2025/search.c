#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node* createnode(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void create(node** head,int data)
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

void search(node** head, int key)
{
    int found=0;
    if(head==NULL)
    {
        printf("nothing is there to print here");
    }
    else
    {
        node* temp=*head;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                found=1;
            }
            temp=temp->next;
        }
    }
    if(found==1)
    {
        printf("element found\n");

    }
    else
    {
        printf("not found\n");
    }
}
int main()
{
    node* head=NULL;
    create(&head,10);
    create(&head,20);
    create(&head,30);
    create(&head,80);
    create(&head,100);
    create(&head,110);
    create(&head,130);
    create(&head,170);
    create(&head,90); 
    search(&head,90);

    return 0;
}
