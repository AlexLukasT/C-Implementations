#include <stdio.h>
#include "linked_list.h"

int main(int argc, char *argv[])
{
  node_t *head = NULL;

  linked_list_append(&head, 1);
  linked_list_print(head);

  linked_list_append(&head, 2);
  linked_list_print(head);

  linked_list_append(&head, 3);
  linked_list_print(head);

  linked_list_insert(&head, 1, 6);
  linked_list_print(head);

  linked_list_insert(&head, 4, 4);
  linked_list_print(head);

  int val = linked_list_pop(&head, 2);
  printf("Popped %i\n", val);
  linked_list_print(head);

  return 0;
}

