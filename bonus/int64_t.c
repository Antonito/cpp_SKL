/*
** int32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sun Jan  8 00:29:21 2017 Arthur ARNAUD
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
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
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
      obj->value = va_arg(*ap, int64_t);
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
  if (asprintf(&obj->__str__, "<%s (%ld)>", obj->base.base.__name__,
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
  return (check_op(self, other, '+'));
}

static Object*		Int64_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  int64_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Int64_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((Int64_tClass *)self)->value + (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sum = ((Int64_tClass *)self)->value + (int32_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sum = ((Int64_tClass *)self)->value + ((Int64_tClass *)other)->value;
    }

  obj = new(Int64_t, sum);
  return (obj);
}

static Object*		Int64_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Int64_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  int64_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Int64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((Int64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sub = ((Int64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sub = ((Int64_tClass *)self)->value - ((Int64_tClass *)other)->value;
    }

  obj = new(Int64_t, sub);
  return (obj);
}

static Object*		Int64_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Int64_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  int64_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Int64_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((Int64_tClass *)self)->value * (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      mul = ((Int64_tClass *)self)->value * (int32_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      mul = ((Int64_tClass *)self)->value * ((Int64_tClass *)other)->value;
    }

  obj = new(Int64_t, mul);
  return (obj);
}

static Object*		Int64_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Int64_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  int64_t		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Int64_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      if ((int16_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Int64_tClass *)self)->value / (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      if ((int32_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Int64_tClass *)self)->value / (int32_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      if ((int64_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Int64_tClass *)self)->value / ((Int64_tClass *)other)->value;
    }

  obj = new(Int64_t, div);
  return (obj);
}

static bool		Int64_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Int64_t_real_eq(const Object *self, const Object *other)
{
  int64_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - ((Int64_tClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Int64_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Int64_t_real_lt(const Object *self, const Object *other)
{
  int64_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - ((Int64_tClass *)other)->value;
    }

  return (comp < 0);
}

static bool		Int64_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Int64_t_real_gt(const Object *self, const Object *other)
{
  int64_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((Int64_tClass *)self)->value - ((Int64_tClass *)other)->value;
    }

  return (comp > 0);
}

static Int64_tClass _description =
{
  {
      {
    sizeof(Int64_tClass), "Int64_t", &Int64_t_ctor, &Int64_t_dtor,
    &Int64_t_str, &Int64_t_clone, &Int64_t_add, &Int64_t_sub, &Int64_t_mul, &Int64_t_div,
    &Int64_t_eq, &Int64_t_gt, &Int64_t_lt
      },
      &Int64_t_real_add,
      &Int64_t_real_sub,
      &Int64_t_real_mul,
      &Int64_t_real_div,
      &Int64_t_real_eq,
      &Int64_t_real_lt,
      &Int64_t_real_gt
  },
  NULL, 0
};

Class *Int64_t = (Class *)&_description;
