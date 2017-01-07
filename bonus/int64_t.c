/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sat Jan  7 14:48:32 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "raise.h"
#include "int64_t.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  int64_t	value;
} Int64_tClass;

static void	Int64_t_ctor(Object *self, va_list *ap)
{
  Int64_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Int64_t_dtor(Object *self)
{
  Int64_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Int64_t_str(Object *self)
{
  Int64_tClass		*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%ld)>", obj->base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object	*Int64_t_clone(const Object *self)
{
  return (new(Int64_t, ((Int64_tClass *)self)->value));
}

static Object*		Int64_t_add(const Object * self, const Object *other)
{
  Object		*obj;
  int64_t		sum;

  sum = ((Int64_tClass *)self)->value + ((Int64_tClass *)other)->value;
  obj = new(Int64_t, sum);
  return (obj);
}

static Object*		Int64_t_sub(const Object * self, const Object *other)
{
  Object		*obj;
  int64_t		sub;

  sub = ((Int64_tClass *)self)->value - ((Int64_tClass *)other)->value;
  obj = new(Int64_t, sub);
  return (obj);
}

static Object*		Int64_t_mul(const Object * self, const Object *other)
{
  Object		*obj;
  int64_t		mul;

  mul = ((Int64_tClass *)self)->value * ((Int64_tClass *)other)->value;
  obj = new(Int64_t, mul);
  return (obj);
}

static Object*		Int64_t_div(const Object * self, const Object *other)
{
  Object		*obj;
  int64_t		div;

  if (((Int64_tClass *)other)->value == 0)
    raise("Floating point exception");
  div = ((Int64_tClass *)self)->value / ((Int64_tClass *)other)->value;
  obj = new(Int64_t, div);
  return (obj);
}

static bool		Int64_t_eq(const Object *self, const Object *other)
{
  int64_t		val1;
  int64_t		val2;

  val1 = ((Int64_tClass *)self)->value;
  val2 = ((Int64_tClass *)other)->value;
  return (val1 == val2);
}

static bool		Int64_t_lt(const Object *self, const Object *other)
{
  int64_t		val1;
  int64_t		val2;

  val1 = ((Int64_tClass *)self)->value;
  val2 = ((Int64_tClass *)other)->value;
  return (val1 < val2);
}

static bool		Int64_t_gt(const Object *self, const Object *other)
{
  int64_t		val1;
  int64_t		val2;

  val1 = ((Int64_tClass *)self)->value;
  val2 = ((Int64_tClass *)other)->value;
  return (val1 > val2);
}

static Int64_tClass _description =
{
  {
    sizeof(Int64_tClass), "Int64_t", &Int64_t_ctor, &Int64_t_dtor,
    &Int64_t_str, &Int64_t_clone, &Int64_t_add, &Int64_t_sub, &Int64_t_mul, &Int64_t_div,
    &Int64_t_eq, &Int64_t_gt, &Int64_t_lt
  },
  NULL, 0
};

Class *Int64_t = (Class *)&_description;
