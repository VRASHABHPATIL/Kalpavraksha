//question: Declare a 2D array of size 3x3 and initialize it with numbers from 1 to 9. Print the array and find the sum.

#include<stdio.h>
#define size 3
int main()
{
	int a[size][size];
	int i,j,sum=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("Enter the value for position (%d,%d) :",i,j);
			scanf("%d",&a[i][j]);
			sum=sum+a[i][j];
			
		}
	}
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf("%d\t",a[i][j]);
			
		}
		printf("\n");
	}
	
	printf("The sum will be : %d\n",sum);

}

