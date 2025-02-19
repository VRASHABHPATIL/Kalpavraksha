#include<stdio.h>
int main()
{
    int n,i,j,a[100],div;
    int flag=0;

    printf("enter the number of array: ");
    scanf("%d",&n);
    printf("Enter the diviser: ");
    scanf("%d",&div);
    for(i=0;i<n;i++)
    {
        printf("Enter the value for a[%d]: ",i);
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++)
    {

        
        for(j=i+1;j<n;j++)
        {

            int sum=0;
            sum=a[i]+a[j];
            if(sum%div==0)
            {
                flag=1;
            }

           //printf("[%d %d] ",a[i],a[j]);


        }
       
        
    }
    if(flag==1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}