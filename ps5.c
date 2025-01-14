#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{   
    char number[100];
    int sign=0,len,num=0,i,j=0;
    int valid=0;

    printf("Enter the number :");
    scanf("%s",number);

    len=strlen(number);

    if(number[0]=='-')
    {
        sign=1;
        j=j+1;
    }

    for(i=j;i<len;i++)
    {
        if(!isdigit(number[i]))
        {
            valid=1;
            break;
        }
        num=num*10+(number[i]-'0');

    }

    if(sign==1)
    {
        num=num*-1;
    }

    if(valid==1)
    {
        printf("Invalid input..!\n");

    }
    else
    {
        printf("Number is : %d\n",num);

    }
   



}