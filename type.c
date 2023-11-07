#include "type.h"

void typed_value_print(struct typed_value * val) {
  if(!val) {
    return;
  }

  if(!val->type->print) {
    return;
  }

  val->type->print(val);
}

void typed_value_free(struct typed_value * val) {
  if(!val) {
    return;
  }

  if(!val->type->free) {
    return;
  }

  val->type->free(val);
}
