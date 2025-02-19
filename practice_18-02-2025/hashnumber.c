#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mapsize 10
typedef struct map
{
    int data;
    int key;
    struct map* next;
}map;
map* hash_map[mapsize]={NULL};
int hash_function(int key)
{
    return key%mapsize;
}

map* create(int data,int key)
{
    map* new=(map*)malloc(sizeof(map));
    new->data=data;
    new->key=key;
    new->next=NULL;
    return new;
}
map* create_map(int key,int data)
{
    int hashvalue=hash_function(key);
    map* newnode=create(data,key);
    if(hash_map[hashvalue]==NULL)
    {
        hash_map[hashvalue]=newnode;
    }
    else
    {
        map* temp=hash_map[hashvalue];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

}

map* search(int key)
{
    int hashvalue=hash_function(key);
    map* temp=hash_map[hashvalue];
    while(temp!=NULL)
    {
        if(temp->key==key)
        {
            printf("\nforund value is : %d\n",temp->data);
            
            break;
        }
        temp=temp->next;
    }
}
void display()
{
    int i;
    for(i=0;i<mapsize;i++)
    {
        map* temp=hash_map[i];
        printf("index: %d: ",i);
        while(temp!=NULL)
        {
            printf("|%d|%d|->",temp->key,temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
    
}
map* delete(int key)
{
    int hashvalue=hash_function(key);
    map* temp=hash_map[hashvalue];
    map* prve;
    while(temp!=NULL && temp->key!=key)
    {
        prve=temp;
        temp=temp->next;
    }
    if(prve!=NULL)
    {
        prve->next=temp->next;
    }
    free(temp);
}
int main()
{

    create_map(1,20);
    create_map(11,20);
    create_map(21,20);
    create_map(12,20);
    create_map(22,20);
    create_map(32,20);
    create_map(13,20);
    create_map(14,20);
    create_map(15,20);
    create_map(16,20);
    create_map(17,20);
    create_map(28,20);
    create_map(19,20);
    create_map(17,20);
    create_map(18,29);
    create_map(10,20);
    display();
    search(18);
    delete(32);
    display();
    return 0;
}