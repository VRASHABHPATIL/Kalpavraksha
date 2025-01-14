#include<stdio.h>

void  compress(char c[100],int len)
{
    int i,count,j=0;
    char compressed[100];
    for(i=0;i<len;i++)
    {
        count=1;
        while(i+1<len && c[i]==c[i+1])
        {
            i=i+1;
            count=count+1;
        }

        compressed[j]=c[i];
        j=j+1;
        compressed[j]=count+'0';
        j=j+1;

    }
    compressed[j]='\0';
    printf("%s\n",compressed);
}
int strlength(char b[100])
{
    int i=0;
    while(b[i]!='\0')
    {
        i=i+1;
    }
    return i;
}

void main()
{
    char a[100],len;
    char compressed1[100];

    printf("Enter the string :");
    scanf("%s",a);

    len=strlength(a);
    compress(a,len);


}