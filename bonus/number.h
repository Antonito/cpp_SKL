
#ifndef NUMBER_H
# define NUMBER_H

# include <sys/types.h>
# include <stdarg.h>

# include "bool.h"
# include "object.h"

typedef Object* (*real_op)(const Object* self, const Object* other, bool place);
typedef bool (*real_cmp)(const Object* self, const Object* other);

typedef struct {
  Class		base;
  real_op	real_add;
  real_op	real_sub;
  real_op	real_mul;
  real_op	real_div;
  real_cmp	real_eq;
  real_cmp	real_lt;
  real_cmp	real_gt;

} Number;

#endif
