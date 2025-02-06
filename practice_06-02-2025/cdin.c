#include<stdio.h>
#include<string.h>
int main()
{
    char input[100]="""cd usr/"",""cd local/"",""cd bin/"",""cd ../""";

    char *token=strtok(input,"\", ");

    while(token!=NULL)
    {
        printf("%s\n",token);
        token=strtok(NULL,"\", ");
        

    }
    return 0;
}