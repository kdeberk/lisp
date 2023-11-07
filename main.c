#include "constants.h"
#include "error.h"
#include "result.h"
#include "repl.h"

int main(int argc, char **argv) {
  struct result * res;

  UNUSED(argc);
  UNUSED(argv);

  if((res = repl_loop()) && !res->ok) {
    fatal_error(result_unwrap_error(res));
    return 1;
  }
  return 0;
}
