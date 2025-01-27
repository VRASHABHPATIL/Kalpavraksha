#include<stdio.h>
#include<stdlib.h>

struct Product 
{
    int id;
    struct Product* next;
};

struct Product* create(int id) 
{
    struct Product* newnode = (struct Product*)malloc(sizeof(struct Product));
    newnode->id = id;
    newnode->next = NULL;
    return newnode;
}

void appendProduct(struct Product** head, int id) 
{
    struct Product* newnode = create(id);
    if (*head == NULL) 
    {
        *head = newnode;
    } 
    else 
    {
        struct Product* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void print(struct Product* head) 
{
    struct Product* temp = head;
    while (temp != NULL) 
    {
        printf("Product ID: %d\n", temp->id);
        temp = temp->next;
    }
}

int getCount(struct Product* head) 
{
    int count = 0;
    struct Product* temp = head;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct Product* getMiddleNode(struct Product* start, int position) 
{
    struct Product* temp = start;
    for(int i = 0; i < position; i++) 
    {
        if(temp == NULL) return NULL;
        temp = temp->next;
    }
    return temp;
}

struct Product* binarySearch(struct Product* head, int searchId) 
{
    int left = 0;
    int right = getCount(head) - 1;
    struct Product* start = head;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        struct Product* midNode = getMiddleNode(start, mid);

        if (midNode->id == searchId) 
        {
            return midNode;
        }

        if (midNode->id < searchId) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return NULL;
}

void freeList(struct Product* head) 
{
    struct Product* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    struct Product* head = NULL;
    int n, id, searchId;

    printf("Enter the number of products: ");
    scanf("%d", &n);

    printf("Enter product IDs in sorted order:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Enter product ID %d: ", i + 1);
        scanf("%d", &id);
        appendProduct(&head, id);
    }

    printf("\nProduct Catalog:\n");
    print(head);
    printf("Total products: %d\n", getCount(head));

    printf("\nEnter product ID to search: ");
    scanf("%d", &searchId);

    struct Product* result = binarySearch(head, searchId);
    if (result != NULL) 
    {
        printf("Product found! ID: %d\n", result->id);
    } 
    else 
    {
        printf("Product with ID %d not found.\n", searchId);
    }

    freeList(head);
    return 0;
}