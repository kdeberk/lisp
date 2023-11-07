#ifndef __TYPE_H__
#define __TYPE_H__

struct typed_value;

struct type {
  char * name;
  void (*print)(struct typed_value *);
  void (*free)(struct typed_value *);
};

struct typed_value {
  struct type * type;
  // N.B. The rest of the struct is empty as this struct
  // is only an 'interface' for the actual type structs.
  // These type structs must start with the field 'struct type *', before defining their others.
};

// borrows @val
void typed_value_print(struct typed_value * val);
// moves @val
void typed_value_free(struct typed_value * val);

#endif
