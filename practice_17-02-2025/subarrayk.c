#include<stdio.h>
#include<stdlib.h>
int uniquecount(int arr[],int n)
{
    int maps[100]={0},i;
    int count=0;
    for(i=0;i<n;i++)
    {
        if(!maps[arr[i]])
        {
            maps[arr[i]]=1;
            count=count+1;
        }

    }
    return count;
}
int main()
{
    int n,i,j,k,flag;
    int a[100];
    int maxlen=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("enter the value of k: ");
    scanf("%d",&flag);

    for(i=0;i<n;i++)
    {
        printf("enter the array element a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    

    for(i=0;i<n;i++)
    {
        
        for(j=i;j<n;j++)
        {
            int arr[100],m=0;
            for(k=i;k<=j;k++)
            {
                arr[m]=a[k];
                m=m+1;    
            }
            int a=uniquecount(arr,m);
            //printf("%d\t",a);
            if(a==flag)
            {
                maxlen=maxlen+1;
            }
            
        }
    }
    printf("%d\n",maxlen);
    return 0;
}