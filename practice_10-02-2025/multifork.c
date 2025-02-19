#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int num_children = 5;
    pid_t pid;

    for (int i = 0; i < num_children; i++) {
        pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0) {
            printf("Child %d: My PID is %d, My Parent's PID is %d\n", i + 1, getpid(), getppid());
            exit(0);
        }
    }

    for (int i = 0; i < num_children; i++) {
        wait(NULL);
    }

    printf("Parent: All child processes have terminated.\n");
    return 0;
}
