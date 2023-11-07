#include "linked_list.h"

#include <stdlib.h>

struct linked_list * list_add_value(struct linked_list *prv, void * val) {
  struct linked_list * cell = malloc(sizeof(struct linked_list));
  cell->val = val;
  cell->nxt = 0x00;

  if(prv != 0x00) {
    prv->nxt = cell;
  }

  return cell;
}
