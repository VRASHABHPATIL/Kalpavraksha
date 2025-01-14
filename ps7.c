#include <stdio.h>
#include <ctype.h>

void main() {
    char a[100];
    int i=0,j=0,count,maxlen=0;
    char word[100];
    int  iteratori;
    

    printf("Enter the string: ");
    scanf("%[^\n]%*c", a);

    while (a[i] != '\0') 
    {
        while (a[i] != '\0' && a[i]==' ')
        {
            i++;
        }
        if (a[i] != '\0') 
        {
            j = 0;

            while (a[i] != '\0' && a[i]!=' ') 
            {
                word[j++] = a[i++];
            
            }
            count=j;
            word[j] = '\0';
            if(count>maxlen)
            {
                maxlen=count;
                iteratori=i-count;
            }

            
        }
    }

    for(i=0;i<maxlen;i++)
    {
        printf("%c",a[iteratori]);
        iteratori++;
    }
    printf("\n");
}
