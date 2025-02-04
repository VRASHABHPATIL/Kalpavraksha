#include<stdio.h>

void push(int arr[], int value, int *top)
 {
    if (*top == -1) 
    {
        *top = 0;
    }
    arr[*top] = value;
    *top = *top + 1;
}

int pop(int arr[], int *top) 
{
    *top = *top - 1;
    int value = arr[*top];
    return value;
}

int main() 
{
    int i, n, value;
    int arr[100];
    int result[100];
    int top = -1;
    int *a = &top;
    
    printf("Enter the size: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) 
    {
        printf("Enter the value at %d: ", i);
        scanf("%d", &value);
        
        push(arr, value, a);
        
        int nearsmall = -1;
        int temp_stack[100];
        int temp_top = -1;

        while (*a != -1) 
        {
            int val = pop(arr, a);
            if (val < value) 
            {
                nearsmall = val;
                break;
            }
            temp_stack[++temp_top] = val;
        }
        
        while (temp_top != -1) 
        {
            push(arr, temp_stack[temp_top--], a);
        }
        
        result[i] = nearsmall;
    }

    for (i = 0; i < n; i++) 
    {
        printf("%d\n", result[i]);
    }

    return 0;
}
