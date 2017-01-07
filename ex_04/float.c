/*
** float.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:37 2017 Antoine Baché
** Last update Sat Jan  7 18:25:47 2017 Ludovic Petrenko
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <float.h>
#include "raise.h"
#include "float.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  float		value;
} FloatClass;

static void	Float_ctor(Object *self, va_list *ap)
{
  FloatClass	*obj;

  if (!self || !ap)
    raise("Invalid parameter!");
  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = (float)va_arg(*ap, double);
    }
}

static void	Float_dtor(Object *self)
{
  FloatClass	*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Float_str(Object *self)
{
  FloatClass		*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%f)>", obj->base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object*		Float_add(const Object * self, const Object *other)
{
  Object		*obj;
  float			sum;

  if (!self || !other)
    raise("Invalid parameter!");
  sum = ((FloatClass *)self)->value + ((FloatClass *)other)->value;
  obj = new(Float, sum);
  return (obj);
}

static Object*		Float_sub(const Object * self, const Object *other)
{
  Object		*obj;
  float			sub;

  if (!self || !other)
    raise("Invalid parameter!");
  sub = ((FloatClass *)self)->value - ((FloatClass *)other)->value;
  obj = new(Float, sub);
  return (obj);
}

static Object*		Float_mul(const Object * self, const Object *other)
{
  Object		*obj;
  float			mul;

  if (!self || !other)
    raise("Invalid parameter!");
  mul = ((FloatClass *)self)->value * ((FloatClass *)other)->value;
  obj = new(Float, mul);
  return (obj);
}

static Object*		Float_div(const Object * self, const Object *other)
{
  Object		*obj;
  float			div;
  float			value;

  if (!self || !other)
    raise("Invalid parameter!");
  value = ((FloatClass *)other)->value;
  if (value < 0.001f && value > -0.001f)
    raise("Floating point exception");
  div = ((FloatClass *)self)->value / ((FloatClass *)other)->value;
  obj = new(Float, div);
  return (obj);
}

static bool		Float_eq(const Object *self, const Object *other)
{
  float			val1;
  float			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((FloatClass *)self)->value;
  val2 = ((FloatClass *)other)->value;
  return (val1 == val2);
}

static bool		Float_lt(const Object *self, const Object *other)
{
  float			val1;
  float			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((FloatClass *)self)->value;
  val2 = ((FloatClass *)other)->value;
  return (val1 < val2);
}

static bool		Float_gt(const Object *self, const Object *other)
{
  float			val1;
  float			val2;

  if (!self || !other)
    raise("Invalid parameter!");
  val1 = ((FloatClass *)self)->value;
  val2 = ((FloatClass *)other)->value;
  return (val1 > val2);
}

static FloatClass _description =
{
  {
    sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor,
    &Float_str, &Float_add, &Float_sub, &Float_mul, &Float_div,
    &Float_eq, &Float_gt, &Float_lt
  },
  NULL, 0
};

Class *Float = (Class *)&_description;
