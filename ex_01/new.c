/*
** new.c for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_01
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 00:33:57 2017 Antoine Baché
** Last update Sat Jan  7 17:56:05 2017 Ludovic Petrenko
*/

#include <stdlib.h>
#include <string.h>
#include "raise.h"
#include "new.h"

void	*new(Class *class)
{
  void	*obj;

  obj = NULL;
  if (!class)
    raise("Invalid parameter!");
  obj = malloc(class->__size__);
  if (!obj)
    {
      raise("Out of memory");
    }
  memcpy(obj, class, class->__size__);
  if (class->__init__)
    class->__init__(obj);
  return (obj);
}

void	delete(Object *ptr)
{
  Class	*obj;

  if (!ptr)
    raise("Invalid parameter!");
  obj = ptr;
  if (obj->__del__)
    obj->__del__(obj);
  free(ptr);
}
