#include "hash_table.h"

#include "list.h"

struct key_value_pair {
  char * key;
  void * val;
};

struct bucket {
  size_t n_items;
  struct list * pairs;
};

struct hash_table * hash_table_new(void) {
}

void hash_set_value(struct hash_table * hsh, char * key, void * val) {

}

boolean hash_get_value(struct hash_table * hsh, char * key, void ** val) {
}
