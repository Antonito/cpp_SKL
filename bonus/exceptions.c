/*
** exceptions.c for CppPool in /home/bache_a/work/piscine_cpp/cpp_SKL/bonus
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 16:50:56 2017 Antoine Baché
** Last update Sat Jan  7 18:52:35 2017 Antoine Baché
*/

#include "raise.h"
#include "exceptions.h"

__attribute__((nonnull (1, 2)))static void		Exception_ctor(Object *self, va_list *ap)
{
  ExceptionClass	*obj;

  if (!self || !ap)
    raise("Cannot create Exception");
  obj = self;
  obj->value = NO_EXCEPTION;
}


static enum ExceptionsCode	Exception_getException(ExceptionClass *self)
{
  if (!self)
    raise("Cannot get exception");
  return (self->value);
}

__attribute__((always_inline)) inline void	_free_exception(Object *ptr)
{
  if (!ptr || !*(void **)ptr)
    raise("Incorrect argument !");
  ptr = *(void **)ptr;
  free(ptr);
}

static ExceptionClass	_description =
  {
    {
      sizeof(ExceptionClass), "Exception", &Exception_ctor, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
    },
    {
      {
	{0},
	0,
	{
	  {0}
	}
      },
    }, -1, &Exception_getException,
  };

Class *Exception = (Class *)&_description;
