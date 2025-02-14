#include<stdio.h>
#include<stdlib.h>
#define mapsize 10
typedef struct node
{
    int data;
}map;
map hash_map[mapsize]={0};
int hashfunction(int key)
{
    return key%mapsize;
}

void insert(int data,int key)
{
    int index=hashfunction(key);
    while(hash_map[index].data!=0)
    {
        index=hashfunction(key+1);
    }
    hash_map[index].data=data;
}

void display()
{
    int i;
    for(i=0;i<mapsize;i++)
    {
        printf("index: %d\t value: %d\n",i,hash_map[i].data);
    }
    printf("\n");
}

int main()
{
    insert(10,15);
    insert(20,15);
    insert(30,16);
    insert(40,17);
    insert(50,18);
    insert(60,19);
    insert(70,123);
    insert(80,22);
    display();
    return 0;
}