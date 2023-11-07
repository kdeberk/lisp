#ifndef __ERROR_H__
#define __ERROR_H__

struct error {
  char * msg;
  struct error * parent;
};

// copy @msg
struct error * error_fmt(char * msg, ...);

// combine @err and @parent into a new error.
// move @err
// move @parent
struct error * error_wrap(struct error * err, struct error * parent);

// free error.
// move @err
void error_free(struct error * err);

// write @msg to stderr and then exit(1).
// copy @msg
void fatal(char * msg);

// write @err to stderr and then exit(1).
// copy @err
void fatal_error(struct error * err);

#endif
