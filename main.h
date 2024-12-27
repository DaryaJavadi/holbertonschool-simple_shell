#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

char *get_path(void);
char *get_full_path(char *arg, int *status);
void set_argv(char *buffer, char ***argv);
void execute(char **argv, int *status);

#endif
