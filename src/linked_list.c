#include <stdio.h>
#include "linked_list.h"

bool linked_list_is_empty(node_t *head)
{
  if (head == NULL) {
    return true;
  }
  return false;
}

void linked_list_insert(node_t **head, int index, int new_val)
{
  const int size = linked_list_size(*head);

  // allocate a new node
  node_t *new_node = malloc(sizeof(node_t));
  if (new_node == NULL)
  {
    fprintf(stderr, "Could not allocate memory for next node");
  }
  // set the value on the new node
  new_node->val = new_val;

  if (index < 0 || index > size)
  {
    return;
  } 
  else if (index == 0)
  {
    // list is still empty: create first node and point head to it
    *head = new_node;
    new_node->next = NULL;
  }
  else if (index == size)
  {
    node_t *last_node = _linked_list_get_last_node(*head, NULL);
    last_node->next = new_node;
    new_node->next = NULL;
  } 
  else
  {
    node_t *previous_node = _linked_list_get_node_at(*head, index - 1);
    node_t *next_node = _linked_list_get_node_at(*head, index);
    previous_node->next = new_node;
    new_node->next = next_node;
  }
}

void linked_list_append(node_t **head, int new_val)
{
  linked_list_insert(head, linked_list_size(*head), new_val);
}

int linked_list_size(node_t *head)
{
  int *size = malloc(sizeof size);
  _linked_list_get_last_node(head, size);
  return *size;
}

void linked_list_print(node_t *head)
{
  node_t *current = head;
  printf("|");
  while (current != NULL) {
    printf(" %i |", current->val);
    current = current->next;
  }
  printf("\n");
}

int linked_list_pop(node_t **head, int index)
{
  const int size = linked_list_size(*head);

  int val;
  if (index < 0 || index > size - 1)
  {
    fprintf(stderr, "Index out of range");
    return 0;
  }
  else if (index == 0)
  {
    // pop first element
    node_t *first_node = _linked_list_get_node_at(*head, 0);
    if (size == 1) {
      // list has only one element -> set head to NULL
      *head = NULL;
    } else {
      node_t *second_node = _linked_list_get_node_at(*head, 1);
      *head = second_node;
    }
    val = first_node->val;
    free(first_node);
  }
  else if (index == size - 1)
  {
    node_t *last_node = _linked_list_get_node_at(*head, size - 1);
    if (size == 1) {
      *head = NULL;
    } else {
      node_t *second_last_node = _linked_list_get_node_at(*head, size - 2);
      second_last_node->next = NULL;
    }
    val = last_node->val;
    free(last_node);
  }
  else
  {
    node_t *previous_node = _linked_list_get_node_at(*head, index - 1);
    node_t *current_node = _linked_list_get_node_at(*head, index);
    node_t *next_node = _linked_list_get_node_at(*head, index + 1);
    previous_node->next = next_node;
    val = current_node->val;
    free(current_node);
  }

  return val;
}

node_t *_linked_list_get_last_node(node_t *head, int *ret_size)
{
  // find the latest node of the list and count the size along the way
  node_t *current = head;
  int size;
  if (head != NULL) {
    size = 1;
    while (current->next != NULL) {
      current = current->next;
      size++;
    }
  } else {
    size = 0;
  }

  if (ret_size != NULL) {
    *ret_size = size;
  }

  return current;
}

node_t *_linked_list_get_node_at(node_t *head, int index)
{
  node_t *current = head;
  int counter = 0;
  while (counter < index) {
    current = current->next;
    counter++;
  }
  return current;
}
