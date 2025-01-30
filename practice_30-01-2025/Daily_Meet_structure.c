#include<stdio.h>
#include<stdlib.h>
typedef struct values
{
    char *string;
    int **arr;
}values;

int main()
{
    values *v=(values*)malloc(sizeof(values));
    int i,j;

    v->string=(char*)malloc(100*sizeof(char));
    printf("Enter the space saparated string value :");
    scanf("%[^\n]%*c",v->string);

    v->arr=(int**)malloc(3*sizeof(int));
    for(i=0;i<3;i++)
    {
        v->arr[i]=(int*)malloc(3*sizeof(int));
    }
    printf("enter the values for 2darray\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("enter the value for arr[%d][%d]: ",i,j);
            scanf("%d",&(v->arr[i][j]));
        }
        
    }

    printf("String is: %s\n",v->string);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",v->arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}