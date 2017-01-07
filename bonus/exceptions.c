/*
** exceptions.c for CppPool in /home/bache_a/work/piscine_cpp/cpp_SKL/bonus
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 16:50:56 2017 Antoine Baché
** Last update Sat Jan  7 20:14:56 2017 Antoine Baché
*/

#include "raise.h"
#include "exceptions.h"

static void		Exception_ctor(Object * const self, va_list * const ap)
{
  ExceptionClass	*obj;

  if (!self || !ap)
    raise("Cannot create exception");
  obj = self;
  obj->value = NO_EXCEPTION;
}


static enum ExceptionsCode	Exception_getException(const ExceptionClass *
						       const self)
{
  if (!self)
    raise("Cannot get Exception");
  return (self->value);
}

inline void	_free_exception(Object *ptr)
{
  Object	*except;

  if (!ptr || !*(void **)ptr)
    raise("Incorrect argument !");
  except = *(void **)ptr;
  free(except);
  *(void **)ptr = NULL;
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
