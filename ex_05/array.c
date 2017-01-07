/*
** array.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_05
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 02:06:07 2017 Antoine Baché
** Last update Sat Jan  7 03:04:17 2017 Antoine Baché
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass* _array;
    size_t _idx;
} ArrayIteratorClass;

void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
}

bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
}

bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
}

bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
}

void ArrayIterator_incr(ArrayIteratorClass* self)
{
}

Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
}

void ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
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

void Array_ctor(ArrayClass* self, va_list* args)
{
  size_t	i;
  va_list	new_list;

  if (self && args)
    {
      self->_size = va_arg(*args, size_t);
      self->_type = va_arg(*args, Class *);
      self->_tab = malloc(sizeof(self->_type) * (self->_size + 1));
      va_copy(new_list, *args);
      if (!self->_tab)
	raise("Out of memory !\n");
      memset(self->_tab, 0, sizeof(self->_type) * (self->_size + 1));
      i = 0;
      while (i < self->_size)
	{
	  self->_tab[i] = new(self->_type, &new_list);
	  ++i;
	}
      va_end(new_list);
    }
}

void Array_dtor(ArrayClass* self)
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
    }
}

size_t Array_len(ArrayClass* self)
{
  if (self)
    {
      return (self->_size);
    }
  return (0);
}

Iterator* Array_begin(ArrayClass* self)
{
  Iterator	*ite;

  ite = NULL;
  if (self)
    {
      ite = new(ArrayIterator, self->_tab, self->_size, 0);
    }
  return (ite);
}

Iterator* Array_end(ArrayClass* self)
{
  Iterator	*ite;

  ite = NULL;
  if (self)
    {
      ite = new(ArrayIterator, self->_tab, self->_size, 0);
    }
  return (ite);
}

Object* Array_getitem(ArrayClass* self, ...)
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
	    return (&self->_tab[i]);
	  ++i;
	}
    }
  return (NULL);
}


void Array_setitem(ArrayClass* self, ...)
{
  size_t	ndx;
  size_t	i;
  va_list	ap;
  Object	**new_objs;

  if (self)
    {
      va_start(ap, self);
      ndx = va_arg(ap, size_t);
      new_objs = malloc(sizeof(self->_type) * (self->_size + 2));
      ndx = (ndx > self->_size) ? self->_size : ndx;
      memcpy(new_objs, self->_tab, sizeof(self->_type) * ndx);
      new_objs[ndx] = new(self->_type, &ap);
      if (self->_size - ndx > 0)
	memcpy(new_objs + ndx + 1, self->_tab + ndx + 1,
	       sizeof(self->_type) * (self->_size - ndx));
      self->_tab[self->_size + 1] = NULL;
      free(self->_tab);
      self->_tab = new_objs;
      ++self->_size;
      va_end(ap);
    }
}

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
    },
    NULL, 0, NULL
};

Class* Array = (Class*) &_descr;
