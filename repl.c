#include "repl.h"

#include "constants.h"
#include "read.h"
#include "result.h"
#include "sexp.h"

// returns result
struct result * __repl_read(void);
// moves @val
// returns result
struct result * __repl_eval(struct typed_value * val);
// move @val
// returns result
struct result * __repl_print(struct typed_value * val);

struct result * repl_loop(void) {
  while (true) {
    struct result * res;
    struct typed_value * val;

    res = __repl_read();
    if(!res->ok) {
      return result_wrap_err_msg("read failed", res);
    }
    val = result_unwrap(res);

    res = __repl_eval(val);
    if(!res->ok) {
      return result_wrap_err_msg("eval failed", res);
    }
    val = result_unwrap(res);

    res = __repl_print(val);
    if(!res->ok) {
      return result_wrap_err_msg("print failed", res);
    }
    result_unwrap(res);

    break;
  }
  return result_null();
}

// return result
struct result * __repl_read(void) {
  // TODO: read a line from stdin
  return read_sexp("(+ 1 2)");
}

// move @val
// returns result
struct result * __repl_eval(struct typed_value * val) {
  if(val->type != &sexp_type_list) {
    return result_ok(val);
  }
  // TODO: eval the expression
  return result_ok(val);
}

// move @val
// returns result
struct result * __repl_print(struct typed_value * val) {
  typed_value_print(val);
  typed_value_free(val);
  return result_null();
}
