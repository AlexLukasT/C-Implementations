#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int val;
  struct node *next;
} node_t;

bool linked_list_is_empty(node_t *head);
void linked_list_insert(node_t **head, int index, int new_val);
void linked_list_append(node_t **head, int new_val);
int linked_list_size(node_t *head);
void linked_list_print(node_t *head);
int linked_list_pop(node_t **head, int index);
node_t *_linked_list_get_last_node(node_t *head, int *ret_size);
node_t *_linked_list_get_node_at(node_t *head, int index);
