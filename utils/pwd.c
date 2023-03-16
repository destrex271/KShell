#include <stdio.h>
#include <unistd.h>
int pwd() {
  char path[100];
  getcwd(path, 100);
  printf("You are in : %s\n", path);
  return 0;
}
