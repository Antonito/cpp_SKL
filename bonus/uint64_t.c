/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sat Jan  7 14:49:13 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "raise.h"
#include "uint64_t.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  uint64_t	value;
} Uint64_tClass;

static void	Uint64_t_ctor(Object *self, va_list *ap)
{
  Uint64_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Uint64_t_dtor(Object *self)
{
  Uint64_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static Object	*Uint64_t_clone(const Object *self)
{
  Object	*cloned;

  cloned = new(Uint64_t, ((Uint64_tClass *)self)->value);
  return cloned;
}

static char const*	Uint64_t_str(Object *self)
{
  Uint64_tClass		*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%lu)>", obj->base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object*		Uint64_t_add(const Object * self, const Object *other)
{
  Object		*obj;
  uint64_t			sum;

  sum = ((Uint64_tClass *)self)->value + ((Uint64_tClass *)other)->value;
  obj = new(Uint64_t, sum);
  return (obj);
}

static Object*		Uint64_t_sub(const Object * self, const Object *other)
{
  Object		*obj;
  uint64_t			sub;

  sub = ((Uint64_tClass *)self)->value - ((Uint64_tClass *)other)->value;
  obj = new(Uint64_t, sub);
  return (obj);
}

static Object*		Uint64_t_mul(const Object * self, const Object *other)
{
  Object		*obj;
  uint64_t			mul;

  mul = ((Uint64_tClass *)self)->value * ((Uint64_tClass *)other)->value;
  obj = new(Uint64_t, mul);
  return (obj);
}

static Object*		Uint64_t_div(const Object * self, const Object *other)
{
  Object		*obj;
  uint64_t			div;

  if (((Uint64_tClass *)other)->value == 0)
    raise("Floating point exception");
  div = ((Uint64_tClass *)self)->value / ((Uint64_tClass *)other)->value;
  obj = new(Uint64_t, div);
  return (obj);
}

static bool		Uint64_t_eq(const Object *self, const Object *other)
{
  uint64_t			val1;
  uint64_t			val2;

  val1 = ((Uint64_tClass *)self)->value;
  val2 = ((Uint64_tClass *)other)->value;
  return (val1 == val2);
}

static bool		Uint64_t_lt(const Object *self, const Object *other)
{
  uint64_t			val1;
  uint64_t			val2;

  val1 = ((Uint64_tClass *)self)->value;
  val2 = ((Uint64_tClass *)other)->value;
  return (val1 < val2);
}

static bool		Uint64_t_gt(const Object *self, const Object *other)
{
  int			val1;
  int			val2;

  val1 = ((Uint64_tClass *)self)->value;
  val2 = ((Uint64_tClass *)other)->value;
  return (val1 > val2);
}

static Uint64_tClass _description =
{
  {
    sizeof(Uint64_tClass), "Uint64_t", &Uint64_t_ctor, &Uint64_t_dtor,
    &Uint64_t_str, &Uint64_t_clone, &Uint64_t_add, &Uint64_t_sub, &Uint64_t_mul, &Uint64_t_div,
    &Uint64_t_eq, &Uint64_t_gt, &Uint64_t_lt
  },
  NULL, 0
};

Class *Uint64_t = (Class *)&_description;
