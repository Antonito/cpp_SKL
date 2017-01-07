/*
** point.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_02
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:35:07 2017 Antoine Baché
** Last update Sat Jan  7 18:05:14 2017 Ludovic Petrenko
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "point.h"
#include "raise.h"

typedef struct
{
  Class		base;
  char		*__str__;
  int		x;
  int		y;
} PointClass;

static void	Point_ctor(Object *self, va_list *ap)
{
  PointClass	*obj;

  if (!self || !ap)
    raise("Invalid parameter!");
  obj = self;
  obj->__str__ = NULL;
  obj->x = va_arg(*ap, int);
  obj->y = va_arg(*ap, int);
}

static void	Point_dtor(Object *self)
{
  PointClass	*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Point_str(Object *self)
{
  PointClass		*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%d, %d)>\n", obj->base.__name__,
	       obj->x, obj->y) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static PointClass _description =
{
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_str},
  NULL, 0, 0
};

Class *Point = (Class *)&_description;
