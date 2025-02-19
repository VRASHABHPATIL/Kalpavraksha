#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr=(int*)malloc(sizeof(int));
    int choice,value;
    int i=1,j;

    while(1)
    {
        printf("Enter 1 for inserting first element\n");
        printf("Enter 2 for is additional element need to be added\n");
        printf("enter 3 for printing elements\n");
        printf("Enter 4 for exiting\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value:");
                scanf("%d",&value);
                arr[i]=value;
                i=i+1;
                break;
            case 2:
                printf("Enter the value:");
                scanf("%d",&value);
                arr=realloc(arr,i*sizeof(int));
                arr[i]=value;
                i=i+1;
                break;
            case 3:
                for(j=1;j<i;j++)
                {
                    printf("%d\n",arr[j]);
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice");
                break;
                

        }
    }
}