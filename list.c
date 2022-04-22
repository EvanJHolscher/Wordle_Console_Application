#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

struct node{
  char* data;
  struct node* next;
};

struct node* list_insert(struct node*list, char* data){
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = malloc(sizeof(data));
  strcpy(new_node->data,data);
  new_node->next = NULL;
  if (list == NULL){
    return new_node;
  }
  if (list!=NULL){
    new_node->next = list;
  }

  return new_node;
}

bool list_contains(struct node* list, char* test_data){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp = list;
  if (list == NULL){
    return false;
  }
  while(temp){
    if ((int)(strcmp(temp->data,test_data)) == 0){
      return true;
    }
    else temp = temp->next;
  }
  return 0;
}

void list_print_data(struct node *list){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  if (list == NULL){
      printf("Cannot print a NULL list\n");
  }
  else{
    temp = list;
    while(temp){
      printf("%s \n", temp->data);
      temp = temp->next;
    }
  }
}