#include<stdio.h>
#include<stdlib.h>

struct order 
{
    int orderValue;
    int orderNumber;
    struct order* next;
};

struct order* create(int orderNumber, int orderValue) 
{
    struct order* newnode = (struct order*)malloc(sizeof(struct order));
    newnode->orderValue = orderValue;
    newnode->orderNumber = orderNumber;
    newnode->next = NULL;
    return newnode;
}

void createList(struct order** head, int orderNumber, int orderValue) 
{
    struct order* newnode = create(orderNumber, orderValue);
    struct order* temp = *head;
    if (*head == NULL) 
    {
        *head = newnode;
    } else {
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void print(struct order* head) 
{
    struct order* temp = head;
    while (temp != NULL) 
    {
        printf("Order Number: %d, Order Value: %d\n", temp->orderNumber, temp->orderValue);
        temp = temp->next;
    }
}

void freeList(struct order* head) 
{
    struct order* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct order* split(struct order* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return NULL;
    }
    struct order* slow = head;
    struct order* fast = head->next;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct order* second = slow->next;
    slow->next = NULL;
    return second;
}

struct order* merge(struct order* first, struct order* second) 
{
    if (first == NULL) 
    {   
        return second;
    }
    if (second == NULL) 
    {
        return first;
    }
    if (first->orderValue < second->orderValue)
    {
        first->next = merge(first->next, second);
        return first;
    } 
    else 
    {
        second->next = merge(first, second->next);
        return second;
    }
}

struct order* mergeSort(struct order* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    struct order* second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}

int main() 
{
    struct order* head = NULL;
    int n, i, orderNumber, orderValue;
    printf("Enter the number of orders: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("Enter order number %d: ", i + 1);
        scanf("%d", &orderNumber);
        printf("Enter order value for order %d: ", orderNumber);
        scanf("%d", &orderValue);
        createList(&head, orderNumber, orderValue);
    }
    printf("Order list before sorting:\n");
    print(head);
    head = mergeSort(head);
    printf("Order list after sorting:\n");
    print(head);
    freeList(head);
    return 0;
}