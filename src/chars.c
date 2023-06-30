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
  printf("in copy_str: ");
  for(int i = 0; i < len; i++){
    *p = *inStr;
    printf("%c ", *p);
    p++;
    inStr++;
  }
  //printf("%c ", *p);
  if(*p != '\0'){
    printf("in if stmt copy_str %c\n",*p); 
    *p = '\0';
  }
  printf("p value 1: %c \n", *p);
  p = p - len;
  printf("p value 2: %c \n", *p);
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
    *p = '\0';
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
  char *tmp_str = str;
  while(*tmp_str != '\0'){
    if(non_space_char(*tmp_str)){
      num_tokens++;
      tmp_str = token_terminator(tmp_str);
    }
    else
      tmp_str++;
  }
  printf("num tokens: %d\n", num_tokens);
  return num_tokens;
}

char **tokenize(char *str)
{
  int num_tokens = count_tokens(str);
  if(num_tokens){
    char **p = malloc((num_tokens+1)*sizeof(char*));
    int counter = 1;
    char *start = token_start(str);
    printf("token_start: %c\n", *start);
    while(counter <= num_tokens){
      char *end = token_terminator(start);
      printf("token terminator: %c\n",*end);
      short len = end - start;
      printf("Length of token: %d\n", len);
      char *token = copy_str(start, len);
      printf("in tokenize while loop %d: %s\n", counter,token);
      *p = token;
      p++;
      start = token_start(end);
      printf("next token start: %c\n", *start);
      // printf("token terminator: %s", start);
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

void print_tokens(char **tokens)
{
  while(**tokens != '\0'){
    printf("\"%s\" ", *tokens);
    tokens++;
  }
}

void free_tokens(char **tokens)
{
  int counter = 0;
  while(**tokens != '\0'){
    free(*tokens);
    tokens++;
    printf("free_tokens while loop\n");
    counter++;
  }
  free(*tokens);
  tokens = tokens - (counter);
  free(tokens);
}
