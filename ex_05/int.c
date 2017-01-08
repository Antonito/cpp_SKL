/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sun Jan  8 04:51:36 2017 Antoine Baché
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "raise.h"
#include "int.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  int		value;
} IntClass;

static void	Int_ctor(Object *self, va_list *ap)
{
  IntClass	*obj;

  if (!self || !ap)
    raise("Invalid parameter!");
  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Int_dtor(Object *self)
{
  IntClass	*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Int_str(Object *self)
{
  IntClass		*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%d)>\n", obj->base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object*		Int_add(const Object * self, const Object *other)
{
  Object		*obj;
  int			sum;

  if (!self || !other)
    raise("Invalid parameter!");
  sum = ((IntClass *)self)->value + ((IntClass *)other)->value;
  obj = new(Int, sum);
  return (obj);
}

static Object*		Int_sub(const Object * self, const Object *other)
{
  Object		*obj;
  int			sub;

  if (!self || !other)
    raise("Invalid parameter!");
  sub = ((IntClass *)self)->value - ((IntClass *)other)->value;
  obj = new(Int, sub);
  return (obj);
}

static Object*		Int_mul(const Object * self, const Object *other)
{
  Object		*obj;
  int			mul;

  if (!self || !other)
    raise("Invalid parameter!");
  mul = ((IntClass *)self)->value * ((IntClass *)other)->value;
  obj = new(Int, mul);
  return (obj);
}

static Object*		Int_div(const Object * self, const Object *other)
{
  Object		*obj;
  int			div;

  if (!self || !other)
    raise("Invalid parameter!");
  div = ((IntClass *)self)->value / ((IntClass *)other)->value;
  obj = new(Int, div);
  return (obj);
}

static bool		Int_eq(const Object *self, const Object *other)
{
  int			val1;
  int			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((IntClass *)self)->value;
  val2 = ((IntClass *)other)->value;
  return (val1 == val2);
}

static bool		Int_lt(const Object *self, const Object *other)
{
  int			val1;
  int			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((IntClass *)self)->value;
  val2 = ((IntClass *)other)->value;
  return (val1 < val2);
}

static bool		Int_gt(const Object *self, const Object *other)
{
  int			val1;
  int			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((IntClass *)self)->value;
  val2 = ((IntClass *)other)->value;
  return (val1 > val2);
}

static IntClass _description =
{
  {
    sizeof(IntClass), "Int", &Int_ctor, &Int_dtor,
    &Int_str, &Int_add, &Int_sub, &Int_mul, &Int_div,
    &Int_eq, &Int_gt, &Int_lt
  },
  NULL, 0
};

Class *Int = (Class *)&_description;
