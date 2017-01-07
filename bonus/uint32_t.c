/*
** uint32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sat Jan 07 21:54:53 2017 
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "int8_t.h"
#include "int16_t.h"
#include "uint32_t.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
  char		*__str__;
  uint32_t	value;
} Uint32_tClass;

static void	Uint32_t_ctor(Object *self, va_list *ap)
{
  Uint32_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Uint32_t_dtor(Object *self)
{
  Uint32_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Uint32_t_str(Object *self)
{
  Uint32_tClass		*obj;

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

static Object	*Uint32_t_clone(const Object *self)
{
  return (new(Uint32_t, ((Uint32_tClass *)self)->value));
}

static Object*		Uint32_t_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Uint32_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  uint32_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Uint32_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((Uint32_tClass *)self)->value + (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sum = ((Uint32_tClass *)self)->value + ((Uint32_tClass *)other)->value;
    }

  obj = new(Uint32_t, sum);
  return (obj);
}

static Object*		Uint32_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Uint32_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  uint32_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Uint32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((Uint32_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sub = ((Uint32_tClass *)self)->value - ((Uint32_tClass *)other)->value;
    }

  obj = new(Uint32_t, sub);
  return (obj);
}

static Object*		Uint32_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Uint32_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  uint32_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Uint32_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((Uint32_tClass *)self)->value * (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      mul = ((Uint32_tClass *)self)->value * ((Uint32_tClass *)other)->value;
    }

  obj = new(Uint32_t, mul);
  return (obj);
}

static Object*		Uint32_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Uint32_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  uint32_t		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint32_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      if ((int16_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint32_tClass *)self)->value / (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      if ((int32_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint32_tClass *)self)->value / ((Uint32_tClass *)other)->value;
    }

  obj = new(Uint32_t, div);
  return (obj);
}

static bool		Uint32_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Uint32_t_real_eq(const Object *self, const Object *other)
{
  uint32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint32_tClass *)self)->value / (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Uint32_tClass *)self)->value / ((Uint32_tClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Uint32_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Uint32_t_real_lt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint32_tClass *)self)->value / (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Uint32_tClass *)self)->value / ((Uint32_tClass *)other)->value;
    }

  return (comp < 0);
}

static bool		Uint32_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Uint32_t_real_gt(const Object *self, const Object *other)
{
  int32_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint32_tClass *)self)->value / (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Uint32_tClass *)self)->value / ((Uint32_tClass *)other)->value;
    }

  return (comp > 0);
}

static Uint32_tClass _description =
{
  {
      {
    sizeof(Uint32_tClass), "Uint32_t", &Uint32_t_ctor, &Uint32_t_dtor,
    &Uint32_t_str, &Uint32_t_clone, &Uint32_t_add, &Uint32_t_sub, &Uint32_t_mul, &Uint32_t_div,
    &Uint32_t_eq, &Uint32_t_gt, &Uint32_t_lt
      },
      &Uint32_t_real_add,
      &Uint32_t_real_sub,
      &Uint32_t_real_mul,
      &Uint32_t_real_div,
      &Uint32_t_real_eq,
      &Uint32_t_real_lt,
      &Uint32_t_real_gt
  },
  NULL, 0
};

Class *Uint32_t = (Class *)&_description;
