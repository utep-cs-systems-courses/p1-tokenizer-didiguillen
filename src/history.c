#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *new_list = malloc(sizeof(List));
  new_list->root = NULL;
  return new_list;
}

void add_history(List *list, char *str)
{
  printf("In add history\n");
  List *copy_list = list;
  if(!(copy_list->root)){
    Item *new_item = malloc(sizeof(Item));
    new_item->id = 1;
    short len = str_len(str);
    printf("in add_history %s\n",str);
    new_item->str = copy_str(str, len+1);
    printf("str in node: %s", new_item->str);
    list->root = new_item;
  }
  else{
    printf("before accessing copy_list->root\n");
    Item *curr_item = copy_list->root;
    printf("after accessing copy_list->root\n");
    int curr_id = copy_list->root->id;
    printf("after getting id %d\n", curr_id);
    while(curr_item){
      curr_id = curr_item->id;
      printf("%d. %s\n", curr_id, curr_item->str);
      if(curr_item->next)
	curr_item = curr_item->next;
      else
	break;
    }
    Item *new_item = malloc(sizeof(Item));
    new_item->id = curr_id+1;
    short len = str_len(str);
    new_item->str = copy_str(str, len+1);
    curr_item->next = new_item;
  }
}

char *get_history(List *list, int id)
{
  List *tmp_list = list;
  Item *curr_item = tmp_list->root;
  while(curr_item && (curr_item->id != id)){
    curr_item = curr_item->next;
  }
  if(curr_item && (curr_item->id == id)){
    return curr_item->str;
  }
  else
    return NULL;
}

void print_history(List *list)
{
  List *tmp_list = list;
  Item *curr_item = tmp_list->root;
  while(curr_item){
    printf("%d. %s\n", curr_item->id, curr_item->str);
    curr_item = curr_item->next;
  }
}

void free_history(List *list)
{
  while(list->root){
    Item *new_root = list->root->next;
    free(list->root);
    list->root = new_root;
  }
  free(list);
}
