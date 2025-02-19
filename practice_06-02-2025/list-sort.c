#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{   
    char name[100];
    int time;
    struct node* next;
}node;

node* create(char name[],int time)
{
    node* newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->name,name);
    newnode->time=time;
    newnode->next=NULL;
    return newnode;
}

void create_list(node** head,char name[],int time)
{
    node* newnode=create(name,time);
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

    if(left->time<=right->time)
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

node* mergersort(node** head)
{
    if(*head==NULL || (*head)->next==NULL)
    {
        return *head;
    }
    node* left=NULL;
    node* right=NULL;
    split(head,&left,&right);

    mergersort(&left);
    mergersort(&right);

    *head=merge(left,right);
}
void print(node** head)
{
    node* temp=*head;
    if(*head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%s %d\n",temp->name,temp->time);
            temp=temp->next;
        }
    }
}

int main()
{
    node* head=NULL;
    create_list(&head,"belagavi",1);
    create_list(&head,"mumbai",10);
    create_list(&head,"bgm",9);
    create_list(&head,"bengaluru",4);
    create_list(&head,"hello",3);
    create_list(&head,"temp",6);
    create_list(&head,"suzuki",5);

    print(&head);

    printf("after sorting\n");

    mergersort(&head);

    print(&head);


    
    return 0;
}