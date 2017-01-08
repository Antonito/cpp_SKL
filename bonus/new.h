
#ifndef NEW_H
# define NEW_H

# include <stdarg.h>

# include "object.h"

Object* new(const Class * const class, ...) __attribute__((sentinel(0)));
Object* va_new(const Class* const class, va_list* const ap);
void delete(Object *ptr);

# define new(...) new(__VA_ARGS__, NULL)

#endif
