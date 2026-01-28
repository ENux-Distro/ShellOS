#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 64

int main() {
    char input[MAX_CMD_LEN];
    char *args[MAX_ARGS];

    setenv("PATH", "/bin", 1);

    while (1) {
        printf("# ");

        if (fgets(input, MAX_CMD_LEN, stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = 0;


        int i = 0;
        char *token = strtok(input, " ");
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (args[0] == NULL) continue; 


        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                printf("cd: argument missing\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("cd");
                }
            }
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            printf("Command not found: %s\n", args[0]);
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("fork failed");
        }
    }
    return 0;
}
