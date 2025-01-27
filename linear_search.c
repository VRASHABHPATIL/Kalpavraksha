#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Customer 
{
    int id;
    char name[50];
    struct Customer* next;
};

struct Customer* create(int id, char* name) 
{
    struct Customer* newnode = (struct Customer*)malloc(sizeof(struct Customer));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}

void createList(struct Customer** head, int id, char* name) 
{
    struct Customer* newnode = create(id, name);
    struct Customer* temp = *head;
    if (*head == NULL) 
    {
        *head = newnode;
    } 
    else 
    {
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void print(struct Customer* head) 
{
    struct Customer* temp = head;
    while (temp != NULL) 
    {
        printf("Customer ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

struct Customer* linearSearch(struct Customer* head, int searchId) 
{
    struct Customer* current = head;
    while (current != NULL) 
    {
        if (current->id == searchId) 
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeList(struct Customer* head) 
{
    struct Customer* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    struct Customer* head = NULL;
    int n, i, id, searchId;
    char name[50];

    printf("Enter the number of customers: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter customer ID for customer %d: ", i + 1);
        scanf("%d", &id);
        printf("Enter name for customer %d: ", i + 1);
        scanf(" %[^\n]s", name);
        createList(&head, id, name);
    }

    printf("\nCustomer Database:\n");
    print(head);

    printf("\nEnter customer ID to search: ");
    scanf("%d", &searchId);

    struct Customer* result = linearSearch(head, searchId);
    if (result != NULL) 
    {
        printf("Customer found! ID: %d, Name: %s\n", result->id, result->name);
    } 
    else 
    {
        printf("Customer with ID %d not found.\n", searchId);
    }

    freeList(head);
    return 0;
}