#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 50

int main()
{
  List *history = init_history();
  while(1){
    printf("Welcome to Didi's Tokenizer! Enter a string, 'h' for history or 'q' to quit\n");
    printf(">");
    char buf[MAX];
    fgets(buf, MAX, stdin);
    if(str_len(&buf[0]) == 2 && buf[0] == 'q' ){
      free_history(history);
      break;
    }
    else if(str_len(&buf[0]) <= 1){
      printf("No input given! Please try again.\n");
      continue;
    }
    else if(str_len(&buf[0]) == 2 && buf[0] == 'h')
      history_ui(history);
    else{
      short len = str_len(&buf[0]);
      char *s = malloc(len*sizeof(char));
      s = copy_str(&buf[0], len);
      //printf("%s", buf);
      //printf("%d\n", space_char(' '));
      //printf("%d\n", non_space_char(' '));
      add_history(history, s);
      //printf("Length: %d\n", len);
      //int num_words = count_tokens(&buf[0]);
      //printf("%s\n", p);
      char **t = tokenize(&buf[0]);
      print_tokens(t);
      printf("\n");
      //printf("\nin main: %sdododo\n", *(t+2));
      free_tokens(t);
      printf("Success\n");
    }
  }
  printf("Goodbye!\n");
  return 0;
}

short str_len(char *str)
{
  char *p = str;
  while(*p != '\0'){
    p++;
  }
  return (p-str);
}

void history_ui(List *history)
{
  print_history(history);
  printf("Which item would you like to tokenize?\n>");
  char response[MAX];
  fgets(response, MAX, stdin);
  if(response[0] >= '1' && response[0] <='9'){
    int id = response[0] - '0';
    char *str = get_history(history, id);
    if(str){
      char **t = tokenize(str);
      print_tokens(t);
      printf("\n");
      free_tokens(t);
      return;
    }
    else{
      printf("\nInvalid id!");
    }
  }
  else{
    printf("\nInvalid input!");
    return;
  }
}
