#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 25

int main() {
    int pipefds[2];
    char buffer[BUFFER_SIZE];
    pid_t pid;

    // Create the pipe
    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create the child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // child process
        // Close the read end of the pipe
        close(pipefds[0]);

        // Write a message to the pipe
        char* message = "Hello, parent!";
        if (write(pipefds[1], message, BUFFER_SIZE) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Close the write end of the pipe
        close(pipefds[1]);
        exit(EXIT_SUCCESS);
    } else { // parent process
        // Close the write end of the pipe
        close(pipefds[1]);

        // Read the message from the pipe
        if (read(pipefds[0], buffer, BUFFER_SIZE) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);

        // Close the read end of the pipe
        close(pipefds[0]);
        exit(EXIT_SUCCESS);
    }
} 
