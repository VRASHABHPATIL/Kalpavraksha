//here used the transpose and row revercing for appropriate marix multification

#include <stdio.h>

void rotateMatrix(int n, int matrix[n][n]) 
{
    int i,j,temp;
    for (i = 0; i < n; i++) 
    {
        for (j = i; j < n; j++) 
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    for (i = 0; i < n; i++) 
    {
        int start = 0, end = n - 1;
        while (start < end) 
        {
            temp = matrix[i][start];
            matrix[i][start] = matrix[i][end];
            matrix[i][end] = temp;
            start++;
            end--;
        }
    }
}

void printMatrix(int n, int matrix[n][n]) 
{
    int i,j;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    int matrix[n][n],i,j;
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\nOriginal Matrix:\n");
    printMatrix(n, matrix);
    
    rotateMatrix(n, matrix);
    
    printf("\nMatrix after 90 degree clockwise rotation:\n");
    printMatrix(n, matrix);
    
    return 0;
}

