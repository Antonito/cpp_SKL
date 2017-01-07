/*
** int32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sat Jan  7 18:54:46 2017 Arthur ARNAUD
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
  return (check_op(self, other, '-'));
}

static Object*		Int32_t_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  int32_t		sum;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (strncmp(_b->__name__, "Int8_t", 6) == 0 || strncmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((Int32_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int16_t", 7) == 0 || strncmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((Int32_tClass *)self)->value + (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int32_t", 7) == 0 || strncmp(_b->__name__, "Uint32_t", 8) == 0)
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

static Object*		Int32_t_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  int32_t		sub;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (strncmp(_b->__name__, "Int8_t", 6) == 0 || strncmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int16_t", 7) == 0 || strncmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int32_t", 7) == 0 || strncmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sub = ((Int32_tClass *)self)->value - ((Int32_tClass *)other)->value;
    }

  obj = new(Int32_t, sub);
  return (obj);
}

static Object*		Int32_t_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Int32_t_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  int32_t		mul;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (strncmp(_b->__name__, "Int8_t", 6) == 0 || strncmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((Int32_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int16_t", 7) == 0 || strncmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((Int32_tClass *)self)->value * (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int32_t", 7) == 0 || strncmp(_b->__name__, "Uint32_t", 8) == 0)
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

static Object*		Int32_t_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  int32_t		div;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (strncmp(_b->__name__, "Int8_t", 6) == 0 || strncmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      div = ((Int32_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int16_t", 7) == 0 || strncmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      div = ((Int32_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int32_t", 7) == 0 || strncmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      div = ((Int32_tClass *)self)->value / ((Int32_tClass *)other)->value;
    }

  obj = new(Int32_t, div);
  return (obj);
}

static bool		Int32_t_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Int32_t_real_eq(const Object *self, const Object *other)
{
  Object		*obj;
  int32_t		comp;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (strncmp(_b->__name__, "Int8_t", 6) == 0 || strncmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int16_t", 7) == 0 || strncmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int32_t", 7) == 0 || strncmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value / ((Int32_tClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Int32_t_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Int32_t_real_lt(const Object *self, const Object *other)
{
  Object		*obj;
  int32_t		comp;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (strncmp(_b->__name__, "Int8_t", 6) == 0 || strncmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int16_t", 7) == 0 || strncmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int32_t", 7) == 0 || strncmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value / ((Int32_tClass *)other)->value;
    }

  return (lt < 0);
}

static bool		Int32_t_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Int32_t_real_gt(const Object *self, const Object *other)
{
  Object		*obj;
  int32_t		comp;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Class) + sizeof(char *);


  if (strncmp(_b->__name__, "Int8_t", 6) == 0 || strncmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((Int32_tClass *)self)->value - (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int16_t", 7) == 0 || strncmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value / (int8_t)*(uintptr_t *)value;
    }

  if (strncmp(_b->__name__, "Int32_t", 7) == 0 || strncmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((Int32_tClass *)self)->value / ((Int32_tClass *)other)->value;
    }

  return (lt > 0);
}

static Int32_tClass _description =
{
  {
      {
    sizeof(Int32_tClass), "Int32_t", &Int32_t_ctor, &Int32_t_dtor,
    &Int32_t_str, &Int32_t_clone, &Int32_t_add, &Int32_t_sub, &Int32_t_mul, &Int32_t_div,
    &Int32_t_eq, &Int32_t_gt, &Int32_t_lt
      },
      &Int32_t_real_add,
      &Int32_t_real_sub,
      &Int32_t_real_mul,
      &Int32_t_real_div,
      &Int32_t_real_eq,
      &Int32_t_real_lt,
      &Int32_t_real_gt;
  },
  NULL, 0
};

Class *Int32_t = (Class *)&_description;
