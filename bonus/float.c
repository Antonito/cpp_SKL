/*
** int32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sun Jan  8 01:45:21 2017 Antoine Baché
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "int8_t.h"
#include "int16_t.h"
#include "int32_t.h"
#include "int64_t.h"
#include "float.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
  char		*__str__;
  float	value;
} FloatClass;

static void	Float_ctor(Object *self, va_list *ap)
{
  FloatClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, double);
    }
}

static void	Float_dtor(Object *self)
{
  FloatClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Float_str(Object *self)
{
  FloatClass		*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%f)>", obj->base.base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object	*Float_clone(const Object *self)
{
  return (new(Float, ((FloatClass *)self)->value));
}

static Object*		Float_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Float_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  float			sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((FloatClass *)self)->value + (float)((int8_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((FloatClass *)self)->value + (float)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sum = ((FloatClass *)self)->value + (float)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sum = ((FloatClass *)self)->value + (float)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 7) == 0)
    {
      sum = ((FloatClass *)self)->value + ((FloatClass *)other)->value;
    }

  obj = new(Float, sum);
  return (obj);
}

static Object*		Float_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Float_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  float		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((FloatClass *)self)->value - (float)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((FloatClass *)self)->value - (float)((int16_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sub = ((FloatClass *)self)->value - (float)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sub = ((FloatClass *)self)->value - (float)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 7) == 0)
    {
      sub = ((FloatClass *)self)->value - ((FloatClass *)other)->value;
    }

  obj = new(Float, sub);
  return (obj);
}

static Object*		Float_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Float_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  float		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((FloatClass *)self)->value * (float)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((FloatClass *)self)->value * (float)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      mul = ((FloatClass *)self)->value * (float)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      mul = ((FloatClass *)self)->value * (float)((int64_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Float", 7) == 0)
    {
      mul = ((FloatClass *)self)->value * ((FloatClass *)other)->value;
    }

  obj = new(Float, mul);
  return (obj);
}

static Object*		Float_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Float_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  float			div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((float)((int8_t)*(uintptr_t *)value) > 0.0001 && (float)((int8_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((FloatClass *)self)->value / (float)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      if ((float)((int16_t)*(uintptr_t *)value) > 0.0001 && (float)((int16_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((FloatClass *)self)->value / (float)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      if ((float)((int32_t)*(uintptr_t *)value) > 0.0001 && (float)((int32_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((FloatClass *)self)->value / (float)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      if ((float)((int64_t)*(uintptr_t *)value) > 0.0001 && (float)((int64_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((FloatClass *)self)->value / (float)((int64_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Float", 7) == 0)
    {
      if (((FloatClass *)other)->value > 0.0001 && ((FloatClass *)other)->value < 0.0001)
	raise("you cannot divide by zero)");
      div = ((FloatClass *)self)->value / ((FloatClass *)other)->value;
    }

  obj = new(Float, div);
  return (obj);
}

static bool		Float_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Float_real_eq(const Object *self, const Object *other)
{
  float			comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int16_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 7) == 0)
    {
      comp = ((FloatClass *)self)->value - ((FloatClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Float_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Float_real_lt(const Object *self, const Object *other)
{
  float		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int16_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int32_t)*(uintptr_t *)value);
    }
   else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 7) == 0)
    {
      comp = ((FloatClass *)self)->value - ((FloatClass *)other)->value;
    }

  return (comp < 0);
}

static bool		Float_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Float_real_gt(const Object *self, const Object *other)
{
  float		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((FloatClass *)self)->value - (float)((int64_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Float", 7) == 0)
    {
      comp = ((FloatClass *)self)->value - ((FloatClass *)other)->value;
    }

  return (comp > 0);
}

static FloatClass _description =
{
  {
      {
    sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor,
    &Float_str, &Float_clone, &Float_add, &Float_sub, &Float_mul, &Float_div,
    &Float_eq, &Float_gt, &Float_lt
      },
      &Float_real_add,
      &Float_real_sub,
      &Float_real_mul,
      &Float_real_div,
      &Float_real_eq,
      &Float_real_lt,
      &Float_real_gt
  },
  NULL, 0
};

Class *Float = (Class *)&_description;
