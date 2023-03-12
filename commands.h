#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./utils/cd.h"
#include "./utils/clear.h"
#include "./utils/tokenizer.h"

int process_command(char *command) {
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
    cd(tokens[1]);
  } else {
    return -1;
  }
  return 0;
}
