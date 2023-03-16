#include "../colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int execute(char *tokens[256], size_t len) {
  int stat;
  int pid = fork();

  if (pid == 0) {
    execvp(tokens[0], tokens);
    printf(ANSI_COLOR_RED "Command Not Found!\n");
    exit(0);
  } else if (pid < 0) {
    printf("Cannot Fork!\n");
  } else {
    wait(&stat);
  }
  printf("Status : %d\n", stat);
  return stat;
}
