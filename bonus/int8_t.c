/*
** int32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sun Jan  8 00:28:36 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "int8_t.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
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
  if (asprintf(&obj->__str__, "<%s (%d)>", obj->base.base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object	*Int8_t_clone(const Object *self)
{
  return (new(Int8_t, ((Int8_tClass *)self)->value));
}

static Object*		Int8_t_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Int8_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  int8_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Int8_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }

  obj = new(Int8_t, sum);
  return (obj);
}

static Object*		Int8_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Int8_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  int8_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Int8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  obj = new(Int8_t, sub);
  return (obj);
}

static Object*		Int8_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Int8_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  int8_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Int8_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  obj = new(Int8_t, mul);
  return (obj);
}

static Object*		Int8_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Int8_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  int8_t		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Int8_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  obj = new(Int8_t, div);
  return (obj);
}

static bool		Int8_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Int8_t_real_eq(const Object *self, const Object *other)
{
  int8_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  return (comp == 0);
}

static bool		Int8_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Int8_t_real_lt(const Object *self, const Object *other)
{
  int8_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  return (comp < 0);
}

static bool		Int8_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Int8_t_real_gt(const Object *self, const Object *other)
{
  int8_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  return (comp > 0);
}

static Int8_tClass _description =
{
  {
      {
    sizeof(Int8_tClass), "Int8_t", &Int8_t_ctor, &Int8_t_dtor,
    &Int8_t_str, &Int8_t_clone, &Int8_t_add, &Int8_t_sub, &Int8_t_mul, &Int8_t_div,
    &Int8_t_eq, &Int8_t_gt, &Int8_t_lt
      },
      &Int8_t_real_add,
      &Int8_t_real_sub,
      &Int8_t_real_mul,
      &Int8_t_real_div,
      &Int8_t_real_eq,
      &Int8_t_real_lt,
      &Int8_t_real_gt
  },
  NULL, 0
};

Class *Int8_t = (Class *)&_description;
