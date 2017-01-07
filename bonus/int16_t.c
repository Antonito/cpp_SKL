/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sat Jan  7 14:06:54 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "raise.h"
#include "int16_t.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  int16_t	value;
} Int16_tClass;

static void	Int16_t_ctor(Object *self, va_list *ap)
{
  Int16_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Int16_t_dtor(Object *self)
{
  Int16_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Int16_t_str(Object *self)
{
  Int16_tClass		*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%d)>", obj->base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object*		Int16_t_add(const Object * self, const Object *other)
{
  Object		*obj;
  int16_t		sum;

  sum = ((Int16_tClass *)self)->value + ((Int16_tClass *)other)->value;
  obj = new(Int16_t, sum);
  return (obj);
}

static Object*		Int16_t_sub(const Object * self, const Object *other)
{
  Object		*obj;
  int16_t		sub;

  sub = ((Int16_tClass *)self)->value - ((Int16_tClass *)other)->value;
  obj = new(Int16_t, sub);
  return (obj);
}

static Object*		Int16_t_mul(const Object * self, const Object *other)
{
  Object		*obj;
  int16_t		mul;

  mul = ((Int16_tClass *)self)->value * ((Int16_tClass *)other)->value;
  obj = new(Int16_t, mul);
  return (obj);
}

static Object*		Int16_t_div(const Object * self, const Object *other)
{
  Object		*obj;
  int16_t		div;

  if (((Int16_tClass *)other)->value == 0)
    raise("Floating point exception");
  div = ((Int16_tClass *)self)->value / ((Int16_tClass *)other)->value;
  obj = new(Int16_t, div);
  return (obj);
}

static bool		Int16_t_eq(const Object *self, const Object *other)
{
  int16_t		val1;
  int16_t		val2;

  val1 = ((Int16_tClass *)self)->value;
  val2 = ((Int16_tClass *)other)->value;
  return (val1 == val2);
}

static bool		Int16_t_lt(const Object *self, const Object *other)
{
  int16_t		val1;
  int16_t		val2;

  val1 = ((Int16_tClass *)self)->value;
  val2 = ((Int16_tClass *)other)->value;
  return (val1 < val2);
}

static bool		Int16_t_gt(const Object *self, const Object *other)
{
  int16_t		val1;
  int16_t		val2;

  val1 = ((Int16_tClass *)self)->value;
  val2 = ((Int16_tClass *)other)->value;
  return (val1 > val2);
}

static Int16_tClass _description =
{
  {
    sizeof(Int16_tClass), "Int16_t", &Int16_t_ctor, &Int16_t_dtor,
    &Int16_t_str, &Int16_t_add, &Int16_t_sub, &Int16_t_mul, &Int16_t_div,
    &Int16_t_eq, &Int16_t_gt, &Int16_t_lt
  },
  NULL, 0
};

Class *Int16_t = (Class *)&_description;
