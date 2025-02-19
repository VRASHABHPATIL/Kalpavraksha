#include<stdio.h>
#include<stdlib.h>
#define size 5
struct node
{
    int data;
};
struct node cqueue[size];
int front=-1;
int rear=-1;

void enqueue(int data)
{
    if((rear+1)%size==front)
    {
        printf("Queue is full can not enter value %d.\n",data);
        return;
    
    }
    if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%size;
    cqueue[rear].data=data;
    
}
void dequeue()
{
    if(front==-1)
    {
        printf("queue is empty.\n");
        return;
    }
    printf("dequeud: %d\n",cqueue[front].data);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
    
}
void display()
{
    if(front==-1)
    {
        printf("nothing to print.\n");
        return;
    }
    // if(front==rear)
    // {
    //     printf("%d\t",cqueue[front].data);
    //     return;
    // }
    int temp=front;
    while(temp!=rear)
    {
        printf("%d\t",cqueue[temp].data);
        temp=(temp+1)%size;
    }
    printf("%d\n",cqueue[rear].data);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    display();
    dequeue();
    display();   
    display();
    dequeue();
    display();
    return 0;
}