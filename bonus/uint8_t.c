/*
** int.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:45 2017 Antoine Baché
** Last update Sat Jan  7 14:34:11 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "raise.h"
#include "uint8_t.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  uint8_t	value;
} Uint8_tClass;

static void	Uint8_t_ctor(Object *self, va_list *ap)
{
  Uint8_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Uint8_t_dtor(Object *self)
{
  Uint8_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static Object	*Uint8_t_clone(const Object *self)
{
  Object	*cloned;

  cloned = new(Uint8_t, ((Uint8_tClass *)self)->value);
  return cloned;
}

static char const*	Uint8_t_str(Object *self)
{
  Uint8_tClass		*obj;

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

static Object*		Uint8_t_add(const Object * self, const Object *other)
{
  Object		*obj;
  uint8_t			sum;

  sum = ((Uint8_tClass *)self)->value + ((Uint8_tClass *)other)->value;
  obj = new(Uint8_t, sum);
  return (obj);
}

static Object*		Uint8_t_sub(const Object * self, const Object *other)
{
  Object		*obj;
  uint8_t			sub;

  sub = ((Uint8_tClass *)self)->value - ((Uint8_tClass *)other)->value;
  obj = new(Uint8_t, sub);
  return (obj);
}

static Object*		Uint8_t_mul(const Object * self, const Object *other)
{
  Object		*obj;
  uint8_t			mul;

  mul = ((Uint8_tClass *)self)->value * ((Uint8_tClass *)other)->value;
  obj = new(Uint8_t, mul);
  return (obj);
}

static Object*		Uint8_t_div(const Object * self, const Object *other)
{
  Object		*obj;
  uint8_t			div;

  if (((Uint8_tClass *)other)->value == 0)
    raise("Floating point exception");
  div = ((Uint8_tClass *)self)->value / ((Uint8_tClass *)other)->value;
  obj = new(Uint8_t, div);
  return (obj);
}

static bool		Uint8_t_eq(const Object *self, const Object *other)
{
  uint8_t			val1;
  uint8_t			val2;

  val1 = ((Uint8_tClass *)self)->value;
  val2 = ((Uint8_tClass *)other)->value;
  return (val1 == val2);
}

static bool		Uint8_t_lt(const Object *self, const Object *other)
{
  uint8_t			val1;
  uint8_t			val2;

  val1 = ((Uint8_tClass *)self)->value;
  val2 = ((Uint8_tClass *)other)->value;
  return (val1 < val2);
}

static bool		Uint8_t_gt(const Object *self, const Object *other)
{
  int			val1;
  int			val2;

  val1 = ((Uint8_tClass *)self)->value;
  val2 = ((Uint8_tClass *)other)->value;
  return (val1 > val2);
}

static Uint8_tClass _description =
{
  {
    sizeof(Uint8_tClass), "Uint8_t", &Uint8_t_ctor, &Uint8_t_dtor,
    &Uint8_t_str, &Uint8_t_clone, &Uint8_t_add, &Uint8_t_sub, &Uint8_t_mul, &Uint8_t_div,
    &Uint8_t_eq, &Uint8_t_gt, &Uint8_t_lt
  },
  NULL, 0
};

Class *Uint8_t = (Class *)&_description;
