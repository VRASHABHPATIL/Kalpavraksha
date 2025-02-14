#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum number{
    ONE=1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
};

typedef struct queue
{
    enum number num;
    struct queue* next;
}queue;

queue* front=NULL;
queue* rare=NULL;

char* enumtochar(enum number num)
{
    if(num==ONE)
    {
        return "one";
    }
    else if(num==TWO)
    {
        return "two";

    }
    else if(num==THREE)
    {
        return "three";
        
    }
    else if(num==FOUR)
    {
        return "four";
        
    }
    else if(num==FIVE)
    {
        return "five";
        
    }
    else if(num==SIX)
    {
        return "six";
        
    }
    else if(num==SEVEN)
    {
        return "seven";
        
    }
    else if(num==EIGHT)
    {
        return "eight";
        
    }
    else if(num==NINE)
    {
        return "nine";
        
    }
    else
    {
        return "ten";
        
    }
}

enum number stringtoenum(char str[])
{
    enum number num;
    if(strcmp(str,"one")==0)
    {
        num=ONE;
    }
    else if(strcmp(str,"two")==0)
    {
        num=TWO;
    }
    else if(strcmp(str,"three")==0)
    {
        num=THREE;
    }
    else if(strcmp(str,"four")==0)
    {
        num=FOUR;
    }
    else if(strcmp(str,"five")==0)
    {
        num=FIVE;
    }
    else if(strcmp(str,"six")==0)
    {
        num=SIX;
    }
    else if(strcmp(str,"seven")==0)
    {
        num=SEVEN;
    }
    else if(strcmp(str,"eight")==0)
    {
        num=EIGHT;
    }
    else if(strcmp(str,"nine")==0)
    {
        num=NINE;
    }
    else
    {
        num=TEN;
    }
    return num;
    

}
queue* create(enum number num1)
{
    queue* new=(queue*)malloc(sizeof(queue));
    new->num=num1;
    new->next=NULL;
    return new;

}

queue* enqueue(enum number num)
{
    queue* new=create(num);
    if(front==NULL)
    {
        front=new;
        rare=new;
    }
    else if(front->num>new->num)
    {
        new->next=front;
        front=new;
    }
    else
    {
        queue* current=front;
        queue* prve=NULL;
        while(current!=NULL && current->num<new->num)
        {
            prve=current;
            current=current->next;
        }
        
        new->next=current;
        if(prve!=NULL)
        {
            prve->next=new;
        }

    }
}

queue* dequeue()
{
    queue* temp=front;
    front=front->next;
    printf("dequeued:%s\n",enumtochar(temp->num));
    free(temp);
}




void print()
{
    queue* temp=front;
    while(temp!=NULL)
    {
        printf("%s\t",enumtochar(temp->num));
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    enum number num; 
    char str[100];
    // printf("Enter the value for number: ");
    // scanf("%d",&n);
    // printf("Enter the string value:");
    // scanf("%s",str);
    // num=stringtoenum(str);

    enqueue(stringtoenum("six"));
    enqueue(stringtoenum("two"));
    enqueue(stringtoenum("four"));
    enqueue(stringtoenum("four"));
    enqueue(stringtoenum("one"));
    enqueue(stringtoenum("ten"));
    print();
    dequeue();
    dequeue();
    print();

    //printf("%d\n",num);
    
}
