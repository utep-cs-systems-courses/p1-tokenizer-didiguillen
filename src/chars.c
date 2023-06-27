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
  if(space_char(c))
    return 0;
  else
    return 1;
}

char *copy_str(char *inStr, short len)
{
  char *p = (char *) malloc(sizeof(char)*len);
  for(int i = 0; i < len; i++){
    *p = *inStr;
    p++;
    inStr++;
  }
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
  if(*p == '\0' || *p == ' ')
    return p;
}

int count_tokens(char *str)
{
  char *p = str;
  int num_tokens = 0;
  while(*p != '\0'){
    if(space_char(*p)){
      continue;
    }
    else if(non_space_char){
      char* bw = token_start(p);
      char* ew = token_terminator(bw);
      p = ew;
      num_tokens++;
    }
  }
  return num_tokens;
}
