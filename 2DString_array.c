#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100
#define STRSIZE 50

int vowelcount(char name[SIZE][SIZE][STRSIZE], int row, int column)
{
	int i,j,vowelcount=0;
	int k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			char str[SIZE]="";
			strcpy(str,name[i][j]);
			char ch=tolower(str[k]);
			if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
			{
				vowelcount=vowelcount+1;
		
			}
			
				
		}
	}
	
	return vowelcount;
	
}

void LongName(char name[SIZE][SIZE][STRSIZE], int row, int column)
{
	int i,j,maxlen=0,rowposition,columnposition;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			if(strlen(name[i][j])>maxlen)
			{
				maxlen=strlen(name[i][j]);
				rowposition=i;
				columnposition=j;
				
				
			}
			
				
		}	
	}
	
	printf("The longest name : %s\n",name[rowposition][columnposition]);
	
}

void printnames(char name[SIZE][SIZE][STRSIZE], int row, int column)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%s\t",name[i][j]);
		}
		printf("\n");
	}
	
	
}

int main() 
{
	int rows,columns,i,j,vcount;
	char names[SIZE][SIZE][STRSIZE];
	while(1)
	{
		printf("Enter the number of rows : ");
		scanf("%d",&rows);
		
		if(rows<1 || rows>10)
		{
			printf("Invalid entery enter the row value between 1-10..!\n");
		}
		else
		{
			break;
		}
	
	}
	
	
	while(1)
	{
		printf("Enter the number of columns : ");
		scanf("%d",&columns);
		
		if(columns<1 || columns>101)
		{
			printf("Invalid entery enter the column value between 1-101..!\n");
		}
		else
		{
			break;
		}
	
	}

	
	
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			while(1)
			{
				printf("Enter the value at position(%d,%d) :",i,j);
				scanf("%s", names[i][j]);
				
				if(strlen(names[i][j])>STRSIZE)
				{
					printf("Error ..! Maximum length of character allowed is 50 please enter within that limit\n");
				
				}
				else
				{
					break;
				}
			
			}
			
		}
	}
	
	printnames(names,rows,columns);
	vcount=vowelcount(names,rows,columns);
	printf("Number of names starting with a vowel: %d\n",vcount);
	LongName(names,rows,columns);
	
} 
