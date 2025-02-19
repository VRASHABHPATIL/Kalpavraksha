#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
typedef struct node
{
    char key[100];
    int id;
    struct node* next;
}node;

node* hash_map[size]={NULL};

int hashfunction(char key[])
{
    int i,a=0;
    int n=strlen(key);
    for(i=0;i<n;i++)
    {
        a=a+key[i];
    }
    printf("hashvalue: %d\n",a);
    return a%size;
}

node* create(char key[],int id)
{
    node* new=(node*)malloc(sizeof(node));
    new->id=id;
    strcpy(new->key,key);
    new->next=NULL;
    return new;
}

node* insert(char key[],int id)
{
    node* newnode=create(key,id);
    int hashvalue=hashfunction(key);
    if(hash_map[hashvalue]==NULL)
    {
        hash_map[hashvalue]=newnode;
    }
    else
    {
        node* temp=hash_map[hashvalue];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void search(char key[])
{
    int hashvalue=hashfunction(key);
    node* temp=hash_map[hashvalue];
    while(temp!=NULL)
    {
        if(strcmp(temp->key,key)==0)
        {
            printf("id is : %d\n",temp->id);
            break;
        }
        temp=temp->next;
    }
}

void update(char key[],int updated_id)
{
    int hashvalue=hashfunction(key);
    node* temp=hash_map[hashvalue];
    while(temp!=NULL)
    {
        if(strcmp(temp->key,key)==0)
        {
            temp->id=updated_id;
            printf("updated sucesfully.\n");
        }
        temp=temp->next;
    }
}
void display()
{
    int i;
    for(i=0;i<size;i++)
    {
        node* temp=hash_map[i];
        printf("index: %d: ",i);
        while(temp!=NULL)
        {
            printf("|%s %d|->",temp->key,temp->id);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    insert("alice",1);
    insert("bob",2);
    insert("kelvin",3);
    insert("Vrashabh",4);
    display();
    search("Vrashabh");
    update("Vrashabh",10);
    display();
    return 0;
}