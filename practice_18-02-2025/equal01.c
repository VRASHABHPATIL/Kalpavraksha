#include<stdio.h>
#include<string.h>
int maps(int a[],int n)
{
    int map[100]={0};
    int i;
   // printf("%d\n",n);
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            map[0]=map[0]+1;
        }
        else
        {
            map[1]=map[1]+1;
        }
    }
    if(map[0]==map[1])
    {
        return n;
    }
    return -1;


}
int main()
{
    int arr[100],i,j,n,k;
    int maxlen=-1;
    printf("Enter the size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    // for(i=0;i<n;i++)
    // {
    //     printf("%d",arr[i]);
    // }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            int temp[100];
            int m=-1;
            for(k=i;k<j;k++)
            {
                m=m+1;
                temp[m]=arr[k];       
            }
            int res=maps(temp,m);
            if(res!=-1)
            {
                if(res>maxlen)
                {
                    maxlen=res;
                }

            }

            

        }
    }
    printf("%d\n",maxlen);
    return 0;
}