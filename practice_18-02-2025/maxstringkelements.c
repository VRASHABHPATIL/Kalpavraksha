#include<stdio.h>
#include<string.h>
#define max 256
int maps(char str[],int k)
{
    int map[max]={0};
    int i;
    int n=strlen(str);
   // printf("%d\n",n);
    int count=0;
    // for(i=0;i<256;i++)
    // {
    //     map[i]=NULL;
    // }
    for(i=0;i<n;i++)
    {
        if(!map[str[i]])
        {
            map[str[i]]=1;
            count=count+1;
        }
    }
    if(count==k)
    {
        return n;
    }
    else
    {
        return -1;
    }

}
int main()
{
    char str[100];
    int i,j,k,m,u;
    int maxlen=0;
    printf("enter the character: ");
    scanf("%s",str);
    printf("Enter the number of  unique characters: ");
    scanf("%d",&u);
    //printf("%s\n",str);
    int n=strlen(str);
    for(i=0;i<n;i++)
    {
        
        for(j=i+1;j<n;j++)
        {
           // printf("{");
           char temp[100];
           int m=0;
            for(k=i;k<j;k++)
            {
                temp[m]=str[k];
                m=m+1;
            }
            temp[m] = '\0';
            
           // temp[i]="\0";
            int res=maps(temp,u);
            if(res==-1)
            {
                maxlen=maxlen;
            }
            else
            {
                if(res>=maxlen)
                {
                    maxlen=res;
                }
            }
        }
    }
    printf("%d\n",maxlen);
    return 0;
}