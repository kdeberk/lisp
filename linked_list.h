#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct linked_list {
  void * val;
  struct linked_list * nxt;
};

// modifies @prv
// moves @val
struct linked_list * list_add_value(struct linked_list *prv, void * val);
// moves @lst
void list_free(struct linked_list * lst);

#endif
