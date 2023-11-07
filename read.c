#include "read.h"

#include <stdlib.h>
#include "linked_list.h"
#include "sexp.h"
#include <stdio.h>

struct result * __read_sexp(char ** str);
struct result * __read_list(char ** str);
struct result * __read_integer(char ** str);
struct result * __read_symbol(char ** str);

struct result * read_sexp(char * str) {
  char * s;
  struct result * res;

  s = str;
  if(*s == 0x00) {
    return result_null();
  }

  res = __read_sexp(&s);
  if(!res->ok) {
    return res;
  }

  if(*s != 0x00) {
    return result_err(error_fmt("trailing junk: '%.5s'", s));
  }

  return res;
}

struct result * __read_sexp(char ** str) {
  char * s;
  struct result * res;

  s = *str;
  while(' ' == *s) { s++; }

  if('0' <= *s && *s <= '9') {
    res = __read_integer(&s);
  } else if('(' == *s) {
    res = __read_list(&s);
  } else {
    res = __read_symbol(&s);
  }

  if(res->ok) {
    *str = s;
  }
  return res;
}

struct result * __read_integer(char ** str) {
  char * s;
  long val;

  s = *str;
  val = 0;
  while('0' <= *s && *s < '9') {
    val = val * 10 + (*s - '0');
    s++;
  }
  if(*s == 0x00 || *s == ' ' || *s == '\t' || *s == '\n' || *s == ')') {
    *str = s;
    return result_ok((struct typed_value *) sexp_new_integer(val));
  }

  return result_err(error_fmt("not an integer: '%.*s'", s - *str + 1, *str));
}

struct result * __read_list(char ** str) {
  char * s;
  struct linked_list * head, * cur;

  s = *str + 1; // Skip the '('
  head = cur = 0x00;

  while(true) {
    struct result * res;

    while(' ' == *s) { s++; }

    if(')' == *s) {
      s++;
      break;
    }

    res = __read_sexp(&s);
    if(!res->ok) {
      return res;
    }

    cur = list_add_value(cur, result_unwrap(res));
    if(head == 0x00) {
      head = cur;
    }
  }

  *str = s;
  return result_ok((struct typed_value *) sexp_new_list(head));
}

struct result * __read_symbol(char ** str) {
  char * s;
  struct sexp_symbol * symbol;

  s = *str;
  while(*s != 0x00 && *s != ' ' && *s != ')') {
    s++;
  }

  symbol = sexp_new_symbol(*str, (size_t)(s - *str));
  *str = s;

  return result_ok((struct typed_value *) symbol);
}
