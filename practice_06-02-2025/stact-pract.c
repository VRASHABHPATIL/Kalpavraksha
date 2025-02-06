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

node* push(node** top,int data)
{
    node*new=create(data);
    new->next=*top;
    *top=new;

}
int pop(node** top)
{
    if(*top==NULL)
    {
        printf("nothing to pop\n");

    }
    else
    {
        int data=(*top)->data;
        *top=(*top)->next;
        return data;
    }
}

void print(node** top)
{
    node* temp=*top;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    node* top=NULL;
    push(&top,10);
    push(&top,20);
    push(&top,30);
    push(&top,40);
    push(&top,50);
    push(&top,60);

    print(&top);

    return 0;
}