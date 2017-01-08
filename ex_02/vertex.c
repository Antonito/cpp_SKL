/*
** vertex.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_02
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:35:16 2017 Antoine Baché
** Last update Sat Jan  7 18:00:35 2017 Ludovic Petrenko
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "vertex.h"
#include "raise.h"

typedef struct
{
  Class	base;
  char	*__str__;
  int	x;
  int	y;
  int	z;
} VertexClass;

static void	Vertex_ctor(Object *self, va_list *ap)
{
  VertexClass	*obj;

  if (!self || !ap)
    raise("Invalid parameter!");
  obj = self;
  obj->__str__ = NULL;
  obj->x = va_arg(*ap, int);
  obj->y = va_arg(*ap, int);
  obj->z = va_arg(*ap, int);
}

static void	Vertex_dtor(Object *self)
{
  VertexClass	*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
}

static char const*	Vertex_str(Object *self)
{
  VertexClass		*obj;

  if (!self)
    raise("Invalid parameter!");
  obj = self;
  if (obj->__str__)
    free(obj->__str__);
  if (asprintf(&obj->__str__, "<%s (%d, %d, %d)>\n", obj->base.__name__,
	       obj->x, obj->y, obj->z) == -1)
    {
      raise("Out of memory");
    }
  return (obj->__str__);
}

static VertexClass _description =
  {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_str},
    NULL, 0, 0, 0
  };

Class *Vertex = (Class *)&_description;
