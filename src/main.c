#include "builtins.h"
#include "parser.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_CANON 4096

int main(void) {
  char buffer[MAX_CANON];
  char **args = NULL;
  pid_t pid = 0;

  while (printf("> "), fflush(stdout), fgets(buffer, sizeof(buffer), stdin)) {
    str_cut(buffer);

    args = split_line(buffer);

    if (args != NULL && args[0] != NULL) {
      int status = is_builtin(args);

      if (status == 0) {
        free(args);
        break;
      }

      if (status == -1)

      {
        pid = fork();

        if (pid < 0) {
          perror("fork");
        }

        else if (pid == 0) {
          if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
          }
        }

        else {
          wait(NULL);
        }
      }

      free(args);
    }
  }
  return 0;
}
