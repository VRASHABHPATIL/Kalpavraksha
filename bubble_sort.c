#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int score;
	char name[100];
	struct node* next;
};

struct node* create(int score, char *name)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	strcpy(newnode->name,name);
	newnode->score=score;
	newnode->next=NULL;
	return newnode;
}

struct node* createList(struct node** head,int score, char *name)
{
	struct node* newnode=create(score,name);
	struct node* temp=*head;
	
	if(*head==NULL)
	{
		*head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

struct node* print(struct node** head)
{
	struct node* temp=*head;
	while(temp!=NULL)
	{
		printf("%d",temp->score);
		printf("\t");
		printf("%s",temp->name);
		printf("\n");
		temp=temp->next;
	}
}


void sort(struct node** head)
{
	int swapped=1;
    	struct node* ptr1;
        struct node* lptr = NULL;

   
    	if (*head == NULL)
    	{
        	return;
        }

    	while(swapped) 
    	{
        	swapped = 0;
        	ptr1 = *head;

        	while (ptr1->next != lptr) 
        	{
            		if (ptr1->score < ptr1->next->score) 
            		{
                
                		int temp_score = ptr1->score;
                		char temp_name[10];
                		strcpy(temp_name, ptr1->name);

                		ptr1->score = ptr1->next->score;
                		strcpy(ptr1->name, ptr1->next->name);

                		ptr1->next->score = temp_score;
                		strcpy(ptr1->next->name, temp_name);

                		swapped = 1;
            		}
            		ptr1 = ptr1->next;
           	}
        	lptr = ptr1;
   	 }
}


void main()
{
	struct node* head=NULL;
	int n,i,score;
	char name[10];
	printf("Enter the number of players :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the name of player%d: ",i);
		scanf("%s",name);
		printf("Enter the score scored: ");
		scanf("%d",&score);
		createList(&head,score,name);
	
	}
	
	printf("Players list before soting\n");
	print(&head);
	sort(&head);
	printf("Players list after soting\n");
	print(&head);
}

