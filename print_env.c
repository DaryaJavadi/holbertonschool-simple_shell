/**
* print_env - Print the current environment variables
* @env: The environment variable to print
*
* This function prints all environment variables for the program.
*/

/**
 * print_env - prints the environment variables
 */
void print_env(void)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

/**
 * execute - executes the given program or handles built-ins
 * @argv: argument vector
 * @status: variable for exit status
 */
void execute(char **argv, int *status)
{
    pid_t pid;
    char *command;

    if (argv[0] == NULL)
        return;

    if (strcmp(argv[0], "exit") == 0)
    {
        free(argv);
        exit(*status);
    }

    if (strcmp(argv[0], "env") == 0)
    {
        print_env();
        return;
    }

    command = get_full_path(argv[0], status);
    if (command == NULL)
        return;

    pid = fork();
    if (pid == 0)
    {
        if (execve(command, argv, environ) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0)
    {
        wait(NULL);
        free(command);
    }
    else
    {
        perror("Fork failed");
        free(command);
    }
}
