#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(struct Node** head, int position, int value) 
{
    if (position < 1) 
    {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) 
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) 
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(struct Node* head, int position, int newValue) {
    if (position < 1) 
    {
        printf("Invalid position\n");
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position; i++) 
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp->data = newValue;
}

void deleteAtBeginning(struct Node** head) 
{
    if (*head == NULL) 
    {
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) 
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node** head, int position) 
{
    if (position < 1 || *head == NULL) 
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) 
    {
        if (temp == NULL || temp->next == NULL) 
        {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

int main() {
    int n, operation, value, position;
    struct Node* head = NULL;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter the operation number: ");
        scanf("%d", &operation);

        switch (operation) 
        {
            case 1: 
                printf("Enter the data to be inserted at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2: 
                printf("Enter the data to be inserted at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 3: 
                printf("Enter the position where the data to be inserted: ");
                scanf("%d", &position);
                printf("Enter the data to be inserted: ");
                scanf("%d", &value);
                insertAtPosition(&head, position, value);
                break;
            case 4: 
                display(head);
                break;
            case 5: 
                printf("Enter the position where the data need to be updated: ");
                scanf("%d", &position);
                printf("Enter the data to be inserted: ");
                scanf("%d", &value);
                updateAtPosition(head, position, value);
                break;
            case 6: 
                deleteAtBeginning(&head);
                break;
            case 7: 
                deleteAtEnd(&head);
                break;
            case 8: 
                printf("Enter the position where the data needs to be deleted: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            default:
                printf("Invalid operation\n");
                break;
        }
    }

    return 0;
}
