/*
** uint16_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sun Jan  8 02:38:15 2017 Ludovic Petrenko
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "int8_t.h"
#include "int16_t.h"
#include "uint16_t.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
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
      obj->value = va_arg(*ap, unsigned int);
    }
}

static void	Uint16_t_dtor(Object *self)
{
  Uint16_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Uint16_t_str(Object *self)
{
  Uint16_tClass		*obj;

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

static Object	*Uint16_t_clone(const Object *self)
{
  return (new(Uint16_t, ((Uint16_tClass *)self)->value));
}

static Object*		Uint16_t_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Uint16_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  uint16_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Uint16_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((Uint16_tClass *)self)->value + (int16_t)*(uintptr_t *)value;
    }

  obj = new(Uint16_t, sum);
  return (obj);
}

static Object*		Uint16_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Uint16_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  uint16_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Uint16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((Uint16_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  obj = new(Uint16_t, sub);
  return (obj);
}

static Object*		Uint16_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Uint16_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  uint16_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Uint16_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((Uint16_tClass *)self)->value * (int16_t)*(uintptr_t *)value;
    }

  obj = new(Uint16_t, mul);
  return (obj);
}

static Object*		Uint16_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Uint16_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  uint16_t		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint16_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      if ((int16_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint16_tClass *)self)->value / (int16_t)*(uintptr_t *)value;
    }

  obj = new(Uint16_t, div);
  return (obj);
}

static bool		Uint16_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Uint16_t_real_eq(const Object *self, const Object *other)
{
  uint16_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint16_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  return (comp == 0);
}

static bool		Uint16_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Uint16_t_real_lt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint16_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  return (comp < 0);
}

static bool		Uint16_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Uint16_t_real_gt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint16_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint16_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  return (comp > 0);
}

static Uint16_tClass _description =
{
  {
      {
	sizeof(Uint16_tClass), "Uint16_t", &Uint16_t_ctor, &Uint16_t_dtor, NULL,
    &Uint16_t_str, &Uint16_t_clone, &Uint16_t_add, &Uint16_t_sub, &Uint16_t_mul, &Uint16_t_div,
    &Uint16_t_eq, &Uint16_t_gt, &Uint16_t_lt
      },
      &Uint16_t_real_add,
      &Uint16_t_real_sub,
      &Uint16_t_real_mul,
      &Uint16_t_real_div,
      &Uint16_t_real_eq,
      &Uint16_t_real_lt,
      &Uint16_t_real_gt
  },
  NULL, 0
};

Class *Uint16_t = (Class *)&_description;
