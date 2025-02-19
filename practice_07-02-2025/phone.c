#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX_NAME 101
#define MAX_CONTACTS 100001
 
struct Contact 
{
    char name[MAX_NAME];
    long long number;
    int isValid;
};
 
struct Contact phonebook[MAX_CONTACTS];
int contactCount = 0;
 
void add(char *name, long long number) 
{
    for(int i = 0; i < contactCount; i++) 
    {
        if(phonebook[i].isValid && strcmp(phonebook[i].name, name) == 0) 
        {
            phonebook[i].number = number;
            printf("Success");
            return;
        }
    }
    
    strcpy(phonebook[contactCount].name, name);
    phonebook[contactCount].number = number;
    phonebook[contactCount].isValid = 1;
    contactCount++;
    printf("Success");
}
 
void delete(char *name) 
{
    for(int i = 0; i < contactCount; i++) 
    {
        if(phonebook[i].isValid && strcmp(phonebook[i].name, name) == 0) 
        {
            phonebook[i].isValid = 0;
            printf("Success");
            return;
        }
    }
    printf("Not Found");
}
 
void search(char *name) 
{
    for(int i = 0; i < contactCount; i++) 
    {
        if(phonebook[i].isValid && strcmp(phonebook[i].name, name) == 0) 
        {
            printf("%lld", phonebook[i].number);
            return;
        }
    }
    printf("Not Found");
}
 
int main() 
{
    int n;
    scanf("%d\n", &n);
    
    while(n--) 
    {
        char operation[10], line[1000];
        fgets(line, sizeof(line), stdin);
        
        int i = 0;
        while(line[i] != '(' && line[i] != '\0') 
        {
            if(line[i] != ' ') 
            {
                operation[i] = line[i];
                i++;
            }
            else 
            {
                line[i] = '\0';
            }
        }
        operation[i] = '\0';
        
    
        char name[MAX_NAME] = {0};
        long long number;
        char *start = strchr(line, '"');
        if(start) 
        {
            start++;
            char *end = strchr(start, '"');
            if(end) 
            {
                strncpy(name, start, end - start);
                name[end - start] = '\0';
            }
        }
        
        if(strcmp(operation, "add") == 0) 
        {
            sscanf(strrchr(line, ',') + 1, "%lld", &number);
            add(name, number);
        }
        else if(strcmp(operation, "search") == 0) 
        {
            search(name);
        }
        else if(strcmp(operation, "delete") == 0) 
        {
            delete(name);
        }
        
        if(n > 0) printf("\n");
    }
    return 0;
}