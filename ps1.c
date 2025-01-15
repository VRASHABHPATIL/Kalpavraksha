#include<stdio.h>

int strlength(char a[100])
{
    int len=0,i=0;
    while(a[i]!='\0')
    {
        i=i+1;

    }
    return i;
}
int strpalindrome(char a[100],int len)
{
    int flag=1,i;
    
    for(i=0;i<len/2;i++)
    {
        if(a[i]!=a[len-i-1])
        {
            
            flag=0;
        }
    }

    return flag;


}
int strcombinationlen(char *str, char *result, int start, int len, int index) 
{
    int maxlen = 0,i;    
    
    if (index > 0) 
    {
        result[index] = '\0';
        int curlen = strlength(result);
        if(strpalindrome(result, curlen)) 
        {   
            if (curlen >= maxlen)
            {            
                maxlen = curlen;  
                          
            }
        }
    }
   
    
    for(i=start; i<len; i++) {
        result[index] = str[i];
        int track=strcombinationlen(str, result, i + 1, len, index + 1);
        if(track>maxlen)
        {
            maxlen=track;
        }
    }
    return maxlen;
    
}

int strcombination(char *str, char *result, int start, int len, int index, int len1) 
{
    int maxlen = 0,i;    
    
    if (index > 0) 
    {
        result[index] = '\0';
        int curlen = strlength(result);
        if(strpalindrome(result, curlen)) 
        {   
            if (curlen==len1)
            {            
                printf("%s\n",result);           
                
            }
        }
    }
 
    
    for(i=start; i<len; i++) {
        result[index] = str[i];
        strcombination(str, result, i + 1, len, index + 1,len1);
    }
}
void main()
{
    char str[100],result[100];
    int i,j,length,ispal,len1;
    printf("Enter the string value :");
    scanf("%s",str);
    length=strlength(str);
    ispal=strpalindrome(str,length);
    len1=strcombinationlen(str,result,0,length,0);
    strcombination(str,result,0,length,0,len1);



}