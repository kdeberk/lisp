#ifndef __BINARY_SEARCH_TREE
#define __BINARY_SEARCH_TREE

#include <stdlib.h>

// TODO: this can be placed more generally?
typedef int (*compareFn)(void * a, void * b);

struct node;

struct binary_search_tree {
  size_t n_items;
  struct node * head;
  compareFn * fn;
};

struct binary_search_tree * binary_search_tree_new(compareFn * fn);
void * binary_search_tree_add(void * item);

#endif
