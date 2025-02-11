#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum number
{
    ONE=1,
    TWO,
    THREE,
    FOUR,
    FIVE
};
typedef struct node
{
    enum number num;
    struct node* next;   
}node;


node* create(enum number num1)
{
    node* new=(node*)malloc(sizeof(node));
    new->num=num1;
    new->next=NULL;
    return new;

}

node* create_list(node** head,enum number num)
{
    node* new=create(num);
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}
enum number map(char str[])
{
    enum number temp;
    if(strcmp(str,"one")==0)
    {
        temp=ONE;
    }
    else if(strcmp(str,"two")==0)
    {
        temp=TWO;
    }
    else if(strcmp(str,"three")==0)
    {
        temp=THREE;
    }
    else if(strcmp(str,"four")==0)
    {
        temp=FOUR;
    }
    else
    {
        temp=FIVE;
    }

    return temp;
}

char* mapenumtochar(enum number num)
{
    
    if(num==1)
    {
        return "one";
    }
    else if(num==2)
    {
        return "two";
    }
    else if(num==3)
    {
        return "three";
    }
    else if(num==4)
    {
        return "four";
    }
    else
    {
        return "five";
    }

}

void print(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%s\n",mapenumtochar(temp->num));
        temp=temp->next;
    }
}
int main()
{
    node* head=NULL;
    char str[100];
    int n=5;

    while(n!=0)
    {
        printf("enter the number between1-5in string: ");
        scanf("%s",str);
        enum number num=map(str);
        create_list(&head,num);
        n=n-1;

    }

    print(&head);
}