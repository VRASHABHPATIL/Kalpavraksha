#include<stdio.h>
int main()
{
    char str1[100],str2[100];
    int n;
    printf("Enter the input ");
    scanf("%[^(](\"%[^\"]\",%d)",str1,str2,&n);
    printf("%s\n",str1);
    printf("%s\n",str2);
    printf("%d\n",n);
    return 0;
}