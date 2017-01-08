/*
** array.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_05
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 02:06:07 2017 Antoine Baché
** Last update Sat Jan  7 18:34:52 2017 Ludovic Petrenko
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

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

static void	_setval(ArrayClass *self, size_t ndx, va_list *ap)
{
  if (self && ap && ndx < self->_size)
    {
      free(self->_tab[ndx]);
      self->_tab[ndx] = va_new(self->_type, ap);
    }
}

void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
  if (self && args)
    {
      self->_array = va_arg(*args, ArrayClass*);
      self->_idx = va_arg(*args, size_t);
      if (self->_idx >= self->_array->_size)
	raise("Out of range iterator!");
    }
}

bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self && other)
    {
      if (self->_array != other->_array)
	raise("Comparison between incompatible iterator!");
      return (self->_idx == other->_idx);
    }
  return (false);
}

bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self && other)
    {
      if (self->_array != other->_array)
	raise("Comparison between incompatible iterator!");
      return (self->_idx > other->_idx);
    }
  return (false);
}

bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self && other)
    {
      if (self->_array != other->_array)
	raise("Comparison between incompatible iterator!");
      return (self->_idx < other->_idx);
    }
  return (false);
}

void ArrayIterator_incr(ArrayIteratorClass* self)
{
  if (self)
    {
      self->_idx++;
      if (self->_idx >= self->_array->_size)
	raise("Out of range iterator!");
    }
}

Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
  if (self)
    {
      return (getitem((Container *)self->_array, self->_idx));
    }
  return (NULL);
}

void ArrayIterator_setval(ArrayIteratorClass* self, ...)
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
  va_list	ap;

  if (self && args)
    {
      printf("%p\n", self);
      self->_size = va_arg(*args, size_t);
      printf("%lu\n", self->_size);
      self->_type = va_arg(*args, Class *);
<<<<<<< HEAD
      printf("%p\n", self->_type);
      self->_tab = calloc(self->_size + 1, sizeof(self->_type));
      printf("%p\n", self->_tab);
=======
      self->_tab = malloc(sizeof(self->_type) * (self->_size + 1));
>>>>>>> 769bf0f2765739d36af96027c1209ed45abc43ec
      if (!self->_tab)
	raise("Out of memory !\n");
      //      memset(self->_tab, 0, sizeof(self->_type) * (self->_size + 1));
      i = 0;
      while (i < self->_size)
	{
<<<<<<< HEAD
	  va_copy(new_list, *args);
	  self->_tab[i] = va_new(self->_type, &new_list);
	  va_end(new_list);
=======
	  va_copy(ap, *args);
	  self->_tab[i] = va_new(self->_type, &ap);
	  va_end(ap);
>>>>>>> 769bf0f2765739d36af96027c1209ed45abc43ec
	  ++i;
	}
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
      free(self->_tab);
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
<<<<<<< HEAD
      ite = new(ArrayIterator, self->_tab, 0);
=======
      ite = new(ArrayIterator, self, 0);
>>>>>>> 769bf0f2765739d36af96027c1209ed45abc43ec
    }
  return (ite);
}

Iterator* Array_end(ArrayClass* self)
{
  Iterator	*ite;

  ite = NULL;
  if (self)
    {
      ite = new(ArrayIterator, self, 0);
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
