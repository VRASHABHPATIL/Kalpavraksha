#include<stdio.h>
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
    node* new=create(data);
    if(*head==NULL)
    {
        *head=new;
    }
    else{
        node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}

node* removenode(node** head,int k,int n)
{
    
    if(*head==NULL)
    {
        printf("nothing to delete.\n");
    }
    else
    {
        
        if(k==n)
        {
            node* temp=*head;
            *head=(*head)->next;
            free(temp);
        }
        else
        {
            
            int val=n-k;
            node* temp=*head;
            while(val>1)
            {
                temp=temp->next;
                val=val-1;
        

            }
            
            node* temp1=temp->next;
            
            temp->next=temp1->next;
            free(temp1);

        }
        
    }
}
void print(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    node* head=NULL;
    int n,i;
    printf("Enter thye value for n: ");
    scanf("%d",&n);
    int temp;
    for(i=0;i<n;i++)
    {
        printf("Enter the data for %d :",i);
        scanf("%d",&temp);
        create_list(&head,temp);
    }
    print(&head);
    removenode(&head,1,5);
    print(&head);

}