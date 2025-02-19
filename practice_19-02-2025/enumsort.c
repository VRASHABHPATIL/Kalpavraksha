#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum number
{
    ONE=1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN
}num;
typedef struct node
{
    num num1;
    struct node* next;
}node;

num stringtoenum(char str[])
{
    num temp;
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
    else if(strcmp(str,"five")==0)
    {
        temp=FIVE;
    }
    else if(strcmp(str,"six")==0)
    {
        temp=SIX;
    }
    else if(strcmp(str,"seven")==0)
    {
        temp=SEVEN;
    }
    return temp;
}

int main()
{
    char str[100];
    printf("Enter the number: ");
    scanf("%s",str);
    num temp=stringtoenum(str);
    printf("%d\n",temp);


}