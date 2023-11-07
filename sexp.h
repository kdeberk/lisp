#ifndef __LISP_H__
#define __LISP_H__

#include <stdlib.h>

#include "constants.h"
#include "linked_list.h"
#include "type.h"

extern const struct type sexp_type_integer;

struct sexp_integer {
  const struct type * type;
  long val;
};

// borrows @val;
struct sexp_integer * sexp_new_integer(long val);



extern const struct type sexp_type_list;

struct sexp_list {
  const struct type * type;
  struct linked_list * head;
};

// moves @lst;
struct sexp_list * sexp_new_list(struct linked_list * lst);



extern const struct type sexp_type_symbol;

struct sexp_symbol {
  const struct type * type;
  size_t len;
  char * name;
};

// borrows @name
// borrows @len
struct sexp_symbol * sexp_new_symbol(char * name, size_t len);

#endif
