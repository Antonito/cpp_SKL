/*
** new.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:52 2017 Antoine Baché
** Last update Sun Jan  8 00:49:22 2017 Antoine Baché
*/

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "raise.h"
#include "new.h"

Object* va_new(const Class* const class, va_list* const ap)
{
  void	*obj;

  obj = malloc(class->__size__);
  if (!obj)
    {
      raise("Out of memory");
    }
  memcpy(obj, class, class->__size__);
  if (class->__init__)
    class->__init__(obj, ap);
  return (obj);
}

void		*new(const Class * const class, ...)
{
  void		*obj;
  va_list	ap;

  obj = NULL;
  if (class)
    {
      va_start(ap, class);
      obj = va_new(class, &ap);
      va_end(ap);
    }
  return (obj);
}

void	delete(Object *ptr)
{
  Class	*obj;

  if (ptr)
    {
      obj = ptr;
      if (obj->__del__)
	obj->__del__(obj);
      free(ptr);
    }
}
