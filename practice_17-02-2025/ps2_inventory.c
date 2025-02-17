#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char item[100];
    int quantity;
    struct node* next;
}node;

node* create(char item[],int quantity )
{
    node* new=(node*)malloc(sizeof(node));
    strcpy(new->item,item);
    new->quantity=quantity;
    new->next=NULL;
    return new;
}
node* search(node* head,char item[])
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->item,item)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
node* create_list(node** head,char item[],int quantity)
{
    node* newnode=create(item,quantity);
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        node* temp=search(*head,item);
        if(temp==NULL)
        {
            node* temp1=*head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;

            }
            temp1->next=newnode;
        }
        else
        {
            temp->quantity=newnode->quantity;
        }

    }
}
void display(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%s\t%d\n",temp->item,temp->quantity);
        temp=temp->next;
    }
}
int main()
{
    node* head=NULL;
    // create_list(&head,"hello",1);
    // create_list(&head,"hello",10);
    // create_list(&head,"hello",12);
    // create_list(&head,"hello1",1);
    // create_list(&head,"hello2",1);
    // display(&head);

    int i,n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char str[100];
    
        printf("Enter the command: ");
        scanf("%[^\n]%*c", str);
        
        char *token = strtok(str, "\"<>");
    
       // printf("%s\n", token);
        if(strcmp(token,"ADD")==0)
        {
            char item[100];
            int quantity;
            token=strtok(NULL,"\"<>");
            strcpy(item,token);
            token=strtok(NULL,"\"<>");
            quantity=atoi(token);
            create_list(&head,item,quantity);
        }
        else if(strcmp(token,"UPDATE")==0)
        {
            char item[100];
            int quantity;
            token=strtok(NULL,"\"<>");
            strcpy(item,token);
            token=strtok(NULL,"\"<>");
            quantity=atoi(token);
            create_list(&head,item,quantity);
        }
        else if(strcmp(token,"QUERY")==0)
        {
            token=strtok(NULL,"\"<>");
            node* temp=search(head,token);
            if(temp!=NULL)
            {
                printf("FOUND\n");
            }
            else
            {
                printf("NOT-FOUND\n");
            }
        }
        else if(strcmp(token,"DISPLAY")==0)
        {
            display(&head);
        }
    
    }

    return 0;
}