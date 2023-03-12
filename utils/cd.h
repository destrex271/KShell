#include "../colors.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat sb;

int cd(char *path) {
  char abs_path[512];
  getcwd(abs_path, 512);
  strcat(abs_path, "/");
  strcat(abs_path, path);
  if (stat(abs_path, &sb) == -1) {
    printf(ANSI_COLOR_RED "Path does not Exist!\n");
    return -1;
  } else {
    chdir(abs_path);
    char b[256];
    getcwd(b, 256);
  }
  return 0;
}
