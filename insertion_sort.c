#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct task
{
	int priority;
	struct task* next;
};

struct task* create(int priority)
{
	struct task* newnode=(struct task*)malloc(sizeof(struct task));
	newnode->priority=priority;
	newnode->next=NULL;
	return newnode;
}

struct task* createList(struct task** head,int priority)
{
	struct task* newnode=create(priority);
	struct task* temp=*head;
	
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

struct task* print(struct task** head)
{
	struct task* temp=*head;
	while(temp!=NULL)
	{
		printf("%d",temp->priority);
		printf("\n");
		
		temp=temp->next;
	}
}

void sort(struct task** head) 
{
	    if (*head == NULL || (*head)->next == NULL) 
	    {
		return;
	    }
	    
	    struct task* sorted = NULL;
	    struct task* current = *head;
	    
	    while (current != NULL) 
	    {
		struct task* next = current->next;
		
		if (sorted == NULL || sorted->priority > current->priority) 
		{
		    current->next = sorted;
		    sorted = current;
		} 
		else 
		{
		    struct task* temp = sorted;
		    while (temp->next != NULL && temp->next->priority <= current->priority) 
		    {
		        temp = temp->next;
		    }
		    current->next = temp->next;
		    temp->next = current;
		}
		
		current = next;
	    }
	    
	    *head = sorted;
}


void main()
{
	struct task* head=NULL;
	int n,i,priority;
	
	printf("Enter the number of tasks :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the task %d's priority: ",i);
		scanf("%d",&priority);
		createList(&head,priority);
	
	}
	
	printf("task list before soting\n");
	print(&head);
	sort(&head);
	printf("task list after soting\n");
	print(&head);
}
