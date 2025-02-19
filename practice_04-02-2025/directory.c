#include<stdio.h>
#include<string.h>
#define SIZE 100
typedef struct node
{
    char a[100];

}node;
node stack[SIZE];
int top=-1;

void push(char arr[])
{
    if(top>SIZE-1)
    {
        printf("stack overflow\n");

    }
    else
    {
        top=top+1;
        strcpy(stack[top].a,arr);

    }
}

node pop()
{
    if(top==-1)
    {
        printf("nothing is there to print within the stack\n");
    }
    else
    {
        node s;
        strcpy(s.a,stack[top].a);
        top=top-1;
        return s;
    }
}


int main()
{
    int n,i;
    char str[100];
    char result[100];
    char temp[10][100];
    printf("Enter the size of elements :");
    scanf("%d",&n);
    getchar();
    char *str1="../";
    for(i=0;i<n;i++)
    {
        printf("enter the operation:");
        scanf("%[^\n]%*c",str);
        char *a=strtok(str," ");
        char *b=strtok(NULL," ");

        if(strcmp(b,str1)==0)
        {
            node n=pop();
          
        }
        else
        {
            push(b);
        }
        
    }
    i=0;
    while(top!=-1)
    {
        node n=pop();
        strcpy(temp[i],n.a);
        i=i+1;
        
    }
    int size=i;
    for(i=size-1;i>=0;i--)
    {
        printf("%s",temp[i]);
    }
    printf("\n");

    
}