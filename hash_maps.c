#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct node
{
    int key;
    int value;
    struct node* next;
} Node;

Node* createNode(int key, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(Node* hash_table[], int key, int value)
{
    int hashValue = hashFunction(key);

    Node* newNode = createNode(key, value);

    if (hash_table[hashValue] == NULL)
    {
        hash_table[hashValue] = newNode;
    }
    else
    {
        Node* temp = hash_table[hashValue];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Insertion successful: (%d, %d)\n", key, value);
}

int search(Node* hash_table[], int key)
{
    int hashValue = hashFunction(key);
    Node* temp = hash_table[hashValue];

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void delete(Node* hash_table[], int key)
{
    int hashValue = hashFunction(key);

    if (hash_table[hashValue] == NULL)
    {
        printf("Error: Key %d not present in the table.\n", key);
        return;
    }

    Node* temp = hash_table[hashValue];

    if (temp->key == key)
    {
        printf("Deleted key %d with value %d\n", temp->key, temp->value);
        hash_table[hashValue] = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("Deleted key %d with value %d\n", temp->key, temp->value);
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Error: Key %d not found for deletion.\n", key);
}

void display(Node* hash_table[])
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Bucket %d: ", i);
        Node* temp = hash_table[i];

        if (temp != NULL)
        {
            while (temp != NULL)
            {
                printf("(%d, %d) -> ", temp->key, temp->value);
                temp = temp->next;
            }
            printf("NULL\n");
        }
        else
        {
            printf("NULL\n");
        }
    }
}


void freeTable(Node* hash_table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* temp = hash_table[i];
        while (temp != NULL)
        {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main()
{
  
    Node* hash_table[TABLE_SIZE] = {NULL};

    int choice, key, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice)
        {
            case 1:
                printf("Enter key and value to insert (key value): ");
                if (scanf("%d %d", &key, &value) != 2)
                {
                    printf("Invalid input. Please enter two integers.\n");
                    while(getchar() != '\n');
                    break;
                }
                insert(hash_table, key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                if (scanf("%d", &key) != 1)
                {
                    printf("Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                value = search(hash_table, key);
                if (value == -1)
                {
                    printf("Key %d not found in the table.\n", key);
                }
                else
                {
                    printf("Key %d found with value: %d\n", key, value);
                }
                break;

            case 3:
                printf("Enter key to delete: ");
                if (scanf("%d", &key) != 1)
                {
                    printf("Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                delete(hash_table, key);
                break;

            case 4:
                display(hash_table);
                break;

            case 5:
                printf("Exiting program...\n");
                freeTable(hash_table); 
                exit(0);
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
