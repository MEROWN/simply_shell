#include "builtins.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *builtin_str[] = {
#define X(name, func) name,
    BUILTIN_TABLE
#undef X
};

int (*builtin_func[]) (char **) = {
#define X(name, func) &func,
    BUILTIN_TABLE
#undef X
};

int shell_exit(char** args)
{
    return 0;
}

int shell_cd(char** args)
{
   if (args[1] == NULL)
    {
    char* target = getenv("HOME");
    if (target != NULL && chdir(target) != 0)
	perror("shell");
    }
   else {
    if (chdir(args[1]) != 0)
	perror("shell");
   }
   return 1;
}

int shell_help(char** args)
{
    int n = sizeof(builtin_str) / sizeof(char*);
    printf("Use 'man -k' or 'info' to find out more about commands not in this list.\n");

    for (int i = 0; i < n; i++) 
    {
	printf("%s \n", builtin_str[i]);
    }
    return 1;
}

int builtin_count()
{
    return sizeof(builtin_str) / sizeof(char*);
};

int is_builtin(char** args)
{

    if (args == NULL || args[0] == NULL)
    {
	return 1;
    }

    for (int i = 0; i < builtin_count(); i++) 
    {
	if (strcmp(builtin_str[i], args[0]) == 0)
	{
	    return builtin_func[i](args);
	}
    }
    return -1; 
}

