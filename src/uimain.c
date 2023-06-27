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
  short len = token_terminator(&buf[0]) - token_start(&buf[0]);
  char *p = malloc((len+1)*sizeof(char));
  printf("Length: %d\n", len);
  p = copy_str((&buf[0]), len);
  printf("%s\n", *p);
}


