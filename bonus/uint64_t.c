/*
** uint64_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sat Jan 07 21:36:40 2017 
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "int8_t.h"
#include "int16_t.h"
#include "uint64_t.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
  char		*__str__;
  uint64_t	value;
} Uint64_tClass;

static void	Uint64_t_ctor(Object *self, va_list *ap)
{
  Uint64_tClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, int);
    }
}

static void	Uint64_t_dtor(Object *self)
{
  Uint64_tClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Uint64_t_str(Object *self)
{
  Uint64_tClass		*obj;

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

static Object	*Uint64_t_clone(const Object *self)
{
  return (new(Uint64_t, ((Uint64_tClass *)self)->value));
}

static Object*		Uint64_t_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Uint64_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  uint64_t		sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Uint64_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((Uint64_tClass *)self)->value + (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sum = ((Uint64_tClass *)self)->value + (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sum = ((Uint64_tClass *)self)->value + ((Uint64_tClass *)other)->value;
    }

  obj = new(Uint64_t, sum);
  return (obj);
}

static Object*		Uint64_t_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Uint64_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  uint64_t		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Uint64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((Uint64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sub = ((Uint64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sub = ((Uint64_tClass *)self)->value - ((Uint64_tClass *)other)->value;
    }

  obj = new(Uint64_t, sub);
  return (obj);
}

static Object*		Uint64_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Uint64_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  uint64_t		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Uint64_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((Uint64_tClass *)self)->value * (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      mul = ((Uint64_tClass *)self)->value * (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      mul = ((Uint64_tClass *)self)->value * ((Uint64_tClass *)other)->value;
    }

  obj = new(Uint64_t, mul);
  return (obj);
}

static Object*		Uint64_t_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Uint64_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  uint64_t		div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((int8_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint64_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      if ((int16_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint64_tClass *)self)->value / (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      if ((int32_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint64_tClass *)self)->value / (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      if ((int64_t)*(uintptr_t *)value == 0)
	raise("you cannot divide by zero)");
      div = ((Uint64_tClass *)self)->value / (int64_t)*(uintptr_t *)value;
    }

  obj = new(Uint64_t, div);
  return (obj);
}

static bool		Uint64_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Uint64_t_real_eq(const Object *self, const Object *other)
{
  uint64_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - ((Uint64_tClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Uint64_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Uint64_t_real_lt(const Object *self, const Object *other)
{
  uint64_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - ((Uint64_tClass *)other)->value;
    }

  return (comp < 0);
}

static bool		Uint64_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Uint64_t_real_gt(const Object *self, const Object *other)
{
  uint64_t		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int16_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - (int32_t)*(uintptr_t *)value;
    }

  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((Uint64_tClass *)self)->value - ((Uint64_tClass *)other)->value;
    }

  return (comp > 0);
}

static Uint64_tClass _description =
{
  {
      {
    sizeof(Uint64_tClass), "Uint64_t", &Uint64_t_ctor, &Uint64_t_dtor,
    &Uint64_t_str, &Uint64_t_clone, &Uint64_t_add, &Uint64_t_sub, &Uint64_t_mul, &Uint64_t_div,
    &Uint64_t_eq, &Uint64_t_gt, &Uint64_t_lt
      },
      &Uint64_t_real_add,
      &Uint64_t_real_sub,
      &Uint64_t_real_mul,
      &Uint64_t_real_div,
      &Uint64_t_real_eq,
      &Uint64_t_real_lt,
      &Uint64_t_real_gt
  },
  NULL, 0
};

Class *Uint64_t = (Class *)&_description;
