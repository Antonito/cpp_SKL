/*
** char.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:29 2017 Antoine Baché
** Last update Sun Jan  8 07:45:16 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "raise.h"
#include "char.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  char		value;
} CharClass;

static void	Char_ctor(Object *self, va_list *ap)
{
  CharClass	*obj;

  if (!self || !ap)
    raise("Invalid parameter!");
  obj = self;
  obj->__str__ = NULL;
  obj->value = (char)va_arg(*ap, int);
}

static void	Char_dtor(Object *self)
{
  CharClass	*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Char_str(Object *self)
{
  CharClass		*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%c)>\n", obj->base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object*		Char_add(const Object * self, const Object *other)
{
  Object		*obj;
  char			sum;

  if (!self || !other)
    raise("Invalid parameter!");
  sum = ((CharClass *)self)->value + ((CharClass *)other)->value;
  obj = new(Char, sum);
  return (obj);
}

static Object*		Char_sub(const Object * self, const Object *other)
{
  Object		*obj;
  char			sub;

  if (!self || !other)
    raise("Invalid parameter!");
  sub = ((CharClass *)self)->value - ((CharClass *)other)->value;
  obj = new(Char, sub);
  return (obj);
}

static Object*		Char_mul(const Object * self, const Object *other)
{
  Object		*obj;
  char			mul;

  if (!self || !other)
    raise("Invalid parameter!");
  mul = ((CharClass *)self)->value * ((CharClass *)other)->value;
  obj = new(Char, mul);
  return (obj);
}

static Object*		Char_div(const Object * self, const Object *other)
{
  Object		*obj;
  char			div;

  if (!self || !other)
    raise("Invalid parameter!");
  div = ((CharClass *)self)->value / ((CharClass *)other)->value;
  obj = new(Char, div);
  return (obj);
}

static bool		Char_eq(const Object *self, const Object *other)
{
  char			val1;
  char			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((CharClass *)self)->value;
  val2 = ((CharClass *)other)->value;;
  return (val1 == val2);
}

static bool		Char_lt(const Object *self, const Object *other)
{
  char			val1;
  char			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((CharClass *)self)->value;
  val2 = ((CharClass *)other)->value;;
  return (val1 < val2);
}

static bool		Char_gt(const Object *self, const Object *other)
{
  char			val1;
  char			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((CharClass *)self)->value;
  val2 = ((CharClass *)other)->value;;
  return (val1 > val2);
}

static CharClass _description =
{
  {
    sizeof(CharClass), "Char", &Char_ctor, &Char_dtor,
    &Char_str, &Char_add, &Char_sub, &Char_mul, &Char_div,
    &Char_eq, &Char_gt, &Char_lt
  },
  NULL, 0
};

Class *Char = (Class *)&_description;
