#include<stdio.h>
#include<string.h>
void main()
{
    char a[100],b,c[100];
    int i,j=0;

    printf("enter the string :");
    scanf("%s",a);
    getchar();
    printf("Enter the character to be removed :");
    scanf("%c",&b);

    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=b)
        {
            c[j]=a[i];
            j=j+1;
        }

    }

    printf("%s\n",c);
}