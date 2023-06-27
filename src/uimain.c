#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAX 50

int main()
{
  printf(">");
  char buf[MAX];
  fgets(buf, MAX, stdin);
  printf("%s", buf);
  printf("%d\n", space_char(' '));
  printf("%d\n", non_space_char(' '));
  char *p = malloc(MAX*sizeof(char));
  *p = *copy_str((&buf[0]), MAX);
  printf("%s\n", *p);
}
