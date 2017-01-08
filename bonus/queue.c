/*
** array.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_05
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 02:06:07 2017 Antoine Baché
** Last update Sun Jan  8 09:41:47 2017 Antoine Baché
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
#include "array.h"
#include "number.h"
#include "queue.h"

static void Queue_ctor(QueueClass* self, va_list* args)
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
    queue_push(self, value);
  va_end(ap);
}

static int	IsInQueue(QueueNode* list, Object *val)
{
  while (list)
    {
      if (list->_type == val)
	return (1);
      list = list->next;
    }
  return (0);
}

static void Queue_dtor(QueueClass* self)
{
  QueueNode*	node;
  QueueNode*	next;

  if (!self)
    raise("Invalid parameter!");
  node = self->_list;
  if (!node)
    return ;
  while (node)
    {
      next = node->next;
      if (!IsInQueue(next, node->_type))
	delete(node->_type);
      free(node);
      node = next;
    }
  free(self->_str);
}

static size_t Queue_len(QueueClass* self)
{
  if (self)
    {
      return (self->_size);
    }
  return (0);
}

static void	Queue_push_back(QueueClass* self, ...)
{
  QueueNode	*node;
  QueueNode	*new_node;
  va_list	ap;

  if (self)
    {
      va_start(ap, self);
      if (!(new_node = malloc(sizeof(QueueNode))))
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
}

static void	Queue_pop_front(QueueClass* self)
{
  QueueNode	*node;

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

static Object	*Queue_front(QueueClass *self)
{
  return (self->_list->_type);
}

static Object	*Queue_back(QueueClass *self)
{
  QueueNode	*node;

  node = self->_list;
  if (!node)
    return (NULL);
  while (node->next)
    node = node->next;
  return (node->_type);
}

static bool	Queue_empty(QueueClass const *self)
{
  return (self->_list == NULL);
}

static void	Queue_swap(QueueClass *self, QueueClass *other)
{
  QueueClass	tmp;

  memcpy(&tmp, self, sizeof(QueueClass));
  memcpy(self, other, sizeof(QueueClass));
  memcpy(other, &tmp, sizeof(QueueClass));
}

static Object *Queue_to_array(QueueClass *self)
{
  Object	*arr;
  QueueNode	*node;
  Object	**tab;
  size_t	i = 0;

  if (!self)
    raise("Invalid parameter!");
  arr = new(Array, self->_size, self->_type, 0);
  node = self->_list;
  tab = *(void ***)((char *)arr + sizeof(Container) +
		    sizeof(Class*) + sizeof(size_t));
  while (node && i < self->_size)
    {
      tab[i] = node->_type;
      node = node->next;
      ++i;
    }
  return (arr);
}

static Object *Queue_to_list(QueueClass *self)
{
  if (!self)
    raise("Invalid parameter!");
  return (self);
}

static Object	*Queue_add(QueueClass *self, Object *other)
{
  QueueClass	*res;
  QueueClass	*o = NULL;
  char		*validTypes[] = { "Array", "Queue", "Stack", "Queue" };

  if (!self || !other)
    raise("Invalid parameter!");

  for (int i = 0; i < 4; ++i)
    if (strcmp(((Class*)other)->__name__, validTypes[i]) == 0)
      o = to_list(other);

  if (!o)
    raise("You can only add an Array with another container!");

  res = new(Queue, self->_type);

  for (Iterator *it = begin((Container *)self);
       it != end((Container *)self); incr(it))
    queue_push(res, getval(it));

  for (Iterator *it = begin((Container *)other);
       it != end((Container *)other); incr(it))
    queue_push(res, getval(it));
  return (res);
}

static Object			*Queue_mul(const QueueClass *self, const Object *other)
{
  int				i;
  QueueNode			*node;
  QueueClass			*new_list;
  const Class			*nb;
  int				max;

  nb = other;
  if (!self || !other || memcmp(nb->__name__, "Int32_t", sizeof("Int32_t")))
    {
      raise("Cannot mult Array (second argument should be Int object)");
    }
  i = 0;
  max = *(uintptr_t *)((uintptr_t)nb + sizeof(Number) + sizeof(char *));
  new_list = new(Queue, self->_type, 0);
  while (i < max)
    {
      node = self->_list;
      while (node)
	{
	  queue_push(new_list, node->_type);
	  node = node->next;
	}
      ++i;
    }
  return (new_list);
}

static QueueClass *Queue_clone(QueueClass *self)
{
  QueueClass	*c;
  QueueNode	*node;

  if (!self)
    raise("Invalid parameter!");
  c = new(Queue, self->_type);
  node = self->_list;
  while (node)
    {
      queue_push(c, clone(node->_type));
      node = node->next;
    }
  return (c);
}

static bool	Queue_eq(QueueClass *self, QueueClass *other)
{
  QueueNode	*a;
  QueueNode	*b;

  if (!self || !other)
    raise("Invalid parameter!");
  if (self->_size != other->_size)
    return (false);
  a = self->_list;
  b = other->_list;
  while (a && b)
    {
      if (!eq(a, b))
	return (false);
      a = a->next;
      b = b->next;
    }
  return (true);
}

static QueueClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(QueueClass), "Queue",
            (ctor_t) &Queue_ctor, (dtor_t) &Queue_dtor, NULL,
            NULL, /*str */
	    (clone_t) &Queue_clone, /* clone */
            (binary_operator_t) &Queue_add,
	    NULL, /* sub */
	    (binary_operator_t) &Queue_mul,
	    NULL, /* div */
            (binary_comparator_t) &Queue_eq, NULL, NULL, /* gt, lt */
        },
        (len_t) &Queue_len,
	NULL,
	NULL,
	NULL,
	NULL,
	(empty_t) &Queue_empty,
	(swap_t) &Queue_swap,
	(front_t) &Queue_front,
	(back_t) &Queue_back,
	(to_array_t) &Queue_to_array,
	(to_list_t) &Queue_to_list
    },
    NULL, 0, NULL, NULL,
    (queue_push_t) &Queue_push_back,
    (queue_pop_t) &Queue_pop_front
};

Class* Queue = (Class*) &_descr;
