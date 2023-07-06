#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

//This method initializes the linked list for history
List *init_history()
{
  List *new_list = malloc(sizeof(List));
  new_list->root = NULL;
  return new_list;
}

//This method adds a new item to the linked list
void add_history(List *list, char *str)
{
  List *copy_list = list;
  // linked list is empty, new node is root
  if(!(copy_list->root)){
    Item *new_item = malloc(sizeof(Item));
    new_item->id = 1;
    short len = str_len(str);
    new_item->str = copy_str(str, len);
    list->root = new_item;
  }
  else{
    Item *curr_item = copy_list->root;
    int curr_id = copy_list->root->id;
    // determines the last node in the list
    while(curr_item){
      curr_id = curr_item->id;
      if(curr_item->next)
	curr_item = curr_item->next;
      else
	break;
    }
    Item *new_item = malloc(sizeof(Item));
    new_item->id = curr_id+1;
    short len = str_len(str);
    new_item->str = copy_str(str, len);
    curr_item->next = new_item; // adds new node to end of linked list 
  }
}

//This method returns the string stored in the requested node
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

//This method prints out the ids and strings of all elements in the linked list
void print_history(List *list)
{
  List *tmp_list = list;
  Item *curr_item = tmp_list->root;
  while(curr_item){
    printf("%d. %s\n", curr_item->id, curr_item->str);
    curr_item = curr_item->next;
  }
}

//This method frees the nodes and list from memory
void free_history(List *list)
{
  while(list->root){
    Item *new_root = list->root->next;
    free(list->root);
    list->root = new_root;
  }
  free(list);
}
