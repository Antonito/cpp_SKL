/*
** char.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_04
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:36:29 2017 Antoine Baché
** Last update Sat Jan 07 14:25:01 2017 
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "raise.h"
#include "char.h"
#include "new.h"

typedef struct
{
  Class		base;
  char		*__str__;
  char		value;
} CharClass;

static void	Char_ctor(Object *self, va_list *ap)
{
  CharClass	*obj;

  obj = self;
  if (ap)
    {
      obj->__str__ = NULL;
      obj->value = (char)va_arg(*ap, int);
    }
}

static void	Char_dtor(Object *self)
{
  CharClass	*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Char_str(Object *self)
{
  CharClass		*obj;

  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%c)>", obj->base.__name__,
	       obj->value) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static Object*		Char_add(const Object * self, const Object *other)
{
  Object		*obj;
  char			sum;

  sum = ((CharClass *)self)->value + ((CharClass *)other)->value;
  obj = new(Char, sum);
  return (obj);
}

static Object*		Char_sub(const Object * self, const Object *other)
{
  Object		*obj;
  char			sub;

  sub = ((CharClass *)self)->value - ((CharClass *)other)->value;
  obj = new(Char, sub);
  return (obj);
}

static Object*		Char_mul(const Object * self, const Object *other)
{
  Object		*obj;
  char			mul;

  mul = ((CharClass *)self)->value * ((CharClass *)other)->value;
  obj = new(Char, mul);
  return (obj);
}

static Object*		Char_div(const Object * self, const Object *other)
{
  Object		*obj;
  char			div;

  if (((CharClass *)other)->value == 0)
      raise("Floating point exception !");
  div = ((CharClass *)self)->value / ((CharClass *)other)->value;
  obj = new(Char, div);
  return (obj);
}

static bool		Char_eq(const Object *self, const Object *other)
{
  char			val1;
  char			val2;

  val1 = ((CharClass *)self)->value;
  val2 = ((CharClass *)other)->value;;
  return (val1 == val2);
}

static bool		Char_lt(const Object *self, const Object *other)
{
  char			val1;
  char			val2;

  val1 = ((CharClass *)self)->value;
  val2 = ((CharClass *)other)->value;;
  return (val1 < val2);
}

static bool		Char_gt(const Object *self, const Object *other)
{
  char			val1;
  char			val2;

  val1 = ((CharClass *)self)->value;
  val2 = ((CharClass *)other)->value;;
  return (val1 > val2);
}

static CharClass _description =
{
  {
    sizeof(CharClass), "Char", &Char_ctor, &Char_dtor,
    &Char_str, &Char_add, &Char_sub, &Char_mul, &Char_div,
    &Char_eq, &Char_gt, &Char_lt
  },
  NULL, 0
};

Class *Char = (Class *)&_description;
