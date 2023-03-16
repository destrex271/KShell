#include <stdio.h>
#include <string.h>

int tokenizer(char *command, int size, char tokens[10][256]) {
  char *c = strtok(command, " ");
  int k = 0;
  do {
    strcpy(tokens[k], c);
    k++;
    /* printf("%s", tokens[k]); */
    c = strtok(NULL, " ");
  } while (c != NULL);
  return k;
}
