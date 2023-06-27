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
  short len = str_len(&buf[0]);
  char *p = copy_str((&buf[0]), len);
  printf("Length: %d\n", len);
  int num_words = count_tokens(&buf[0]);
  printf("%s\n", p);
  char **t = tokenize(p);
  printf("%s\n", *t);
}

short str_len(char *str)
{
  char *p = str;
  while(*str != '\0'){
    str++;
  }
  return (str-p);
}


