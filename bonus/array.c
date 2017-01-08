/*
** array.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_05
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 02:06:07 2017 Antoine Baché
** Last update Sun Jan  8 07:27:20 2017 Ludovic Petrenko
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdint.h>

#include "raise.h"
#include "array.h"
#include "new.h"
#include "list.h"
#include "number.h"

typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
    char *_str;
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass* _array;
    size_t _idx;
} ArrayIteratorClass;

static void	_setval(ArrayClass *self, size_t ndx, va_list *ap)
{
  if (self && ap && ndx < self->_size)
    {
      delete(self->_tab[ndx]);
      self->_tab[ndx] = va_new(self->_type, ap);
    }
}

static void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
  if (self && args)
    {
      self->_array = va_arg(*args, ArrayClass*);
      self->_idx = va_arg(*args, size_t);
      if (self->_idx > self->_array->_size)
	raise("Out of range iterator!");
    }
}

static bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self && other)
    {
      if (self->_array != other->_array)
	raise("Comparison between incompatible iterator!");
      return (self->_idx == other->_idx);
    }
  return (false);
}

static bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self && other)
    {
      if (self->_array != other->_array)
	raise("Comparison between incompatible iterator!");
      return (self->_idx > other->_idx);
    }
  return (false);
}

static bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self && other)
    {
      if (self->_array != other->_array)
	raise("Comparison between incompatible iterator!");
      return (self->_idx < other->_idx);
    }
  return (false);
}

static void ArrayIterator_incr(ArrayIteratorClass* self)
{
  if (self)
    {
      self->_idx++;
      if (self->_idx > self->_array->_size)
	raise("Out of range iterator!");
    }
}

static Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
  if (self)
    {
      return (getitem((Container *)self->_array, self->_idx));
    }
  return (NULL);
}

static void ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
  va_list	ap;

  if (self)
    {
      va_start(ap, self);
      _setval(self->_array, self->_idx, &ap);
      va_end(ap);
    }
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
	    NULL, /* set */
            NULL, /* str */
	    NULL, /* clone */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ArrayIterator_eq,
            (binary_comparator_t) &ArrayIterator_gt,
            (binary_comparator_t) &ArrayIterator_lt,
        },
        (incr_t) &ArrayIterator_incr,
        (getval_t) &ArrayIterator_getval,
        (setval_t) &ArrayIterator_setval,
    },
    NULL,
    0
};

static Class* ArrayIterator = (Class*) &ArrayIteratorDescr;

static void Array_ctor(ArrayClass* self, va_list* args)
{
  size_t	i;
  va_list	ap;

  if (self && args)
    {
      self->_size = va_arg(*args, size_t);
      self->_type = va_arg(*args, Class *);
      self->_tab = malloc((self->_size + 1) * sizeof(self->_type));
      if (!self->_tab)
	raise("Out of memory !\n");
      memset(self->_tab, 0, self->_size + 1);
      i = 0;
      while (i < self->_size)
	{
	  va_copy(ap, *args);
	  self->_tab[i] = va_new(self->_type, &ap);
	  va_end(ap);
	  ++i;
	}
    }
}

static void Array_dtor(ArrayClass* self)
{
  size_t	i;

  if (self)
    {
      i = 0;
      while (i < self->_size)
	{
	  delete(self->_tab[i]);
	  ++i;
	}
      free(self->_tab);
    }
}

static size_t Array_len(ArrayClass* self)
{
  if (self)
    {
      return (self->_size);
    }
  return (0);
}

static Iterator* Array_begin(ArrayClass* self)
{
  Iterator	*ite;

  ite = NULL;
  if (self)
    {
      ite = new(ArrayIterator, self, 0);
    }
  return (ite);
}

static Iterator* Array_end(ArrayClass* self)
{
  Iterator	*ite;

  ite = NULL;
  if (self)
    {
      ite = new(ArrayIterator, self, self->_size);
    }
  return (ite);
}

static Object* Array_getitem(ArrayClass* self, ...)
{
  size_t	ndx;
  va_list	ap;
  size_t	i;

  if (self)
    {
      va_start(ap, self);
      ndx = va_arg(ap, size_t);
      va_end(ap);
      i = 0;
      while (i < self->_size)
	{
	  if (i == ndx)
	    return (self->_tab[i]);
	  ++i;
	}
    }
  return (NULL);
}

static void Array_setitem(ArrayClass* self, ...)
{
  va_list	ap;
  size_t	ndx;

  if (self)
    {
      va_start(ap, self);
      ndx = va_arg(ap, size_t);
      _setval(self, ndx, &ap);
      va_end(ap);
    }
}

static Object	*Array_to_array(ArrayClass *self)
{
  if (!self)
    raise("Invalid parameter!");
  return (self);
}

static Object	*Array_to_list(ArrayClass *self)
{
  Object	*list;

  if (!self)
    raise("Invalid parameter!");
  list = new(List, self->_type);
  for (size_t i = 0; i < self->_size; ++i)
    push_back(list, getitem((Container *)self, i));
  return (list);
}

static bool	Array_empty(ArrayClass *self)
{
  if (!self)
    raise("Invalid parameter!");
  return (self->_size == 0);
}

static void	Array_swap(ArrayClass *self, ArrayClass *other)
{
  ArrayClass	tmp;

  if (!self || !other)
    raise("Invalid parameter!");
  memcpy(&tmp, self, sizeof(ArrayClass));
  memcpy(self, other, sizeof(ArrayClass));
  memcpy(other, &tmp, sizeof(ArrayClass));
}

static Object	*Array_front(ArrayClass *self)
{
  if (!self)
    raise("Invalid parameter!");
  if (self->_size == 0)
    return (NULL);
  else
    return (self->_tab[0]);
}

static Object	*Array_back(ArrayClass *self)
{
  if (!self)
    raise("Invalid parameter!");
  if (self->_size == 0)
    return (NULL);
  else
    return (self->_tab[self->_size - 1]);
}

static Object	*Array_add(ArrayClass *self, Object *other)
{
  ArrayClass	*res;
  size_t	i;
  ArrayClass	*o = NULL;
  char		*validTypes[] = { "Array", "List", "Stack", "Queue" };

  if (!self || !other)
    raise("Invalid parameter!");

  for (int i = 0; i < 4; ++i)
    if (strcmp(((Class*)other)->__name__, validTypes[i]) == 0)
      {
      o = to_array(other);
      break;
      }

  if (!o)
    raise("You can only add an Array with another container!");

  res = new(Array, self->_size + o->_size, self->_type);
  i = 0;
  for (size_t j = 0; j < self->_size; ++i, ++j)
    res->_tab[i] = self->_tab[j];
  for (size_t j = 0; j < o->_size; ++i, ++j)
    res->_tab[j + self->_size] = o->_tab[j];
  return (res);
}

static Object			*Array_mul(const ArrayClass *self, const Object *other)
{
  int				i;
  ArrayClass			*old;
  ArrayClass			*new_arr;
  const Class			*nb;
  int				max;

  nb = other;
  if (!self || !other || memcmp(nb->__name__, "Int32_t", sizeof("Int32_t")))
    {
      raise("Cannot mult Array (second argument should be Int object)");
    }
  i = 0;
  max = *(uintptr_t *)((uintptr_t)nb + sizeof(Number) + sizeof(char *));
  new_arr = new(Array, 0, self->_type);
  while (i < max)
    {
      old = new_arr;
      new_arr = add(new_arr, self);
      free(old);
      ++i;
    }
  return (new_arr);
}

static char const	*Array_to_string(ArrayClass *self)
{
  char *last;
  size_t	i;

  (void)last;
  (void)i;
  if (!self)
    raise("Invalid parameter!");
  if (self->_str)
    free(self->_str);
  if (asprintf(&self->_str, "Array<%s>[%lu]\n{\n", self->_type->__name__, self->_size) == -1)
    raise("Out of memory!");
  i = 0;
  while (i < self->_size)
    {
      if (self->_tab[i])
      	{
      	  last = self->_str;
      	  if (asprintf(&self->_str, "%s%s, ", last, str(self->_tab[i])) == -1)
      	    raise("Out of memory!");
      	  free(last);
      	}
      ++i;
    }
  last = self->_str;
  if (asprintf(&self->_str, "%s\n}\n", last) == -1)
    raise("Out of memory!");
  free(last);
  return (self->_str);
}

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
	    NULL, /* set */
            (to_string_t) &Array_to_string, /*str */
	    NULL, /*clone*/
            (binary_operator_t) &Array_add,
	    NULL, /* sub */
	    (binary_operator_t) &Array_mul,
	    NULL, /* div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
	(empty_t) &Array_empty,
	(swap_t) &Array_swap,
	(front_t) &Array_front,
	(back_t) &Array_back,
	(to_array_t) &Array_to_array,
	(to_list_t) &Array_to_list
    },
    NULL, 0, NULL, NULL
};

Class* Array = (Class*) &_descr;
