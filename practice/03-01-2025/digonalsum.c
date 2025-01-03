#include<stdio.h>
#define n 100

int main()
{
	int i,j,a[n][n];
	int row=2,col=2;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("Enter the element at (%d,%d)",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",a[i][j]);
			
		}
		printf("\n");
	}
	
	printf("sum  will be :\n");
	int sum=0;
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			if(i==j)
			{
				sum=sum+a[i][j];
			}
			
		}
		
	}
	
	printf("%d\n",sum);
	
	
	
	
}
