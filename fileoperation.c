#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int id;
    char name[50];
    int age;
}User;

void create() 
{
    FILE *file = fopen("users.txt", "w");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        exit(1);
    }
    fclose(file);
}

void add() 
{
    FILE *file = fopen("users.txt", "a");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        exit(1);
    }

    User user;
    printf("enter user id: ");
    scanf("%d", &user.id);
    printf("enter user name: ");
    scanf("%s", user.name);
    printf("enter user age: ");
    scanf("%d", &user.age);

    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
}

void display() 
{
    FILE *file = fopen("users.txt", "r");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        exit(1);
    }

    User user;
    printf("ID\tName\tAge\n");
    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) 
    {
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}

void update() 
{
    FILE *file = fopen("users.txt", "r");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        exit(1);
    }

    User user;
    int id,found=0;
    printf("enter the userid to be updated: ");
    scanf("%d", &id);

    FILE *temp = fopen("temp.txt", "w");
    if (temp==NULL) 
    {
        printf("error in opening the temp file!\n");
        exit(1);
    }

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) 
    {
        if (user.id==id) 
        {
            printf("enter the new user name : ");
            scanf("%s", user.name);
            printf("enter the new user age: ");
            scanf("%d", &user.age);
            found = 1;
        }
        fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (!found) 
    {
        printf("user id not found!\n");
    } 
    else
    {
        printf("user details updated.\n");
    }
}

void delete() 
{
    FILE *file = fopen("users.txt", "r");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        exit(1);
    }

    User user;
    int id, found = 0;
    printf("enter the user id to be deleted : ");
    scanf("%d", &id);

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) 
    {
        printf("error in opening the temp file!\n");
        exit(1);
    }

    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) 
    {
        if (user.id != id) 
        {
            fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
        } 
        else 
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (!found) 
    {
        printf("user id not found!\n");
    } 
    else 
    {
        printf("user deleted.\n");
    }
}

int main() {
    int choice;
    create();

    while (1) 
    {
        printf("enter you choice:\n");
        printf("1.add user\n");
        printf("2.display users\n");
        printf("3.update user\n");
        printf("4.delete user\n");
        printf("5.exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                update();
                break;
            case 4:
                delete();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        
    }

    return 0;
}

