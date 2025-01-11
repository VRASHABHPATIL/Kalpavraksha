#include<stdio.h>
#include<string.h>
void main()
{
    char string1[100];
    char string2[100];
    int str1len,str2len,i,j,flag=0;

    printf("Enter the string1 :");
    scanf("%s",string1);

    printf("Enter the string2 :");
    scanf("%s",string2);
    str1len=strlen(string1);
    str2len=strlen(string2);

    if(str1len!=str2len)
    {
        flag=1;
    }
    else
    {
        j=str1len-1;
        for(i=0;i<str1len;i++)
        {
            if(string1[i]!=string2[j])
            {
                flag=1;
            }
            j=j-1;

        }
    }

    if(flag==0)
    {
        printf("output : true\n");
    }

    else 
    {
        printf("output : false\n");
    }




}