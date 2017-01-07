/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sat Jan  7 14:40:15 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "raise.h"
#include "uint16_t.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  uint16_t	value;
} Uint16_tClass;

static void	Uint16_t_ctor(Object *self, va_list *ap)
{
  Uint16_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Uint16_t_dtor(Object *self)
{
  Uint16_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static Object	*Uint16_t_clone(const Object *self)
{
  Object	*cloned;

  cloned = new(Uint16_t, ((Uint16_tClass *)self)->value);
  return cloned;
}

static char const*	Uint16_t_str(Object *self)
{
  Uint16_tClass		*obj;

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

static Object*		Uint16_t_add(const Object * self, const Object *other)
{
  Object		*obj;
  uint16_t			sum;

  sum = ((Uint16_tClass *)self)->value + ((Uint16_tClass *)other)->value;
  obj = new(Uint16_t, sum);
  return (obj);
}

static Object*		Uint16_t_sub(const Object * self, const Object *other)
{
  Object		*obj;
  uint16_t			sub;

  sub = ((Uint16_tClass *)self)->value - ((Uint16_tClass *)other)->value;
  obj = new(Uint16_t, sub);
  return (obj);
}

static Object*		Uint16_t_mul(const Object * self, const Object *other)
{
  Object		*obj;
  uint16_t			mul;

  mul = ((Uint16_tClass *)self)->value * ((Uint16_tClass *)other)->value;
  obj = new(Uint16_t, mul);
  return (obj);
}

static Object*		Uint16_t_div(const Object * self, const Object *other)
{
  Object		*obj;
  uint16_t			div;

  if (((Uint16_tClass *)other)->value == 0)
    raise("Floating point exception");
  div = ((Uint16_tClass *)self)->value / ((Uint16_tClass *)other)->value;
  obj = new(Uint16_t, div);
  return (obj);
}

static bool		Uint16_t_eq(const Object *self, const Object *other)
{
  uint16_t			val1;
  uint16_t			val2;

  val1 = ((Uint16_tClass *)self)->value;
  val2 = ((Uint16_tClass *)other)->value;
  return (val1 == val2);
}

static bool		Uint16_t_lt(const Object *self, const Object *other)
{
  uint16_t			val1;
  uint16_t			val2;

  val1 = ((Uint16_tClass *)self)->value;
  val2 = ((Uint16_tClass *)other)->value;
  return (val1 < val2);
}

static bool		Uint16_t_gt(const Object *self, const Object *other)
{
  int			val1;
  int			val2;

  val1 = ((Uint16_tClass *)self)->value;
  val2 = ((Uint16_tClass *)other)->value;
  return (val1 > val2);
}

static Uint16_tClass _description =
{
  {
    sizeof(Uint16_tClass), "Uint16_t", &Uint16_t_ctor, &Uint16_t_dtor,
    &Uint16_t_str, &Uint16_t_clone, &Uint16_t_add, &Uint16_t_sub, &Uint16_t_mul, &Uint16_t_div,
    &Uint16_t_eq, &Uint16_t_gt, &Uint16_t_lt
  },
  NULL, 0
};

Class *Uint16_t = (Class *)&_description;
