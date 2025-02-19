#include<stdio.h>
#include<stdlib.h>
struct node
{
    int *data;
};
struct node* print(struct node * arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(arr[i].data));
    }
    printf("\n");
}
int main()
{
    int n,i;
    printf("Enter the value of n :");
    scanf("%d",&n);
    struct node* arr=(struct node*)malloc(n*(sizeof(struct node*)));
    for(i=0;i<n;i++)
    {
        arr[i].data=(int*)malloc(sizeof(int));
        *(arr[i].data)=i;
    }
    print(arr,n);
    
}