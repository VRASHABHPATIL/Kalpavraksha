#include<stdio.h>
int arr[100];

void merge(int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[100], right[100];
    
    for(i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }

    for(i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    i = 0;
    j = 0;
    k = low;

    while(i < n1 && j < n2)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergersort(int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = low + (high - low) / 2;
        mergersort(low, mid);
        mergersort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int i, n;
    printf("Enter the value for n: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    
    mergersort(0, n - 1);  
    for(i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
