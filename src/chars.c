#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\n' || c == '\t')
    return 1;
  else
    return 0;
}

int non_space_char(char c)
{
  if(space_char(c) || c == '\0')
    return 0;
  else
    return 1;
}

char *copy_str(char *inStr, short len)
{
  char *p = malloc(sizeof(char)*(len+1));
  for(int i = 0; i < len; i++){
    *p = *inStr;
    printf("%c ", *p);
    p++;
    inStr++;
  }
  printf("%c ", *p);
  if(*p != '\0'){
    *(p+1) = '\0';
    p++;
  }
  p = p - len;
  printf("%c ", *p);
  return p;
}

char *token_start(char *str)
{
  char *p = str;
  if(non_space_char(*p))
    return p;
  while(space_char(*p)){
    p++;
  }
  if(*p == '\0'){
    p = 0;
  }
  return p;
}

char *token_terminator(char *token)
{
  char *p = token;
  while(non_space_char(*p))
    p++;
  return p;
}

int count_tokens(char *str)
{
  char *p = str;
  int num_tokens = 0;
  while(*p != '\0'){
    char *bw = token_start(p);
    if(bw){
      printf("found nonspace %c\n", *bw);  
      char *ew = token_terminator(bw);
      printf("token end %c\n", *ew);
      if(*ew == '\0')
	num_tokens++;
	break;
      printf("new p%c\n", *p);
      num_tokens++;
    }
    printf("numtokens: %d\n", num_tokens);
  }
  printf("%d\n", num_tokens);
  return num_tokens;
}
