#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include <stdlib.h>
#include "constants.h"

struct bucket;

struct hash_table {
  size_t n_buckets;
  struct bucket * buckets;
};

struct hash_table * hash_table_new(void);
// modifies @hsh
// moves @key
// moves @val
void hash_set_value(struct hash_table * hsh, char * key, void * val);
// sets @*val
// returns reference to @val
boolean hash_get_value(struct hash_table * hsh, char * key, void ** val);
// moves @hsh
void hash_free(struct hash_table * hsh);

#endif
