/*
** array.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_05
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 02:06:07 2017 Antoine Baché
** Last update Sun Jan  8 08:14:36 2017 Arthur ARNAUD
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

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

  if (!self || !node || !ap)
    raise("Invalid parameter!");
  delete(node->_type);
  node->_type = va_new(self->_type, ap);
}

static void ListIterator_ctor(ListIteratorClass* self, va_list* args)
{
  if (!self || !args)
    raise("Invalid parameter!");
  self->_list = va_arg(*args, ListClass*);
  self->_node = va_arg(*args, ListNode*);
}

static bool ListIterator_eq(ListIteratorClass* self, ListIteratorClass* other)
{
  if (!self || !other)
    raise("Invalid parameter!");
  if (self->_list != other->_list)
    raise("Comparison between incompatible iterator!");
  return (self->_node == other->_node);
}

static bool ListIterator_gt(ListIteratorClass* self, ListIteratorClass* other)
{
  ListNode*	node;

  if (!self || !other)
    raise("Invalid parameter!");
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
  return (false);
}

static bool ListIterator_lt(ListIteratorClass* self, ListIteratorClass* other)
{
  ListNode*	node;

  if (!self || !other)
    raise("Invalid parameter!");
  node = self->_node;
  if (node == other->_node)
    return (false);
  while (node)
    {
      if (node == other->_node)
	return (true);
      node = node->next;
    }
  return (false);
}

static void ListIterator_incr(ListIteratorClass* self)
{
  if (!self)
    raise("Invalid parameter!");
  if (!self->_node)
    raise("Out of range iterator!");
  self->_node = self->_node->next;
}

static Object* ListIterator_getval(ListIteratorClass* self)
{
  if (!self)
    raise("Invalid parameter!");
  return (self->_node->_type);
}

static void ListIterator_setval(ListIteratorClass* self, ...)
{
  va_list	ap;

  if (!self)
    raise("Invalid parameter!");
  va_start(ap, self);
  _setval(self->_list, self->_node, &ap);
  va_end(ap);
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

static void List_ctor(ListClass* self, va_list* args)
{
  uint32_t	n;
  uint32_t	i = 0;
  Object	*value = NULL;
  va_list	ap;

  if (!self || !args)
    raise("Invalid parameter!");
  self->_type = va_arg(*args, Class *);
  va_copy(ap, *args);
  n = va_arg(ap, uint32_t);
  self->_size = 0;
  self->_list = NULL;
  printf("%u\n", n);
  if (n)
    value = va_arg(ap, Object*);
  while (i++ < n)
    push_back(self, value);
  va_end(ap);
}

static int	IsInList(ListNode* list, Object *val)
{
  if (!list)
    raise("Invalid parameter!");
  while (list)
    {
      if (list->_type == val)
	return (1);
      list = list->next;
    }
  return (0);
}

static void List_dtor(ListClass* self)
{
  ListNode*	node;
  ListNode*	next;

  if (!self)
    raise("Invalid parameter!");
  node = self->_list;
  if (!node)
    return ;
  while (node)
    {
      next = node->next;
      if (!IsInList(next, node->_type))
	delete(node->_type);
      free(node);
      node = next;
    }
  free(self->_str);
}

static size_t List_len(ListClass* self)
{
  if (!self)
    raise("Invalid parameter!");
  return (self->_size);
}

static Iterator* List_begin(ListClass* self)
{
  Iterator	*ite;

  if (!self)
    raise("Invalid parameter!");
  ite = NULL;
  ite = new(ListIterator, self, self->_list);
  return (ite);
}

static Iterator* List_end(ListClass* self)
{
  Iterator	*ite;

  if (!self)
    raise("Invalid parameter!");
  ite = NULL;
  ite = new(ListIterator, self, NULL);
  return (ite);
}

static Object* List_getitem(ListClass* self, ...)
{
  size_t	ndx;
  va_list	ap;
  ListNode	*node;
  size_t	i;

  if (!self)
    raise("Invalid parameter!");
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
  return (NULL);
}

static __attribute__((sentinel)) void List_setitem(ListClass* self, ...)
{
  va_list	ap;
  size_t	ndx;
  ListNode*	node;
  size_t	i;

  if (!self)
    raise("Invalid parameter!");
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

static void	List_push_back(ListClass* self, ...)
{
  ListNode	*node;
  ListNode	*new_node;
  va_list	ap;

  if (!self)
    raise("Invalid parameter!");
  va_start(ap, self);
  if (!(new_node = malloc(sizeof(ListNode))))
    raise("Out of memory!");
  new_node->_type = va_arg(ap, __typeof__(self->_type));
  if (!self->_list)
    self->_list = new_node;
  else
    {
      node = self->_list;
      while (node->next)
	node = node->next;
      node->next = new_node;
    }
  new_node->next = NULL;
  self->_size++;
  va_end(ap);
}

static void	List_push_front(ListClass* self, ...)
{
  ListNode	*new_node;
  va_list	ap;

  if (!self)
    raise("Invalid parameter!");
  va_start(ap, self);
  if (!(new_node = malloc(sizeof(ListNode))))
    raise("Out of memory!");
  new_node->_type = va_arg(ap, __typeof__(self->_type));
  new_node->next = self->_list;
  self->_list = new_node;
  self->_size++;
  va_end(ap);
}

static void	List_pop_back(ListClass* self)
{
  ListNode	*node;

  if (!self)
    raise("Invalid parameter!");
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

static void	List_pop_front(ListClass* self)
{
  ListNode	*node;

  if (!self)
    raise("Invalid parameter!");
  if (!self->_list || !self->_size)
    raise("Cannot pop from empty list!");
  node = self->_list;
  self->_list = node->next;
  delete(node->_type);
  free(node);
  --self->_size;
}

static void	List_insert(ListClass* self, ...)
{
  ListNode	*node;
  size_t	ndx;
  size_t	i;
  va_list	ap;
  ListNode	*new_node;

  if (!self)
    raise("Invalid parameter!");
  va_start(ap, self);
  ndx = va_arg(ap, size_t);
  if (ndx >= self->_size)
    raise("Index out of range!");
  if (!(new_node = malloc(sizeof(ListNode))))
    raise("Out of memory!");
  node = self->_list;
  i = 0;
  while (i < ndx - 1 && node)
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
  va_end(ap);
}

static Object	*List_front(ListClass *self)
{
  if (!self)
    raise("Invalid parameter!");
  return (self->_list->_type);
}

static Object	*List_back(ListClass *self)
{
  ListNode	*node;

  if (!self)
    raise("Invalid parameter!");
  node = self->_list;
  if (!node)
    return (NULL);
  while (node->next)
    node = node->next;
  return (node->_type);
}

static bool	List_empty(ListClass const *self)
{
  if (!self)
    raise("Invalid parameter!");
  return (self->_list == NULL);
}

static void	List_clear(ListClass *self)
{
  ListNode*	node;
  ListNode*	next;

  if (!self)
    raise("Invalid parameter!");
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
  self->_list = NULL;
  self->_size = 0;
}

static void	List_swap(ListClass *self, ListClass *other)
{
  ListClass	tmp;

  if (!self || !other)
    raise("Invalid parameter!");
  memcpy(&tmp, self, sizeof(ListClass));
  memcpy(self, other, sizeof(ListClass));
  memcpy(other, &tmp, sizeof(ListClass));
}

static void	List_reverse(ListClass *self)
{
  ListNode	*rev = NULL;
  ListNode	*node;
  ListNode	*next;

  if (!self)
    raise("Invalid parameter!");
  node = self->_list;
  while (node)
    {
      next = node->next;
      node->next = rev;
      rev = node;
      node = next;
    }
  self->_list = rev;
}

static char const	*List_to_string(ListClass *self)
{
  char		*last;
  ListNode	*node;

  if (!self)
    raise("Invalid parameter!");
  if (self->_str)
    free(self->_str);
  if (asprintf(&self->_str, "List<%s>[%lu]\n", self->_type->__name__, self->_size) == -1)
    raise("Out of memory!");
  node = self->_list;
  while (node)
    {
      last = self->_str;
      if (asprintf(&self->_str, "%s%s", last, str(node->_type)) == -1)
	raise("Out of memory!");
      free(last);
      node = node->next;
    }
  return (self->_str);
}

static ListClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ListClass), "List",
            (ctor_t) &List_ctor, (dtor_t) &List_dtor,
            (to_string_t) &List_to_string, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &List_len,
        (iter_t) &List_begin,
        (iter_t) &List_end,
        (getitem_t) &List_getitem,
        (setitem_t) &List_setitem,
	(empty_t) &List_empty,
	(swap_t) &List_swap,
	(front_t) &List_front,
	(back_t) &List_back
    },
    NULL, 0, NULL, NULL,
    (push_back_t) &List_push_back,
    (push_front_t) &List_push_front,
    (pop_back_t) &List_pop_back,
    (pop_front_t) &List_pop_front,
    (insert_t) &List_insert,
    (clear_t) &List_clear,
    (reverse_t) &List_reverse,

};

Class* List = (Class*) &_descr;
