/*
** array.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_05
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 02:06:07 2017 Antoine Baché
** Last update Sat Jan  7 17:14:35 2017 Ludovic Petrenko
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct {
    Iterator base;
    ListNode* _node;
    ListClass* _list;
} ListIteratorClass;

static void	_setval(ListClass *self, ListNode *node, va_list *ap)
{
  if (self && ap)
    {
      free(node->_type);
      node->_type = va_new(self->_type, ap);
    }
}

void ListIterator_ctor(ListIteratorClass* self, va_list* args)
{
  if (self && args)
    {
      self->_list = va_arg(*args, ListClass*);
      self->_node = va_arg(*args, ListNode*);
    }
}

bool ListIterator_eq(ListIteratorClass* self, ListIteratorClass* other)
{
  if (self && other)
    {
      if (self->_list != other->_list)
	raise("Comparison between incompatible iterator!");
      return (self->_node == other->_node);
    }
  return (false);
}

bool ListIterator_gt(ListIteratorClass* self, ListIteratorClass* other)
{
  ListNode*	node;

  if (self && other)
    {
      if (self->_list != other->_list)
	raise("Comparison between incompatible iterator!");
      node = other->_node;
      if (node == self->_node)
	return (false);
      while (node)
	{
	  if (node == self->_node)
	    return (true);
	  node = node->next;
	}
    }
  return (false);
}

bool ListIterator_lt(ListIteratorClass* self, ListIteratorClass* other)
{
  ListNode*	node;

  if (self && other)
    {
      node = self->_node;
      if (node == other->_node)
	return (false);
      while (node)
	{
	  if (node == other->_node)
	    return (true);
	  node = node->next;
	}
    }
  return (false);
}

void ListIterator_incr(ListIteratorClass* self)
{
  if (self)
    {
      if (!self->_node)
	raise("Out of range iterator!");
      self->_node = self->_node->next;
    }
}

Object* ListIterator_getval(ListIteratorClass* self)
{
  if (self)
    {
      return (self->_node->_type);
    }
  return (NULL);
}

void ListIterator_setval(ListIteratorClass* self, ...)
{
  va_list	ap;

  if (self)
    {
      va_start(ap, self);
      _setval(self->_list, self->_node, &ap);
      va_end(ap);
    }
}

static ListIteratorClass ListIteratorDescr = {
    {
        {
            sizeof(ListIteratorClass), "ListIterator",
            (ctor_t) &ListIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ListIterator_eq,
            (binary_comparator_t) &ListIterator_gt,
            (binary_comparator_t) &ListIterator_lt,
        },
        (incr_t) &ListIterator_incr,
        (getval_t) &ListIterator_getval,
        (setval_t) &ListIterator_setval,
    },
    NULL,
    0
};

static Class* ListIterator = (Class*) &ListIteratorDescr;

void List_ctor(ListClass* self, va_list* args)
{
  if (self && args)
    {
      self->_type = va_arg(*args, Class *);
      self->_size = 0;
      self->_list = NULL;
    }
}

void List_dtor(ListClass* self)
{
  ListNode*	node;
  ListNode*	next;

  if (self)
    {
      node = self->_list;
      if (!node)
	return ;
      while (node)
	{
	  next = node->next;
	  delete(node->_type);
	  free(node);
	  node = next;
	}
    }
}

size_t List_len(ListClass* self)
{
  if (self)
    {
      return (self->_size);
    }
  return (0);
}

Iterator* List_begin(ListClass* self)
{
  Iterator	*ite;

  ite = NULL;
  if (self)
    {
      ite = new(ListIterator, self->_list);
    }
  return (ite);
}

Iterator* List_end(ListClass* self)
{
  Iterator	*ite;

  ite = NULL;
  if (self)
    {
      ite = new(ListIterator, NULL, 0);
    }
  return (ite);
}

Object* List_getitem(ListClass* self, ...)
{
  size_t	ndx;
  va_list	ap;
  ListNode	*node;
  size_t	i;

  if (self)
    {
      va_start(ap, self);
      ndx = va_arg(ap, size_t);
      va_end(ap);
      node = self->_list;
      if (ndx >= self->_size)
	raise("Index out of range!");
      i = 0;
      while (i < self->_size)
	{
	  if (!node)
	    raise("Corrupted list!");
	  if (i == ndx)
	    return (node->_type);
	  node = node->next;
	  ++i;
	}
    }
  return (NULL);
}


void List_setitem(ListClass* self, ...)
{
  va_list	ap;
  size_t	ndx;
  ListNode*	node;
  size_t	i;

  if (self)
    {
      va_start(ap, self);
      ndx = va_arg(ap, size_t);
      node = self->_list;
      if (ndx >= self->_size)
	raise("Index out of range!");
      i = 0;
      while (i < self->_size)
	{
	  if (!node)
	    raise("Corrupted list!");
	  if (i == ndx)
	    break ;
	  node = node->next;
	  ++i;
	}
      _setval(self, node, &ap);
      va_end(ap);
    }
}

void	List_push_back(ListClass* self, ...)
{
  ListNode	*node;
  ListNode	*new_node;
  va_list	ap;
      printf("DEBUG #01\n");
  if (self)
    {
      va_start(ap, self);
      printf("DEBUG #0\n");
      if (!(new_node = malloc(sizeof(ListNode))))
	raise("Out of memory!");
      printf("DEBUG #1\n");
      new_node->_type = va_arg(ap, __typeof__(self->_type));
      printf("DEBUG #2\n");
      if (!self->_list)
	self->_list = new_node;
      else
	{
	  printf("DEBUG #3\n");
	  node = self->_list;
	  while (node->next)
	    node = node->next;
	  printf("DEBUG #4\n");
	  node->next = new_node;
	}
      new_node->next = NULL;
      printf("DEBUG #5\n");
      self->_size++;
      printf("DEBUG #6\n");
      va_end(ap);
    }
}

void	List_push_front(ListClass* self, ...)
{
  ListNode	*new_node;
  va_list	ap;

  if (self)
    {
      va_start(ap, self);
      if (!(new_node = malloc(sizeof(ListNode))))
	raise("Out of memory!");
      new_node->_type = va_arg(ap, __typeof__(self->_type));
      new_node->next = self->_list;
      self->_list = new_node;
      self->_size++;
      va_end(ap);
    }
}

void	List_pop_back(ListClass* self)
{
    ListNode	*node;

  if (self)
    {
      node = self->_list;
      if (!node || !self->_size)
	raise("Cannot pop from empty list!");
      if (!node->next)
	{
	  delete(node->_type);
	  free(node);
	  self->_list = NULL;
	}
      else
	{
	  while (node->next->next)
	    node = node->next;
	  delete(node->next->_type);
	  free(node->next);
	  node->next = NULL;
	}
      --self->_size;
    }
}

void	List_pop_front(ListClass* self)
{
  ListNode	*node;

  if (self)
    {
      if (!self->_list || !self->_size)
	raise("Cannot pop from empty list!");
      node = self->_list;
      self->_list = node->next;
      delete(node->_type);
      free(node);
      --self->_size;
    }
}

void	List_insert(ListClass* self, ...)
{
  ListNode	*node;
  size_t	ndx;
  size_t	i;
  va_list	ap;
  ListNode	*new_node;

  if (self)
    {
      va_start(ap, self);
      ndx = va_arg(ap, size_t);
      if (ndx >= self->_size)
	raise("Index out of range!");
      if (!(new_node = malloc(sizeof(ListNode))))
	raise("Out of memory!");
      node = self->_list;
      i = 0;
      while (i < ndx && node)
	{
	  ++i;
	  node = node->next;
	}
      if (!node)
	raise("Corrupted list!");
      new_node->_type = va_arg(ap, __typeof__(self->_type));
      new_node->next = node->next;
      node->next = new_node;
      ++self->_size;
    }
}

static ListClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ListClass), "List",
            (ctor_t) &List_ctor, (dtor_t) &List_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &List_len,
        (iter_t) &List_begin,
        (iter_t) &List_end,
        (getitem_t) &List_getitem,
        (setitem_t) &List_setitem,
    },
    NULL, 0, NULL,
    (push_back_t) &List_push_back,
    (push_front_t) &List_push_front,
    (pop_back_t) &List_pop_back,
    (pop_front_t) &List_pop_front,
    (insert_t) &List_insert
};

Class* List = (Class*) &_descr;
