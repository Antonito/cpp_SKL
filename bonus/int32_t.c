/*
** int32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sun Jan 08 07:35:37 2017 
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
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
  char		*__str__;
  int32_t	value;
} Int32_tClass;

static void	Int32_t_ctor(Object *self, va_list *ap)
{
  Int32_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Int32_t_dtor(Object *self)
{
  Int32_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Int32_t_str(Object *self)
{
  Int32_tClass		*obj;

  if (!self)
    raise("Invalid parameter!");
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

static Object	*Int32_t_clone(const Object *self)
{
  return (new(Int32_t, ((Int32_tClass *)self)->value));
}

static Object*		Int32_t_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Int32_t_real_add(const Object *self, const Object *other, bool place)
{
  Object		*obj;
  int32_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  (void)place;
  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Int32_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((Int32_tClass *)self)->value + (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sum = ((Int32_tClass *)self)->value + ((Int32_tClass *)other)->value;
    }

  obj = new(Int32_t, sum);
  return (obj);
}

static Object*		Int32_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Int32_t_real_sub(const Object *self, const Object *other, bool place)
{
  Object		*obj;
  int32_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((Int32_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sub = ((Int32_tClass *)self)->value - ((Int32_tClass *)other)->value;
    }

  if (place)
    sub = -1 * sub;
  obj = new(Int32_t, sub);
  return (obj);
}

static Object*		Int32_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Int32_t_real_mul(const Object *self, const Object *other, bool place)
{
  Object		*obj;
  int32_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  (void)place;
  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Int32_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((Int32_tClass *)self)->value * (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      mul = ((Int32_tClass *)self)->value * ((Int32_tClass *)other)->value;
    }

  obj = new(Int32_t, mul);
  return (obj);
}

static Object*		Int32_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Int32_t_real_div(const Object *self, const Object *other, bool place)
{
  Object		*obj;
  double		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = (double)((Int32_tClass *)self)->value / (double)(int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      div = (double)((Int32_tClass *)self)->value / (double)(int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      div = (double)((Int32_tClass *)self)->value / (double)((Int32_tClass *)other)->value;
    }

  if (place && div != 0)
    div = 1 / div;
  obj = new(Int32_t, (int32_t)div);
  return (obj);
}

static bool		Int32_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Int32_t_real_eq(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value - ((Int32_tClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Int32_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Int32_t_real_lt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value - ((Int32_tClass *)other)->value;
    }

  return (comp < 0);
}

static bool		Int32_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Int32_t_real_gt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value - ((Int32_tClass *)other)->value;
    }

  return (comp > 0);
}

static void	Int32_t_set(Object *self, ...)
{
  Int32_tClass	*obj;
  va_list	ap;

  if (!self)
    raise("Incorrect Arguments");
  obj = self;
  va_start(ap, self);
  obj->value = va_arg(ap, int);
  va_end(ap);
}

static Int32_tClass _description =
{
  {
      {
	sizeof(Int32_tClass), "Int32_t", &Int32_t_ctor, &Int32_t_dtor, &Int32_t_set,
    &Int32_t_str, &Int32_t_clone, &Int32_t_add, &Int32_t_sub, &Int32_t_mul, &Int32_t_div,
    &Int32_t_eq, &Int32_t_gt, &Int32_t_lt
      },
      &Int32_t_real_add,
      &Int32_t_real_sub,
      &Int32_t_real_mul,
      &Int32_t_real_div,
      &Int32_t_real_eq,
      &Int32_t_real_lt,
      &Int32_t_real_gt
  },
  NULL, 0
};

Class *Int32_t = (Class *)&_description;
Class *Int = (Class*)&_description;
