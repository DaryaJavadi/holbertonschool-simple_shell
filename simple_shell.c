#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
	char *args[] = {command, NULL};
        if (execve(command, args, environ) == -1)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
        }
	}
	else
	{
        	int status;
        	waitpid(pid, &status, 0);
	}
}

int main(void)
{
    char input[MAX_INPUT_SIZE];
    char *command;

    while (1)
{
	printf("#cisfun$ ");
	fflush(stdout);

	if (!fgets(input, sizeof(input), stdin))
	{
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		else
		{
			perror("fgets");
			continue;
		}
	}

	input[strcspn(input, "\n")] = 0;

	if (strlen(input) == 0)
	{
		continue;
	}

	command = input;

        if (access(command, F_OK) == 0)
	{
		execute_command(command);
	}
	else
	{
		fprintf(stderr, "./shell: No such file or directory\n");
	}
	}

	return (0);
}
