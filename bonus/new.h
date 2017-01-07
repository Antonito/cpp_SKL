
#ifndef NEW_H
# define NEW_H

# include <stdarg.h>

#include "object.h"

Object* new(const Class * const class, ...);
Object* va_new(const Class* const class, va_list* const ap);
void delete(Object *ptr);

#endif
