#include<stdio.h>
#include<stdlib.h>
#define mapsize 10
typedef struct map
{
    int key;
    int index;
    struct map* next;
}map;
map* hash_map[mapsize]={NULL};
int hashfunction(int key)
{
    return key%mapsize;
}
map* create(int key,int index)
{
    map* new=(map*)malloc(sizeof(map));
    new->key=key;
    new->index=index;
    new->next=NULL;
    return new;
}

map* create_map(int key,int index)
{
    int hashvalue=hashfunction(key);
    map* new=create(key,index);
    if(hash_map[hashvalue]==NULL)
    {
        hash_map[hashvalue]=new;
    }
    else
    {
        map* temp=hash_map[hashvalue];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}

// void display()
// {
//     int i;
//     for(i=0;i<mapsize;i++)
//     {
//         printf("index: %d-> ",i);
//         map* temp=hash_map[i];
//         while(temp!=NULL)
//         {
//             printf("%d %d-> ",temp->key,temp->index);
//             temp=temp->next;
//         }
//         printf("NULL");
//         printf("\n");
//     }
// }

int find(int key)
{
    int hashvalue=hashfunction(key);
    int index=-1;
    map* temp=hash_map[hashvalue];
    while(temp!=NULL)
    {
        if(temp->key==key)
        {
            index=temp->index;
            break;

        }
    }
    return index;

}

int twosum(int arr[],int size,int target)
{
    int i;

    for(i=0;i<size;i++)
    {
        int reminder=target-arr[i];
        int result=find(reminder);
        if(result!=-1)
        {
            printf("[%d,%d]\n",i,result);
            break;
        }

    }
}
int main()
{
    int a[100],i,n,target;

    printf("Enter the size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enyter the array values: ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        create_map(a[i],i);
    }
    printf("enter the target value: ");
    scanf("%d",&target);
   // display();
    // int b= find(2);
    // printf("%d",b);
    twosum(a,n,target);


    return 0;
}