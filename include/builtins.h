#ifndef BUILTINS_H
#define BUILTINS_H

#define BUILTIN_TABLE \
    X("cd", shell_cd) \
    X("exit", shell_exit)

#define X(name, func) int func(char **args);
BUILTIN_TABLE
#undef X

int is_builtin(char **args);

#endif
