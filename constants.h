#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#define UNUSED(x) (void)(x);

#define DO_PRAGMA(x) _Pragma(#x)
#define NO_WARN(flag, ...)                  \
  DO_PRAGMA(clang diagnostic push)          \
  DO_PRAGMA(clang diagnostic ignored #flag) \
  __VA_ARGS__                               \
  DO_PRAGMA(clang diagnostic pop)

#define boolean char

#define true 1
#define false 0

#endif
