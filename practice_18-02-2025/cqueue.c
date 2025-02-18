#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
typedef struct queue
{
    int data;
}queue;

queue q[maxsize];
int front=-1;
int rare=-1;

int isfull()
{
    if((rare+1)%maxsize==front)
    {
        return 1;
    }
    return 0;
}

void enqueue(int value)
{
    if(isfull())
    {
        printf("queue is full cannot enter %d\n",value);
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rare=(rare+1)%maxsize;
    q[rare].data=value;

}

void dequeue()
{
    if(front==-1)
    {
        printf("queue is empty.\n");
        return;
    }
    int dequeued=q[front].data;
    printf("dequeued: %d\n",dequeued);
    if(front==rare)
    {
        front=-1;
        rare=-1;
    }
    else
    {
        front=(front+1)%maxsize;
    }
}

void display()
{
    int temp=front;

    while(temp!=rare)
    {
        printf("%d\t",q[temp].data);
        temp=(temp+1)%maxsize;
    }
    printf("%d\n",q[rare].data);
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
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
    return 0;
}

