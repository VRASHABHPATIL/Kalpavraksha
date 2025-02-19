#include<stdio.h>
#include<string.h>
void horizontal_rotation(int (*a)[100],int row,int column)
{
    int i,j;
    for(i=0;i<row/2;i++)
    {
        for(j=0;j<column;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[row-i-1][j];
            a[row-i-1][j]=temp;
        }
    }
}

void transpose(int (*a)[100],int row,int column)
{
    int i,j;
    int temp[100][100];
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            temp[j][i]=a[i][j];
        }
    }
    for(i=0;i<column;i++)
    {
        for(j=0;j<row;j++)
        {
            a[i][j]=temp[i][j];
        }
    }


}

void vertical_rotation(int (*a)[100],int row,int column)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column/2;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[i][column-j-1];
            a[i][column-j-1]=temp;
        }
    }
}
void print(int (*a)[100],int row,int column)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int a[100][100],row,column;
    int i,j;
    printf("Enter the value of rows: ");
    scanf("%d",&row);
    printf("Enter the value of column: ");
    scanf("%d",&column);

    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("Enter the value for the position a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    print(a,row,column);
    printf("\n");
    // horizontal_rotation(a,row,column);
    // print(a,row,column);
    // printf("\n");
    // transpose(a,row,column);
    // print(a,column,row);
    vertical_rotation(a,row,column);
    print(a,row,column);
    printf("\n");
    transpose(a,row,column);
    print(a,column,row);
    printf("\n");
}