#include "error.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdnoreturn.h>
#include "constants.h"
#include "string.h"

#define MAX_ERROR_STRING 100

struct error * __error_new(char * msg);

struct error * error_fmt(char * fmt, ...) {
  char * msg;
  char dst[MAX_ERROR_STRING];

  NO_WARN(-Wformat-nonliteral, {
      va_list args;
      va_start(args, fmt);
      vsnprintf(dst, MAX_ERROR_STRING, fmt, args);
      va_end(args);
    });

  msg = string_clone(dst, MAX_ERROR_STRING);
  return __error_new(msg);
}

struct error * error_wrap(struct error * err, struct error * parent) {
  err->parent = parent;
  return err;
}

struct error * __error_new(char * msg) {
  struct error * err = malloc(sizeof(struct error));
  err->msg = msg;
  err->parent = 0x00;
  return err;
}

void error_free(struct error * err) {
  if(!err->parent) {
    error_free(err->parent);
  }
  free(err->msg);
  free(err);
  return;
}

noreturn void fatal(char * msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

noreturn void fatal_error(struct error * err) {
  struct error * cur = err;
  while(cur) {
    if(cur->parent) {
      fprintf(stderr, "%s: ", cur->msg);
      cur = cur->parent;
      continue;
    }
    fprintf(stderr, "%s\n", cur->msg);
    break;
  }
  exit(1);
}
