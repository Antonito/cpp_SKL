/*
** int32_t.c for  in /home/arnaud_e/piscine++/cpp_SKL/bonus
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Jan  7 14:11:35 2017 Arthur ARNAUD
** Last update Sun Jan  8 02:54:12 2017 Ludovic Petrenko
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
#include "double.h"
#include "new.h"
#include "number.h"
#include "operation.h"

typedef struct
{
  Number		base;
  char		*__str__;
  double	value;
} DoubleClass;

static void	Double_ctor(Object *self, va_list *ap)
{
  DoubleClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = va_arg(*ap, double);
    }
}

static void	Double_dtor(Object *self)
{
  DoubleClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Double_str(Object *self)
{
  DoubleClass		*obj;

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

static Object	*Double_clone(const Object *self)
{
  return (new(Double, ((DoubleClass *)self)->value));
}

static Object*		Double_add(const Object * self, const Object *other)
{
  return (check_op(self, other, '+'));
}

static Object*		Double_real_add(const Object *self, const Object *other)
{
  Object		*obj;
  double			sum = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sum = ((DoubleClass *)self)->value + (double)((int8_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sum = ((DoubleClass *)self)->value + (double)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sum = ((DoubleClass *)self)->value + (double)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0
	   || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sum = ((DoubleClass *)self)->value + (double)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 5) == 0)
    {

      printf("self :%f\n",((DoubleClass *)self)->value);
      printf("other :%f\n",(double)(*(float *)(uintptr_t *)value));
      sum = ((DoubleClass *)self)->value + (double)(*(float *)(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Double", 6) == 0)
    {
      sum = ((DoubleClass *)self)->value + ((DoubleClass *)other)->value;
    }

  obj = new(Double, sum);
  return (obj);
}

static Object*		Double_sub(const Object * self, const Object *other)
{
  return (check_op(self, other, '-'));
}

static Object*		Double_real_sub(const Object *self, const Object *other)
{
  Object		*obj;
  double		sub = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      sub = ((DoubleClass *)self)->value - (double)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      sub = ((DoubleClass *)self)->value - (double)((int16_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      sub = ((DoubleClass *)self)->value - (double)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      sub = ((DoubleClass *)self)->value - (double)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 5) == 0)
    {
      sub = ((DoubleClass *)self)->value - (double)(*(float *)(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Double", 6) == 0)
    {
      sub = ((DoubleClass *)self)->value - ((DoubleClass *)other)->value;
    }

  obj = new(Double, sub);
  return (obj);
}

static Object*		Double_mul(const Object * self, const Object *other)
{
  return (check_op(self, other, '*'));
}

static Object*		Double_real_mul(const Object *self, const Object *other)
{
  Object		*obj;
  double		mul = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      mul = ((DoubleClass *)self)->value * (double)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      mul = ((DoubleClass *)self)->value * (double)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      mul = ((DoubleClass *)self)->value * (double)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      mul = ((DoubleClass *)self)->value * (double)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 5) == 0)
    {
      mul = ((DoubleClass *)self)->value * (double)(*(float *)(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Double", 6) == 0)
    {
      mul = ((DoubleClass *)self)->value * ((DoubleClass *)other)->value;
    }

  obj = new(Double, mul);
  return (obj);
}

static Object*		Double_div(const Object * self, const Object *other)
{
  return (check_op(self, other, '/'));
}

static Object*		Double_real_div(const Object *self, const Object *other)
{
  Object		*obj;
  double			div = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      if ((double)((int8_t)*(uintptr_t *)value) > 0.0001 && (double)((int8_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((DoubleClass *)self)->value / (double)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      if ((double)((int16_t)*(uintptr_t *)value) > 0.0001 && (double)((int16_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((DoubleClass *)self)->value / (double)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      if ((double)((int32_t)*(uintptr_t *)value) > 0.0001 && (double)((int32_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((DoubleClass *)self)->value / (double)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      if ((double)((int64_t)*(uintptr_t *)value) > 0.0001 && (double)((int64_t)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((DoubleClass *)self)->value / (double)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 5) == 0)
    {
      if ((double)((float)*(uintptr_t *)value) > 0.0001 && (double)((float)*(uintptr_t *)value) < 0.0001)
	raise("you cannot divide by zero)");
      div = ((DoubleClass *)self)->value / (double)(*(float *)(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Double", 6) == 0)
    {
      if (((DoubleClass *)other)->value > 0.0001 && ((DoubleClass *)other)->value < 0.0001)
	raise("you cannot divide by zero)");
      div = ((DoubleClass *)self)->value / ((DoubleClass *)other)->value;
    }

  obj = new(Double, div);
  return (obj);
}

static bool		Double_eq(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '='));
}

static bool		Double_real_eq(const Object *self, const Object *other)
{
  double			comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int16_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 5) == 0)
    {
      comp  = ((DoubleClass *)self)->value - (double)(*(float *)(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Double", 6) == 0)
    {
      comp = ((DoubleClass *)self)->value - ((DoubleClass *)other)->value;
    }

  return (comp == 0);
}

static bool		Double_lt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '<'));
}

static bool		Double_real_lt(const Object *self, const Object *other)
{
  double		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int16_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 5) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)(*(float *)(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Double", 6) == 0)
    {
      comp = ((DoubleClass *)self)->value - ((DoubleClass *)other)->value;
    }

  return (comp < 0);
}

static bool		Double_gt(const Object *self, const Object *other)
{
  return (check_cmp(self, other, '>'));
}

static bool		Double_real_gt(const Object *self, const Object *other)
{
  double		comp = 0;
  Class			*_b;
  uintptr_t		value;

  _b = (Class *)other;
  value = (uintptr_t)other + sizeof(Number) + sizeof(char *);


  if (memcmp(_b->__name__, "Int8_t", 6) == 0 || memcmp(_b->__name__, "Uint8_t", 7) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int8_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int16_t", 7) == 0 || memcmp(_b->__name__, "Uint16_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int16_t)*(uintptr_t *)value);
    }

  else if (memcmp(_b->__name__, "Int32_t", 7) == 0 || memcmp(_b->__name__, "Uint32_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int32_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Int64_t", 7) == 0 || memcmp(_b->__name__, "Uint64_t", 8) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((int64_t)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Float", 5) == 0)
    {
      comp = ((DoubleClass *)self)->value - (double)((float)*(uintptr_t *)value);
    }
  else if (memcmp(_b->__name__, "Double", 6) == 0)
    {
      comp = ((DoubleClass *)self)->value - ((DoubleClass *)other)->value;
    }

  return (comp > 0);
}

static DoubleClass _description =
{
  {
      {
	sizeof(DoubleClass), "Double", &Double_ctor, &Double_dtor, NULL,
    &Double_str, &Double_clone, &Double_add, &Double_sub, &Double_mul, &Double_div,
    &Double_eq, &Double_gt, &Double_lt
      },
      &Double_real_add,
      &Double_real_sub,
      &Double_real_mul,
      &Double_real_div,
      &Double_real_eq,
      &Double_real_lt,
      &Double_real_gt
  },
  NULL, 0
};

Class *Double = (Class *)&_description;
