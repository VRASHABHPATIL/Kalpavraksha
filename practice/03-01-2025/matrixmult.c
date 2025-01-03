#include<stdio.h>
#define n 100

int main()
{
	int i,j,a[n][n],b[n][n],c[n][n];
	int row=2,col=3;
	int row1=3,col1=2,k;
	
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("Enter the element at (%d,%d)",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			printf("Enter the element at (%d,%d)",i,j);
			scanf("%d",&b[i][j]);
			
		}
		
	}
	
	
	for (i=0;i<row;i++)
	{
	
		for(j=0;j<col1;j++)
		{
			c[i][j]=0;
			for (k=0;k<col;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}

	

	
	
	
}
