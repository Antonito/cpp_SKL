
#ifndef NUMBER_H
# define NUMBER_H

# include <sys/types.h>
# include <stdarg.h>

# include "bool.h"
# include "object.h"

typedef Object* (*real_op)(const Object* self, const Object* other);
typedef bool (*real_cmp)(const Object* self, const Object* other);

typedef struct {
  Class		base;
  real_op	real_add;
  real_op	real_sub;
  real_op	real_mul;
  real_op	real_div;
  bool		real_eq;
  bool		real_lt;
  bool		real_gt;

} Number;

#endif
