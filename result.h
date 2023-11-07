#ifndef __RESULT_H__
#define __RESULT_H__

#include "constants.h"
#include "error.h"
#include "type.h"

struct result {
  boolean ok;
  struct error * error;
  struct typed_value * result;
};

// moves @val
struct result * result_ok(struct typed_value * val);

// moves @err
struct result * result_err(struct error * err);

struct result * result_null(void);

// moves @res
// returns res->result
struct typed_value * result_unwrap(struct result * res);

// moves @res
// return res->error
struct error * result_unwrap_error(struct result * res);

// borrows @msg
// moves @res
struct result * result_wrap_err_msg(char * msg, struct result * res);

// moves @res
void result_free(struct result * res);

#endif
