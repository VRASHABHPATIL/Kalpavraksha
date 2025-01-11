#include<stdio.h>
#include<string.h>
void main()
{
    char a[100];
    int len,i,j;

    printf("Enter the string :");
    scanf("%s",a);
    len=strlen(a);
    int match;
    printf("%c",a[0]);
    for(i=1;i<len;i++)
    {
        match=0;
        for(j=0;j<i;j++)
        {
                if(a[j]==a[i])
                {
                    match=1;
                }
        }
        if(match==0)
        {
            printf("%c",a[i]);
        }
        
    }
    printf("\n");


}