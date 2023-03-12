#include "../colors.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat sb;

int cd(char *path) {
  int status = stat(path, &sb);
  if (status == -1) {
    printf(ANSI_COLOR_RED "Path does not Exist!\n" ANSI_COLOR_RESET);
    return -1;
  } else if (S_ISDIR(sb.st_mode) == 0) {
    printf(ANSI_COLOR_RED
           "Not a Directory!\n" ANSI_COLOR_RESET); // Check if argument is a
                                                   // file or directory
  } else {
    chdir(path);
    char b[256];
    getcwd(b, 256);
  }
  return 0;
}
