#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
typedef struct booking
{
    char movie_name[100];
    int screen_number;
    int amount;
    int seat_number;
    char status;
    struct booking* next;

}booking;
 booking* front1=NULL;
 booking* rare1=NULL;
 booking* front2=NULL;
 booking* rare2=NULL;
 booking* createnode(char movie_name[],int screen_number,int amount,int seat_number)
 {
     booking* newnode=(booking*)malloc(sizeof(booking));
     strcpy(newnode->movie_name,movie_name);
     newnode->screen_number=screen_number;
     newnode->amount=amount;
     newnode->seat_number=seat_number;
     newnode->status='p';
     newnode->next=NULL;
     return newnode;

 }

 void book(char movie_name[],int screen_number,int amount,int seat_number)
 {
    booking* newnode=createnode(movie_name,screen_number,amount,seat_number);
    if(rare1==NULL)
    {
        front1=newnode;
        rare1=newnode;
    }
    else
    {
        rare1=rare1->next;
        rare1=newnode;

    }
 }

 booking* approve()
 {
    if(front1==NULL||front1==rare1)
    {
        printf("no elements are there in the queue.");
    }
    else
    {
        booking* newnode=createnode(front1->movie_name,front1->screen_number,front1->amount,front1->seat_number);
        if(rare2==NULL)
        {
            front2=newnode;
            rare2=newnode;
        }
        else
        {
            rare2=rare2->next;
            rare2=newnode;

        }

    }
    booking* temp=front1;
    front1=front1->next;
    free(temp);
 }

 void printbooking(booking* temp)
 {
    while(temp!=NULL)
    {
        printf("%s\n",temp->movie_name);
        temp=temp->next;
    }
 }

 int main()
 {

    char movie_name[100];
    int screen_number,amount,seat_number;
    int choice;
    
    while(1)
    {
        printf("Enter case:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the movie name :");
            scanf("%s",movie_name);
            printf("enter the screen number :");
            scanf("%d",&screen_number);
            printf("enter the ammount :");
            scanf("%d",&amount);
            printf("enter the seat number :");
            scanf("%d",&seat_number);
            book(movie_name,screen_number,amount,seat_number);
            break;

            case 2:
                approve();
                break;
            case 3:
                printbooking(front1);
                break;
            case 4:
                printbooking(front2);
                break;
            default:
                printf("Invalid entry.\n");
                break;
        }
    }
    
    

    return 0;
 }
