#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//This method checks whether the char is a space or not
int space_char(char c)
{
  if(c == ' ' || c == '\n' || c == '\t')
    return 1;
  else
    return 0;
}

//This method checks for a character that is not a space
int non_space_char(char c)
{
  if(space_char(c) || c == '\0')
    return 0;
  else
    return 1;
}

//This method makes a copy of the given string and returns a pointer to the copy.
char *copy_str(char *inStr, short len)
{
  char *p = malloc(sizeof(char)*(len+1));
  for(int i = 0; i < len; i++){
    *p = *inStr;
    p++;
    inStr++;
  }
  if(*p != '\0'){ 
    *p = '\0';
  }
  p = p - len;
  return p;
}

//This method determines the start of a token (the first non-space char)
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

//This method determines the end of a token (searches for the nearest space char)
char *token_terminator(char *token)
{
  char *p = token;
  while(non_space_char(*p))
    p++;
  return p;
}

//This method counts the number of tokens in a string
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
  return num_tokens;
}

//This method tokenizes a string
char **tokenize(char *str)
{
  int num_tokens = count_tokens(str);
  //If there are no tokens, there's nothing to tokenize
  if(num_tokens){
    char **p = malloc((num_tokens+1)*sizeof(char*));
    int counter = 1; //at least one token exists
    char *start = token_start(str);
    while(counter <= num_tokens){
      char *end = token_terminator(start);
      short len = end - start;
      char *token = copy_str(start, len);
      *p = token;
      p++;
      start = token_start(end); //start = next token starting after previous token
      counter++;
    }
    char *end_str = malloc(sizeof(char)); //char pointer to contain string terminator
    *end_str = '\0';
    *p = end_str;
    p = p - num_tokens; //pointer now points at beginning of token vector
    return p;
  }
  else
    return NULL;
}

//This method prints tokens from the given token vector
void print_tokens(char **tokens)
{
  while(**tokens != '\0'){
    printf("\"%s\" ", *tokens);
    tokens++;
  }
}

//This method frees the tokens and token vector from memory
void free_tokens(char **tokens)
{
  int counter = 0;
  while(**tokens != '\0'){
    free(*tokens);
    tokens++;
    counter++;
  }
  free(*tokens);
  tokens = tokens - (counter);
  free(tokens);
}
