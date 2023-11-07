#include "string.h"

#include <string.h>

char * string_clone(char * src, size_t n) {
  char * clone = malloc(sizeof(char) * n);
  strncpy(clone, src, n);
  return clone;
}
