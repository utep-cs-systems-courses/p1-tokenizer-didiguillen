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
    //printf("%c ", *p);
    p++;
    inStr++;
  }
  //printf("%c ", *p);
  if(*p != '\0'){
    *(p+1) = '\0';
    p++;
  }
  p = p - len;
  //printf("%c ", *p);
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
  int num_tokens = 0;
  str = token_start(str);
  while(*str != '\0'){
    if(non_space_char(*str)){
      //printf("found nonspace %c\n", *str);  
      str = token_terminator(str);
      //printf("token end %c\n", *str);
      //printf("new p%c\n", *str);
      num_tokens++;
    }
    else{
      str++;
      continue;
    }
  }
  printf("num tokens: %d\n", num_tokens);
  return num_tokens;
}

char **tokenize(char *str)
{
  int num_tokens = count_tokens(str);
  if(num_tokens){
    char **p = malloc((num_tokens+1)*sizeof(char*));
    int counter = 0;
    char *start = token_start(str);
    while(counter < num_tokens){
      short len = token_terminator(start) - start;
      char *token = copy_str(start, len);
      printf("in tokenize while loop %d: %s\n", counter,token);
      *p = token;
      p++;
      start = token_start(str+len);
      printf("token terminator: %s", start);
      counter++;
    }
    char *end_str = malloc(sizeof(char));
    *end_str = '\0';
    *p = end_str;
    p = p - num_tokens;
    return p;
  }
  else
    return NULL;
}
