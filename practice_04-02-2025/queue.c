#include<stdio.h>
#include<string.h>
#define SIZE 10

typedef struct node
{
    char document[100];
    int pages;
}node;

int front=-1;
int rare=-1;
node queue[SIZE];

void enqueue(char document[],int pages)
{
    if(rare==(SIZE-1))
    {
        printf("Queue full");
    }
    else
    {
        if(front==-1)
        {
            front=front+1;
        }
        rare=rare+1;
        strcpy(queue[rare].document,document);
        queue[rare].pages=pages;
    }
}

node dequeue()
{
    if(front>rare || front==-1)
    {
        printf("underflow..!");
    }
    node a=queue[front];
    front=front+1;
    return a;
     
}

void peak()
{
    printf("%s\t",queue[front].document);
    printf("%d",queue[front].pages);
    printf("\n");
    
}

int main()
{
    enqueue("test1",100);
    enqueue("test2",200);
    enqueue("test3",300);
    enqueue("test4",400);
    enqueue("test5",500);
    peak();
}

    


