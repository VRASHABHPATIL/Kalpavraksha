#include <stdio.h>
#include <stdlib.h>

#define mapsize 10

typedef struct map 
{
    int key;
    int index;
} map;

map* hash_map[mapsize] = {NULL};

int hashfunction(int key) 
{
    key=abs(key);
    return key % mapsize;
}

map* create(int key, int index) 
{
    map* new = (map*)malloc(sizeof(map));
    new->key = key;
    new->index = index;
    return new;
}

void create_map(int key, int index) 
{
    int hashvalue = hashfunction(key);
    map* new = create(key, index);
    while (hash_map[hashvalue] != NULL) 
    {
        hashvalue = (hashvalue + 1) % mapsize;
    }
    hash_map[hashvalue] = new;
}

int find(int key) 
{
    int hashvalue = hashfunction(key);
    int start = hashvalue;
    while (hash_map[hashvalue] != NULL) 
    {
        if (hash_map[hashvalue]->key == key) 
        {
            return hash_map[hashvalue]->index;
        }
        hashvalue = (hashvalue + 1) % mapsize;

    }
    return -1;
}

void twosum(int arr[], int size, int target) 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        int reminder = target - arr[i];
        int result = find(reminder);
        if (result != -1 && result != i) 
        {
            printf("[%d, %d]\n",i,result);
            break;
        }
    }
    
}

int main() 
{
    int a[100], i, n, target;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("Enter the array values: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) 
    {
        create_map(a[i], i);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    twosum(a, n, target);

    return 0;
}
