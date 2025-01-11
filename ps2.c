#include<stdio.h>
#include<string.h>
void main()
{
    char str[100];
    int len,i,j;
    
    printf("Enter the string :");
    scanf("%[^\n]%*c",str);


    len=strlen(str);
    int wordcount=0;
    for(i=0;i<len;i++)
    {
       

        if(i==0 && str[0]== ' ')
        {
            continue;
        }
        else if (i==len-1 && str[len-1]==' ')
        {
            continue;
        }
        else if(str[i] == ' ' && str[i-1]!= ' ')  
        {
            wordcount=wordcount+1;

        }
       
        
    }
    wordcount=wordcount+1;
    printf("number of words are : %d\n",wordcount);


}