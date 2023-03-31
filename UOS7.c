#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid, status;

    // fork a child process
    pid = fork();

    if (pid < 0) {
        // fork failed
        printf("Error: Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        printf("Child process with PID %d started.\n", getpid());
        printf("Child process is executing...\n");
        sleep(5);
        printf("Child process finished.\n");
        exit(0);
    } else {
        // parent process
        printf("Parent process with PID %d started.\n", getpid());
        printf("Parent process is waiting for child process to finish...\n");
        wait(&status);
        printf("Child process with PID %d finished with status %d.\n", pid, status);
        printf("Parent process finished.\n");
    }

    return 0;
} 
