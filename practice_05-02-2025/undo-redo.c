#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node 
{
    char data;
    struct node* next;
} node;

node* createNode(char data)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void push(node** top, char data) 
{
    node* newNode=createNode(data);
    newNode->next=*top;
    *top=newNode;
}

char pop(node** top) 
{
    if (*top == NULL) 
    {
        printf("Stack is empty Nothing to pop.\n");
        return '\0';
    }
    
    node* temp = *top;
    char poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

char peek(node* top) 
{
    if (top == NULL) 
    {
        printf("Stack is empty Nothing to peek.\n");
        return '\0';
    }
    return top->data;
}


void printStack(node* top) 
{
    char str[100];
    int i=0;
    if (top == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    
    node* temp = top;
    printf("Stack: ");
    while (temp != NULL) 
    {
        str[i]=temp->data;
        temp = temp->next;
        i=i+1;
    }
    for(i=strlen(str);i>=0;i--)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}

int main() 
{
    int i;
    node* top1 = NULL;
    node* top2 = NULL;
    char str[100];

    printf("enter the input: ");
    scanf("%s",str);

    for(i=0;i<strlen(str);i++)
    {
        push(&top1,str[i]);
    }
    char ch;
    getchar();
    printf("Enter z for undo y for redo and e for exit\n");

    while(1)
    {
        printf("enter your choice:");
        scanf("%c",&ch);
        getchar();

        switch(ch)
        {
            case 'z':
                printf("undo operation.\n");
                char a=pop(&top1);
                push(&top2,a);
                printStack(top1);
                break;

            case 'y':
                printf("redo operation.\n");
                char b=pop(&top2);
                push(&top1,b);
                printStack(top1);
                break;
            case 'e':
                exit(0);
            default:
                printf("invalid entry\n");


        }
    }


    return 0;
}
