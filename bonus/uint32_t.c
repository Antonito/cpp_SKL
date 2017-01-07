/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sat Jan  7 14:41:40 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "raise.h"
#include "uint32_t.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  uint32_t	value;
} Uint32_tClass;

static void	Uint32_t_ctor(Object *self, va_list *ap)
{
  Uint32_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Uint32_t_dtor(Object *self)
{
  Uint32_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static Object	*Uint32_t_clone(const Object *self)
{
  Object	*cloned;

  cloned = new(Uint32_t, ((Uint32_tClass *)self)->value);
  return cloned;
}

static char const*	Uint32_t_str(Object *self)
{
  Uint32_tClass		*obj;

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

static Object*		Uint32_t_add(const Object * self, const Object *other)
{
  Object		*obj;
  uint32_t			sum;

  sum = ((Uint32_tClass *)self)->value + ((Uint32_tClass *)other)->value;
  obj = new(Uint32_t, sum);
  return (obj);
}

static Object*		Uint32_t_sub(const Object * self, const Object *other)
{
  Object		*obj;
  uint32_t			sub;

  sub = ((Uint32_tClass *)self)->value - ((Uint32_tClass *)other)->value;
  obj = new(Uint32_t, sub);
  return (obj);
}

static Object*		Uint32_t_mul(const Object * self, const Object *other)
{
  Object		*obj;
  uint32_t			mul;

  mul = ((Uint32_tClass *)self)->value * ((Uint32_tClass *)other)->value;
  obj = new(Uint32_t, mul);
  return (obj);
}

static Object*		Uint32_t_div(const Object * self, const Object *other)
{
  Object		*obj;
  uint32_t			div;

  if (((Uint32_tClass *)other)->value == 0)
    raise("Floating point exception");
  div = ((Uint32_tClass *)self)->value / ((Uint32_tClass *)other)->value;
  obj = new(Uint32_t, div);
  return (obj);
}

static bool		Uint32_t_eq(const Object *self, const Object *other)
{
  uint32_t			val1;
  uint32_t			val2;

  val1 = ((Uint32_tClass *)self)->value;
  val2 = ((Uint32_tClass *)other)->value;
  return (val1 == val2);
}

static bool		Uint32_t_lt(const Object *self, const Object *other)
{
  uint32_t			val1;
  uint32_t			val2;

  val1 = ((Uint32_tClass *)self)->value;
  val2 = ((Uint32_tClass *)other)->value;
  return (val1 < val2);
}

static bool		Uint32_t_gt(const Object *self, const Object *other)
{
  int			val1;
  int			val2;

  val1 = ((Uint32_tClass *)self)->value;
  val2 = ((Uint32_tClass *)other)->value;
  return (val1 > val2);
}

static Uint32_tClass _description =
{
  {
    sizeof(Uint32_tClass), "Uint32_t", &Uint32_t_ctor, &Uint32_t_dtor,
    &Uint32_t_str, &Uint32_t_clone, &Uint32_t_add, &Uint32_t_sub, &Uint32_t_mul, &Uint32_t_div,
    &Uint32_t_eq, &Uint32_t_gt, &Uint32_t_lt
  },
  NULL, 0
};

Class *Uint32_t = (Class *)&_description;
