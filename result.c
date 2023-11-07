#include "result.h"

#include <stdlib.h>
#include "type.h"

struct result * result_ok(struct typed_value * result) {
  struct result * res = malloc(sizeof(struct result));
  res->ok = true;
  res->result = result;
  res->error = 0x00;
  return res;
}

struct result * result_err(struct error * err) {
  struct result * res = malloc(sizeof(struct result));
  res->ok = false;
  res->result = 0x00;
  res->error = err;
  return res;
}

struct result * result_null(void) {
  struct result * res = malloc(sizeof(struct result));
  res->ok = true;
  res->result = 0x00;
  res->error = 0x00;
  return res;
}

struct typed_value * result_unwrap(struct result * res) {
  void * result;

  if(res->error != 0x00) {
    fatal("result_unwrap: error is not null");
  }
  result = res->result;
  free(res);
  return result;
}

struct error * result_unwrap_error(struct result * res) {
  struct error * err;

  if(res->error == 0x00) {
    fatal("result_unwrap_error: error is null");
  }
  err = res->error;
  free(res);
  return err;
}

struct result * result_wrap_err_msg(char * msg, struct result * res) {
  if(res->ok) {
    fatal("result_wrap_err_msg: result is not error");
  }

  res->error = error_wrap(error_fmt(msg), res->error);
  return res;
}

void result_free(struct result * res) {
  if(res->ok) {
    typed_value_free(res->result);
  } else if(res->error) {
    error_free(res->error);
  }

  free(res);
  return;
}
