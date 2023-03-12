#include "../colors.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat sb;

int cd(char *abs_path) {
  int status = stat(abs_path, &sb);
  if (status == -1) {
    printf(ANSI_COLOR_RED "Path does not Exist!\n" ANSI_COLOR_RESET);
    return -1;
  } else if (S_ISDIR(sb.st_mode) == 0) {
    printf(ANSI_COLOR_RED
           "Not a Directory!\n" ANSI_COLOR_RESET); // Check if argument is a
                                                   // file or directory
  } else {
    chdir(abs_path);
    char b[256];
    getcwd(b, 256);
  }
  return 0;
}

int rel_cd(char *path) {
  char abs_path[512];
  getcwd(abs_path, 512);
  strcat(abs_path, "/");
  strcat(abs_path, path);
  return cd(abs_path);
}
