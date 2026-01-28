#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Welcome to ShellOS\n");

    pid_t pid = fork();

    if (pid == 0) {
        char *args[] = {"/bin/sh", NULL};
        execv("/bin/sh", args);
        perror("Failed to start shell");
        exit(1);
    } else {
        while(1) {
            wait(NULL);
        }
    }
}
