#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    
    int data;
    struct node* next;
}node;

node* create(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void push(node** top,int data)
{
    node* newnode=create(data);
    newnode->next=*top;
    *top=newnode;

}

int pop(node** top)
{
    
    if(*top==NULL)
    {
        printf("nothing is there to pop here\n");
    }
    else
    {
        int data=(*top)->data;
        *top=(*top)->next;
        return data;
    }
}

void peak(node** top)
{
    printf("%d\n",(*top)->data);
}

int main()
{
    node* top=NULL;
    push(&top,10);
    push(&top,20);
    push(&top,50);
    push(&top,40);
    push(&top,30);
    push(&top,20);

    int data;
    data=pop(&top);
    printf("%d\n",data);
    data=pop(&top);
    printf("%d\n",data);
    data=pop(&top);
    printf("%d\n",data);
    data=pop(&top);
    printf("%d\n",data);

    return 0;
}