#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
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

int findPairWithSum(struct Node* head, int targetSum) 
{
    struct Node* left = head;
    struct Node* right = head;

    if (right == NULL)
    {
        return 0;
    } 

    while (right->next != NULL) 
    {
        right = right->next;
    }

    while (left != right && right != NULL && left != right->next) 
    {
        int currentSum = left->data + right->data;

        if (currentSum == targetSum) 
        {
            return 1;
        } 
        else if (currentSum < targetSum) 
        {
            left = left->next;
        } 
        else 
        {
            struct Node* temp = head;
            while (temp != NULL && temp->next != right) 
            {

                temp = temp->next;
            }
            right = temp; 
        }
    }
    
    return 0;
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* head = NULL;
    int n, targetSum, val;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        append(&head, val);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    if (findPairWithSum(head, targetSum)) 
    {
        printf("Pair found with the given sum %d.\n", targetSum);
    } 
    else 
    {
        printf("No pair found with the given sum %d.\n", targetSum);
    }

    return 0;
}
