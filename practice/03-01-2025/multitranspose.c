#include<stdio.h>
#define n 100

int main()
{
	int i,j,a[n][n];
	int row=2,col=3;
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
	
	printf("Transpose will be :\n");
	
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d\t",a[j][i]);
			
		}
		printf("\n");
	}
	
	
	
	
}
