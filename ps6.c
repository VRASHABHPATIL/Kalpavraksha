#include <stdio.h>
#include <string.h>

void sortstring(char *ptr, int len) 
{
    char temp;
    int i, j;
    for (i = 0; i < len - 1; i++) 
    {
        for (j = 0; j < len - i - 1; j++) 
        {
            if (*(ptr + j) > *(ptr + j + 1)) 
            {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

void main() 
{
    char string1[100];
    char string2[100];
    char *ptr1 = string1;
    char *ptr2 = string2;
    int str1len,str2len,i;

    printf("Enter string1: ");
    scanf("%s", string1);

    printf("Enter string2: ");
    scanf("%s", string2);

    str1len = strlen(string1);
    str2len = strlen(string2);

    sortstring(ptr1,str1len);
    sortstring(ptr2,str2len);

    int flag=0;
    for(i=0;i<str1len;i++)
    {
        if(string1[i]!=string2[i])
        {
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("The given string are anagrams\n");
    }
    else
    {
        printf("The given string are not an anagrams\n");

    }

    
}
