
#ifndef NEW_H
# define NEW_H

# include <stdarg.h>

#include "object.h"

Object* new(Class * class, ...) __attribute__((sentinel(0)));
Object* va_new(Class* class, va_list* ap);
void delete(Object * ptr);

# define new(...) new(__VA_ARGS__, NULL)

#endif
