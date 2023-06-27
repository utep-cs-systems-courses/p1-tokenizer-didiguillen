#include <stdio.h>
#include "tokenizer.h"

#define MAX 5000

int main()
{
  printf(">");
  char buf[MAX];
  fgets(buf, MAX, stdin);
  printf("%s", buf);
  printf("%d\n", space_char(' '));
  printf("%d\n", non_space_char(' '));
  char *s = copy_str(buf, MAX);
  printf("%s", *s);
}
