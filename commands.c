#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./utils/cd.c"
#include "./utils/clear.c"
#include "./utils/ls.c"
#include "./utils/pwd.c"
#include "./utils/sysCommand.c"
#include "./utils/tokenizer.c"

int process_command(char *command) {
  char tp[100];
  strcpy(tp, command);
  command = strtok(command, "\n");
  if (strcmp(command, "clear") == 0) {
    clear_scr();
    return 0;
  }
  if (strcmp(command, "exit") == 0) {
    exit(0);
  }
  char tokens[10][256];
  int len = tokenizer(command, strlen(command), tokens);
  char *curCommand = tokens[0];
  if (strcmp(curCommand, "cd") == 0) {
    if (len > 2) {
      printf(ANSI_COLOR_RED "Too many arguments!\n" ANSI_COLOR_RESET);
      return 0;
    }
    cd(tokens[1]);
  } else if (strcmp(curCommand, "ls") == 0) {
    if (len > 1) {
      char cmd[100] = "";
      for (int i = 1; i < len; i++) {
        strcat(cmd, " ");
        strcat(cmd, tokens[i]);
      }
      return lsAll(cmd);
    }
    return ls();
  } else if (strcmp(curCommand, "pwd") == 0) {
    pwd();
  } else {
    /* execi(command); */
    char **args = (char **)malloc(len);
    for (int i = 0; i < len; i++) {
      args = malloc(256);
    }
    for (int i = 0; i < len; i++) {
      args[i] = tokens[i];
    }
    return execute(args, len);
    /* return -1; */
  }
  return 0;
}
