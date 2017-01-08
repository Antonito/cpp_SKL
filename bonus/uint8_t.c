/*
** uint8_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sun Jan  8 00:32:37 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "int8_t.h"
#include "int16_t.h"
#include "uint8_t.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
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
      obj->value = va_arg(*ap, unsigned int);
    }
}

static void	Uint8_t_dtor(Object *self)
{
  Uint8_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Uint8_t_str(Object *self)
{
  Uint8_tClass		*obj;

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

static Object	*Uint8_t_clone(const Object *self)
{
  return (new(Uint8_t, ((Uint8_tClass *)self)->value));
}

static Object*		Uint8_t_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Uint8_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  uint8_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Uint8_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }
  obj = new(Uint8_t, sum);
  return (obj);
}

static Object*		Uint8_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Uint8_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  uint8_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Uint8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  obj = new(Uint8_t, sub);
  return (obj);
}

static Object*		Uint8_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Uint8_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  uint8_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Uint8_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  obj = new(Uint8_t, mul);
  return (obj);
}

static Object*		Uint8_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Uint8_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  uint8_t		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint8_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }


  obj = new(Uint8_t, div);
  return (obj);
}

static bool		Uint8_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Uint8_t_real_eq(const Object *self, const Object *other)
{
  uint8_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  return (comp == 0);
}

static bool		Uint8_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Uint8_t_real_lt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  return (comp < 0);
}

static bool		Uint8_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Uint8_t_real_gt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint8_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }


  return (comp > 0);
}

static Uint8_tClass _description =
{
  {
      {
    sizeof(Uint8_tClass), "Uint8_t", &Uint8_t_ctor, &Uint8_t_dtor,
    &Uint8_t_str, &Uint8_t_clone, &Uint8_t_add, &Uint8_t_sub, &Uint8_t_mul, &Uint8_t_div,
    &Uint8_t_eq, &Uint8_t_gt, &Uint8_t_lt
      },
      &Uint8_t_real_add,
      &Uint8_t_real_sub,
      &Uint8_t_real_mul,
      &Uint8_t_real_div,
      &Uint8_t_real_eq,
      &Uint8_t_real_lt,
      &Uint8_t_real_gt
  },
  NULL, 0
};

Class *Uint8_t = (Class *)&_description;
