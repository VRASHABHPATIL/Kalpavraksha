#include<stdio.h>
#include<string.h>

typedef struct node
{
    char a[100];
}node;
node q[100];
int front=-1;
int rare=-1;

void enqueue(node n1)
{
    
    if(front>rare)
    {
        printf("queue overflow\n");
    }
    if(front==-1)
    {
        front=0;
    }

    rare=rare+1;
    strcpy(q[rare].a,n1.a);
    
}

node dequeue()
{
    node s=q[front];
    if(front==-1)
    {
        printf("stack underflow\n");
    }
    if(front==rare)
    {
        front=-1;
        rare=-1;
    }
    else
    {
        front=front+1;
    }
    return s;

}
void peak()
{
    printf("%s\n",q[front].a);
}
int main()
{
    node n;
    printf("enter the value to be inserted: ");
    scanf("%s",n.a);
    enqueue(n);
    printf("enter the value to be inserted: ");
    scanf("%s",n.a);
    enqueue(n);
    printf("enter the value to be inserted: ");
    scanf("%s",n.a);
    enqueue(n);
    // node c=dequeue();
    // node d=dequeue();
    // printf("%s\n",c.a);
    // printf("%s\n",d.a);


    //changing the perticular element

    int temp_rear=rare;
    int flag=0;
    while(front!=temp_rear+1)
    {
        node n2=dequeue();
        
        if(strcmp(n2.a,"hello1")==0)
        {
            strcpy(n2.a,"hello10");
            flag=1;
        }
        
        enqueue(n2);
    }
    if(flag==0)
    {
        printf("value not found and not updated\n");
        
    }
    else
    {
        printf("value found and updated\n");
    }
    peak();

}

