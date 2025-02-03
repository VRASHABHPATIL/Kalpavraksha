#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node
{
    int key;
    int value;
    struct node* next;

};
int hash(int key)
{
    return key%SIZE;
}
void main()
{
    int key,value,i;
    struct node *arr=(struct node*)malloc(SIZE*sizeof(struct node));
    for(i=0;i<5;i++)
    {
        printf("Enter the value of key: ");
        scanf("%d",&key);
        printf("Enter the value :");
        scanf("%d",&value);
        int a=hash(key);
        arr[a].key=key;
        arr[a].value=value;
    }

    for(i=0;i<SIZE;i++)
    {
        printf("key :%d, value :%d \n",arr[i].key,arr[i].value);
    }

}