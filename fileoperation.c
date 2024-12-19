#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USERS_FILE "users.txt"
#define TEMP_FILE "temp.txt"
typedef struct 
{
    int id;
    char name[50];
    int age;
}User;

int filestatus=0;

int fileStatus(int status)
{
	if(status==1)
	{
		printf("Error : please chick the file path or permissions to creating or opening the file the file..!");	
		exit(0);
	}

}
void create() 
{
    	
    FILE *file = fopen(USERS_FILE, "w");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        filestatus=1;
        fileStatus(filestatus);
    }
    fclose(file);
    
}

void add() 
{
    FILE *file = fopen(USERS_FILE, "r+");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        filestatus=1;
        fileStatus(filestatus);
    }

    User user;
    while(1)
    {
    	    int found=0;
	    printf("enter user id: ");
	    scanf("%d", &user.id);
	    int id =user.id;
	    while (fscanf(file, "%d %s %d", &user.id, user.name, &user.age) != EOF) 
	    {
	    	if(id==user.id)
	    	{
	    		found =1;
	    	}
	    }
	    if(user.id <=0)
	    {
	    	printf("User id must be non negative number\n");
	    }
	    else if(found==1)
	    {
	    	printf("User already exists with this user id\n");
	    }
	    else
	    {
	    	break;
	    }
    }
    printf("enter user name: ");
    scanf("%s", user.name);

    while(1)
    {
	    printf("enter user age: ");
	    scanf("%d", &user.age);
	    if(user.age<=0)
	    {
	    	printf("User age can not be null or negative \n");
	    }
	    else
	    {
	    	break;
	    }
    }

    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file);
    
    
}

void display() 
{
    FILE *file = fopen(USERS_FILE, "r");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        filestatus=1;
        fileStatus(filestatus);
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
    FILE *file = fopen(USERS_FILE, "r");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        filestatus=1;
        fileStatus(filestatus);
        
    }

    User user;
    int id,found=0;
    printf("enter the userid to be updated: ");
    scanf("%d", &id);

    FILE *temp = fopen(TEMP_FILE, "w");
    if (temp==NULL) 
    {
        printf("error in opening the temp file!\n");
        filestatus=1;
        fileStatus(filestatus);
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

    remove(USERS_FILE);
    rename(TEMP_FILE, USERS_FILE);

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
    FILE *file = fopen(USERS_FILE, "r");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        filestatus=1;
        fileStatus(filestatus);
    }

    User user;
    int id, found = 0;
    printf("enter the user id to be deleted : ");
    scanf("%d", &id);

    FILE *temp = fopen(TEMP_FILE, "w");
    if (temp == NULL) 
    {
        printf("error in opening the temp file!\n");
        filestatus=1;
        fileStatus(filestatus);
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

    remove(USERS_FILE);
    rename(TEMP_FILE, USERS_FILE);

    if (!found) 
    {
        printf("user id not found!\n");
    } 
    else 
    {
        printf("user deleted.\n");
    }
}

enum ChoiceMenu {
	Add_User=1,
	Display_User,
	Update_User,
	Delete_User,
	Exit,
};
int main() {
    int choice;
    FILE *file = fopen(USERS_FILE, "r");
    if (file==NULL) 
    {
        printf("error in opening the file!\n");
        filestatus=1;
        fileStatus(filestatus);
    }
    else
    {
    	create();
    }
    
    
    while (1) 
    {
    	int filestatus;
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
            case Add_User:
                add();
                
                break;
            case Display_User:
                display();
                break;
            case Update_User:
                update();
                break;
            case Delete_User:
                delete();
                break;
            case Exit:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        
    }

    return 0;
}

