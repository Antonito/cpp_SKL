
#ifndef NUMBER_H
# define NUMBER_H

# include <sys/types.h>
# include <stdarg.h>

# include "bool.h"
# include "object.h"

typedef Object* (*real_op)(const Object* self, const Object* other);

typedef struct {
  Class		base;
  real_op	real_add;
} Number;

#endif
