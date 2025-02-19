#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* create(int data)
{
    node* new=(node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    return new;
}

node* create_list(node** head,int data)
{
    node* newnode=create(data);
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    //printf("creadted\n");
}

node* delete(node** head)
{
    node* temp=*head;
    if(temp==NULL)
    {
        printf("nothing to delete\n");

    }
    else if(temp->next==NULL)
    {
        printf("deleted: %d\n",temp->data);
        free(temp);
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf("removed bookmark %d\n",(temp->next)->data);
        node* temp1=temp->next;
        temp->next=NULL;
        free(temp1);

    }

}
void priority(node** head,int data)
{
    node* new=create(data);
    if(*head==NULL || (*head)->data > new->data)
    {
        new->next=*head;
        *head=new;
    }
    else
    {
        node* temp=*head;
        node* prve=NULL;
        while(temp!=NULL)
        {
            if(temp->data<new->data)
            {
                prve=temp;
                temp=temp->next;
            }
            else
            {
                break;
            }
            
        }
        if(prve!=NULL)
        {
            prve->next=new;
            new->next=temp;
        }
    }

}
void display(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;

    }
    printf("\n");
}

int main()
{
    node* head=NULL;

    int n,i;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char str[100];
    
        printf("Enter the string: ");
        scanf("%[^\n]%*c", str);
        
        char *token = strtok(str, "\"<>");
    
       // printf("%s\n", token);
        if(strcmp(token,"BOOKMARK")==0)
        {
            while (token != NULL)
            {
                token = strtok(NULL, "\"<>");
                if (token != NULL)
                {
                    int a= atoi(token);
                    create_list(&head,a);
                }
                    
            }

        }
        else if(strcmp(token,"DELETE")==0)
        {
            delete(&head);
        }
        else if(strcmp(token,"LIST")==0)
        {
            node* head1=NULL;
            node*temp=head;
            while(temp!=NULL)
            {
                priority(&head1,temp->data);
                temp=temp->next;
            }
            display(&head1);
        }
    
        

    }

    //  create_list(&head,10);
    //  create_list(&head,20);
    //  create_list(&head,30);
    //  display(&head);
    //  delete(&head);
    //  display(&head);

    return 0;
}
