#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        printf("child is called now\n");
    }
    else
    {
        printf("parent is called now\n");
    }
}