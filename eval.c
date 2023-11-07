#include "eval.h"

#include "result.h"
#include "sexp.h"
#include "type.h"

struct result * eval(struct typed_value * expr) {
  if(expr->type != &sexp_type_list) {
    return result_ok(expr);
  }
}
