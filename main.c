#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./colors.h"
#include "./commands.c"
#include <signal.h>

// Global Variables
char *user;
char hostname[200];
char curPath[512];

void prompt_t() {
  printf("%d\n", getpid());
  printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, user);
  printf(ANSI_COLOR_BLUE "@" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, hostname);
  printf(ANSI_COLOR_CYAN " | " ANSI_COLOR_RESET);
  printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET, curPath);
  printf(ANSI_COLOR_CYAN " > " ANSI_COLOR_RESET);
}

void signalHandler(int sig_num) {
  signal(sig_num, signalHandler);
  printf("\n");
  prompt_t();
  fflush(stdout);
}

int getInput(char *command) {
  size_t s = 512;
  strcpy(command, "\0");
  getline(&command, &s, stdin);
  if (strcmp(command, "\n") == 0) {
    return -1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  signal(SIGINT, signalHandler);

  bool exit = false;

  // Get Hostname and user
  user = getlogin();
  gethostname(hostname, 200);
  char homePath[512] = "/home/";
  strcat(homePath, user);
  chdir(homePath);

  while (!exit) {
    getcwd(curPath, 512);
    // take input
    prompt_t();
    char command[512];
    strcpy(command, "");
    int x = getInput(command);
    if (x == -1)
      continue;
    // Process input
    int status = process_command(command);
    // Give output
    if (status == -1) {
      printf(ANSI_COLOR_RED "Command Not Found!\n");
    }
  }
  return 0;
}
