/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sat Jan  7 14:01:51 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "raise.h"
#include "int8_t.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  int8_t	value;
} Int8_tClass;

static void	Int8_t_ctor(Object *self, va_list *ap)
{
  Int8_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Int8_t_dtor(Object *self)
{
  Int8_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Int8_t_str(Object *self)
{
  Int8_tClass		*obj;

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

static Object*		Int8_t_add(const Object * self, const Object *other)
{
  Object		*obj;
  int8_t		sum;

  sum = ((Int8_tClass *)self)->value + ((Int8_tClass *)other)->value;
  obj = new(Int8_t, sum);
  return (obj);
}

static Object*		Int8_t_sub(const Object * self, const Object *other)
{
  Object		*obj;
  int8_t		sub;

  sub = ((Int8_tClass *)self)->value - ((Int8_tClass *)other)->value;
  obj = new(Int8_t, sub);
  return (obj);
}

static Object*		Int8_t_mul(const Object * self, const Object *other)
{
  Object		*obj;
  int8_t		mul;

  mul = ((Int8_tClass *)self)->value * ((Int8_tClass *)other)->value;
  obj = new(Int8_t, mul);
  return (obj);
}

static Object*		Int8_t_div(const Object * self, const Object *other)
{
  Object		*obj;
  int8_t		div;

  if (((Int8_tClass *)other)->value == 0)
    raise("Floating point exception");
  div = ((Int8_tClass *)self)->value / ((Int8_tClass *)other)->value;
  obj = new(Int8_t, div);
  return (obj);
}

static bool		Int8_t_eq(const Object *self, const Object *other)
{
  int8_t		val1;
  int8_t		val2;

  val1 = ((Int8_tClass *)self)->value;
  val2 = ((Int8_tClass *)other)->value;
  return (val1 == val2);
}

static bool		Int8_t_lt(const Object *self, const Object *other)
{
  int8_t		val1;
  int8_t		val2;

  val1 = ((Int8_tClass *)self)->value;
  val2 = ((Int8_tClass *)other)->value;
  return (val1 < val2);
}

static bool		Int8_t_gt(const Object *self, const Object *other)
{
  int8_t		val1;
  int8_t		val2;

  val1 = ((Int8_tClass *)self)->value;
  val2 = ((Int8_tClass *)other)->value;
  return (val1 > val2);
}

static Int8_tClass _description =
{
  {
    sizeof(Int8_tClass), "Int8_t", &Int8_t_ctor, &Int8_t_dtor,
    &Int8_t_str, &Int8_t_add, &Int8_t_sub, &Int8_t_mul, &Int8_t_div,
    &Int8_t_eq, &Int8_t_gt, &Int8_t_lt
  },
  NULL, 0
};

Class *Int8_t = (Class *)&_description;
