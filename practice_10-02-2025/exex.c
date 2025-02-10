#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
    
        char *args[] = {"rm","-r","temp", NULL};
        execvp("rm", args);


        perror("Execvp failed");
        exit(1);
    } else {
    
        printf("Parent process: My PID is %d\n", getpid());
        wait(NULL);  
    }

    return 0;
}
