#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "#cisfun$ "
#define BUFFER_SIZE 1024

int main(void)
{
    char buffer[BUFFER_SIZE];
    char *args[2];

    while (1)
    {
        printf("%s", PROMPT);
        fflush(stdout);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
        {
            printf("\n");
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0)
            continue;

        args[0] = buffer;
        args[1] = NULL;

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("Error forking");
            continue;
        }
        else if (pid == 0)
        {
            if (execve(args[0], args, environ) == -1)
            {
                perror(args[0]);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

