#include <stdio.h>
#include <stdlib.h>

/**
 * print_env - prints all environment variables
 */
void print_env(void)
{
    extern char **environ;
    char **env = environ;

    if (!env || !*env)
    {
        return;
    }

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

