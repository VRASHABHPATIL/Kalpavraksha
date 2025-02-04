#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char arr[10][100];
int top=-1;
void push(char a[])
{
    top=top+1;
    strcpy(arr[top],a);
    
}

char* pop()
{
    if(top==-1)
    {
        printf("nothing is there to pop.");
        return NULL;
    }
    else
    {
        
        char *str=arr[top];
        top=top-1;
        return str;

    }

}



int main()
{
    int temp_top=0;
    char temp[10][100];
    char str[100];
    int choice;
    while(1)
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter teh url: ");
                scanf("%s",str);
                push(str);
                break;
            case 2:
                printf("popped: %s\n",pop());
                break;
            case 3:
                printf("top element :%s\n",arr[top]);
                break;
            case 4:
                //getchar();
                temp_top=0;
                printf("enter the url to be changed: ");
                scanf("%s",str);
                char str2[100];
                
                printf("changing value: ");
                scanf("%s",str2);
                getchar();
            
                while(top!=-1)
                {
                    char *str1=pop();
                    if(strcmp(str1,str)==0)
                    {
                        break;
                    }
                    strcpy(temp[temp_top],str1);
                    temp_top=temp_top+1;
                }
                top=top+1;
                strcpy(arr[top],str2);
                while(temp_top!=0)
                {
                    push(temp[temp_top]);
                    temp_top=temp_top-1;
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid entery");
                

        }
    }
}
