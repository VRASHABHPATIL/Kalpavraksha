#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product
{
	int price;
	char name[100];
	struct product* next;
};

struct product* create(int price, char *name)
{
	struct product* newnode=(struct product*)malloc(sizeof(struct product));
	strcpy(newnode->name,name);
	newnode->price=price;
	newnode->next=NULL;
	return newnode;
}

struct product* createList(struct product** head,int price, char *name)
{
	struct product* newnode=create(price,name);
	struct product* temp=*head;
	
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

struct product* print(struct product** head)
{
	struct product* temp=*head;
	while(temp!=NULL)
	{
		printf("%d",temp->price);
		printf("\t");
		printf("%s",temp->name);
		printf("\n");
		temp=temp->next;
	}
}

void sort(struct product** head) 
{
	    struct product *ptr1, *ptr2, *min;
	    
	    if (*head == NULL) 
	    {
	    	return;
	    }
	    
	    ptr1 = *head;
	    while(ptr1 != NULL) 
	    {
		min = ptr1;
		ptr2 = ptr1->next;
		
		while(ptr2 != NULL) 
		{
		    if(ptr2->price < min->price) 
		    {
		        min = ptr2;
		    }
		    ptr2 = ptr2->next;
		}
		
		if(min != ptr1) 
		{
		    int temp_price = ptr1->price;
		    ptr1->price = min->price;
		    min->price = temp_price;
		    
		    char temp_name[10];
		    strcpy(temp_name, ptr1->name);
		    strcpy(ptr1->name, min->name);
		    strcpy(min->name, temp_name);
		}
		
		ptr1 = ptr1->next;
	    }
}


void main()
{
	struct product* head=NULL;
	int n,i,score;
	char name[10];
	printf("Enter the number of products :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the name of product%d: ",i);
		scanf("%s",name);
		printf("Enter the price: ");
		scanf("%d",&score);
		createList(&head,score,name);
	
	}
	
	printf("Products list before soting\n");
	print(&head);
	sort(&head);
	printf("Products list after soting\n");
	print(&head);
}
