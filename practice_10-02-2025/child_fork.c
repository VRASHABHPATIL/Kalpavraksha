#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 

int main() {
    
    pid_t pid1 = fork();
    
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1); 
    }
    
    if (pid1 == 0) {
        
        pid_t pid2 = fork();
        
        if (pid2 < 0) {
            perror("Fork failed");
            exit(1); 
        }
        
        if (pid2 == 0) {
            
            pid_t pid3 = fork();
            
            if (pid3 < 0) {
                perror("Fork failed");
                exit(1); 
            }
            
            if (pid3 == 0) {
                
                printf("Child Process 3: My PID is %d, My Parent's PID is %d\n", getpid(), getppid());
            } else {
                
                printf("Child Process 2: My PID is %d, My Parent's PID is %d\n", getpid(), pid3);
            }
        } else {
            
            printf("childs Process 1: My PID is %d, My Child's PID is %d\n", getpid(), pid2);
        }
    } else {
        
        printf("Original Parent: My PID is %d, My Child's PID is %d\n", getpid(), pid1);
    }

    return 0;
}
