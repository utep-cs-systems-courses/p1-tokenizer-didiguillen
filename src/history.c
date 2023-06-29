#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  Item *root = malloc(sizeof(Item));
  char *n_str = malloc(sizeof(char));
  *n_str = '\0';
  *root->str = n_str;
  List *new_list = malloc(sizeof(List));
  *new_list->root = root;
  return new_list;
}

void add_history(List *list, char *str)
{
  List *copy_list = list;
  if(*copy_list->*root->*str == '\0'){
    Item *curr_item = *copy_list->root;
    Item *new_item = malloc(sizeof(Item));
    *new_item->id = 1;
    short len = str_len(str);
    char *new_str = copy_str(str, len);
    *new_item->str = new_str;
    *new_item->next = curr_item;
    *curr_item->id = 2;
    *list->root = new_item;
  }
  else{
    Item *curr_item = *copy_list->root;
    int count = 1;
    while(*curr_item->*str != '\0'){
      curr_item = curr_item->next;
      count++;
    }
    curr_item--;
    Item *new_item = malloc(sizeof(Item));
    *new_item->id = count;
    short len = str_len(str);
    char *new_str = copy_str(str, len);
    *new_item->str = new_str;
    *new_item->next = curr_item+1;
    *curr_item->next = new_item;
    *(curr_item+1)->id = count+1;
  }
}

char *get_history(List *list, int id)
{
  List *tmp_list = list;
  Item *curr_item = *tmp_list->root;
  while(*curr_item->id != id){
    curr_item = *curr_item->next;
  }
  if(*curr_item->id == id){
    return *curr_item->str;
  }
  else
    return NULL;
}

void print_history(List *list)
{
  List *tmp_list = list;
  Item *curr_item = *tmp_list->root;
  while(*curr_item->*str != '\0'){
    printf("%d. %s\n", *curr_item->id, *curr_item->str);
    curr_item = *curr_item->next;
  }
}

void free_history(List *list)
{
  
}
