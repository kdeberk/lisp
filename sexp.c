#include "sexp.h"

#include <stdio.h>
#include "string.h"
#include "type.h"

void __print_sexp_integer(struct typed_value *);

const struct type sexp_type_integer = {
  .name = "integer",
  .print = __print_sexp_integer,
  .free = 0x00, // TODO
};

struct sexp_integer * sexp_new_integer(long val) {
  struct sexp_integer * res;

  res = malloc(sizeof(struct sexp_integer));
  res->type = &sexp_type_integer;
  res->val = val;
  return res;
}

void __print_sexp_integer(struct typed_value * val) {
  struct sexp_integer * sexp = (struct sexp_integer *) val;
  printf("%lu", sexp->val);
}



void __print_sexp_list(struct typed_value *);

const struct type sexp_type_list = {
  .name = "list",
  .print = __print_sexp_list,
  .free = 0x00, // TODO
};

struct sexp_list * sexp_new_list(struct linked_list * lst) {
  struct sexp_list * res;

  res = malloc(sizeof(struct sexp_list));
  res->type = &sexp_type_list;
  res->head = lst;
  return res;
}

void __print_sexp_list(struct typed_value * val) {
  boolean first;
  struct linked_list * cur;

  first = true;
  cur = ((struct sexp_list *) val)->head;

  printf("(");
  while(cur != 0x00) {
    if(!first) {
      printf(" ");
    }
    first = false;

    typed_value_print(cur->val);
    cur = cur->nxt;
  }

  printf(")");
}

void __print_sexp_symbol(struct typed_value *);

const struct type sexp_type_symbol = {
  .name = "symbol",
  .print = __print_sexp_symbol,
  .free = 0x00, // TODO
};

struct sexp_symbol * sexp_new_symbol(char * name, size_t len) {
  struct sexp_symbol * res;

  UNUSED(len);
  UNUSED(name);

  res = malloc(sizeof(struct sexp_symbol));
  res->type = &sexp_type_symbol;
  res->name = string_clone(name, len);
  // TODO: copy the string
  return res;
}

void __print_sexp_symbol(struct typed_value * val) {
  struct sexp_symbol * sexp = (struct sexp_symbol *) val;
  printf("%s", sexp->name);
}
