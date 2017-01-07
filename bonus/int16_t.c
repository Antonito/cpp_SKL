/*
** int32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sat Jan 07 22:11:07 2017 
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "int8_t.h"
#include "int16_t.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
  char		*__str__;
  int16_t	value;
} Int16_tClass;

static void	Int16_t_ctor(Object *self, va_list *ap)
{
  Int16_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Int16_t_dtor(Object *self)
{
  Int16_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Int16_t_str(Object *self)
{
  Int16_tClass		*obj;

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

static Object	*Int16_t_clone(const Object *self)
{
  return (new(Int16_t, ((Int16_tClass *)self)->value));
}

static Object*		Int16_t_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Int16_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  int16_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Int16_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((Int16_tClass *)self)->value + (int16_t)*(uintptr_t *)value;
    }

  obj = new(Int16_t, sum);
  return (obj);
}

static Object*		Int16_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Int16_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  int16_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Int16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((Int16_tClass *)self)->value - ((Int16_tClass *)other)->value;
    }

  obj = new(Int16_t, sub);
  return (obj);
}

static Object*		Int16_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Int16_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  int16_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Int16_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((Int16_tClass *)self)->value * (int16_t)*(uintptr_t *)value;
    }

  obj = new(Int16_t, mul);
  return (obj);
}

static Object*		Int16_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Int16_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  int16_t		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Int16_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      if ((int16_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Int16_tClass *)self)->value / ((Int16_tClass *)other)->value;
    }

  obj = new(Int16_t, div);
  return (obj);
}

static bool		Int16_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Int16_t_real_eq(const Object *self, const Object *other)
{
  int16_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int16_tClass *)self)->value - ((Int16_tClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Int16_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Int16_t_real_lt(const Object *self, const Object *other)
{
  int16_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int16_tClass *)self)->value - ((Int16_tClass *)other)->value;
    }

  return (comp < 0);
}

static bool		Int16_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Int16_t_real_gt(const Object *self, const Object *other)
{
  int16_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int16_tClass *)self)->value - ((Int16_tClass *)other)->value;
    }

  return (comp > 0);
}

static Int16_tClass _description =
{
  {
      {
    sizeof(Int16_tClass), "Int16_t", &Int16_t_ctor, &Int16_t_dtor,
    &Int16_t_str, &Int16_t_clone, &Int16_t_add, &Int16_t_sub, &Int16_t_mul, &Int16_t_div,
    &Int16_t_eq, &Int16_t_gt, &Int16_t_lt
      },
      &Int16_t_real_add,
      &Int16_t_real_sub,
      &Int16_t_real_mul,
      &Int16_t_real_div,
      &Int16_t_real_eq,
      &Int16_t_real_lt,
      &Int16_t_real_gt
  },
  NULL, 0
};

Class *Int16_t = (Class *)&_description;
