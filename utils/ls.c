#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int ls() {
  system("ls");
  return 0;
}

int lsAll(char *args) {
  char cmd[102] = "ls";
  strcat(cmd, args);
  return system(cmd);
}
