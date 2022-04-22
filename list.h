#include <stdio.h>
#include <stdbool.h>
struct node* list_insert(struct node* list, char* data); 

bool list_contains(struct node* list, char* test_data);

void list_print_data(struct node *list);