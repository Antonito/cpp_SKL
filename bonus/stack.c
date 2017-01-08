/*
** array.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/ex_05
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 02:06:07 2017 Antoine Baché
** Last update Sun Jan  8 09:42:31 2017 Antoine Baché
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

#include "raise.h"
#include "stack.h"
#include "new.h"
#include "array.h"
#include "number.h"
#include "list.h"

static void Stack_ctor(StackClass* self, va_list* args)
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
    stack_push(self, value);
  va_end(ap);
}

static int	IsInStack(StackNode* list, Object *val)
{
  while (list)
    {
      if (list->_type == val)
	return (1);
      list = list->next;
    }
  return (0);
}

static void Stack_dtor(StackClass* self)
{
  StackNode*	node;
  StackNode*	next;

  if (!self)
    raise("Invalid parameter!");
  node = self->_list;
  if (!node)
    return ;
  while (node)
    {
      next = node->next;
      if (!IsInStack(next, node->_type))
	delete(node->_type);
      free(node);
      node = next;
    }
  free(self->_str);
}

static size_t Stack_len(StackClass* self)
{
  if (self)
    {
      return (self->_size);
    }
  return (0);
}

static void	Stack_push_back(StackClass* self, ...)
{
  StackNode	*node;
  StackNode	*new_node;
  va_list	ap;

  if (self)
    {
      va_start(ap, self);
      if (!(new_node = malloc(sizeof(StackNode))))
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

static void	Stack_pop_back(StackClass* self)
{
    StackNode	*node;

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

static Object	*Stack_back(StackClass *self)
{
  StackNode	*node;

  node = self->_list;
  if (!node)
    return (NULL);
  while (node->next)
    node = node->next;
  return (node->_type);
}

static bool	Stack_empty(StackClass const *self)
{
  return (self->_list == NULL);
}

static void	Stack_swap(StackClass *self, StackClass *other)
{
  StackClass	tmp;

  memcpy(&tmp, self, sizeof(StackClass));
  memcpy(self, other, sizeof(StackClass));
  memcpy(other, &tmp, sizeof(StackClass));
}

static Object *Stack_to_array(StackClass *self)
{
  Object	*arr;
  StackNode	*node;
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

static Object *Stack_to_list(StackClass *self)
{
  Object	*o;

  if (!self)
    raise("Invalid parameter!");
  o = new(List, self->_type);
  memcpy(o, self, sizeof(StackClass));
  memcpy(o, List, sizeof(*List));
  return (self);
}

static Object	*Stack_add(StackClass *self, Object *other)
{
  StackClass	*res;
  StackClass	*o = NULL;
  char		*validTypes[] = { "Array", "Stack", "Stack", "Queue" };

  if (!self || !other)
    raise("Invalid parameter!");

  for (int i = 0; i < 4; ++i)
    if (strcmp(((Class*)other)->__name__, validTypes[i]) == 0)
      o = to_list(other);

  if (!o)
    raise("You can only add an Array with another container!");

  res = new(Stack, self->_type);

  for (Iterator *it = begin((Container *)self);
       it != end((Container *)self); incr(it))
    stack_push(res, getval(it));

  for (Iterator *it = begin((Container *)other);
       it != end((Container *)other); incr(it))
    stack_push(res, getval(it));
  return (res);
}

static Object			*Stack_mul(const StackClass *self, const Object *other)
{
  int				i;
  StackNode			*node;
  StackClass			*new_list;
  const Class			*nb;
  int				max;

  nb = other;
  if (!self || !other || memcmp(nb->__name__, "Int32_t", sizeof("Int32_t")))
    {
      raise("Cannot mult Stack (second argument should be Int object)");
    }
  i = 0;
  max = *(uintptr_t *)((uintptr_t)nb + sizeof(Number) + sizeof(char *));
  new_list = new(Stack, self->_type, 0);
  while (i < max)
    {
      node = self->_list;
      while (node)
	{
	  stack_push(new_list, node->_type);
	  node = node->next;
	}
      ++i;
    }
  return (new_list);
}

static StackClass *Stack_clone(StackClass *self)
{
  StackClass	*c;
  StackNode	*node;

  if (!self)
    raise("Invalid parameter!");
  c = new(Stack, self->_type);
  node = self->_list;
  while (node)
    {
      stack_push(c, clone(node->_type));
      node = node->next;
    }
  return (c);
}

static bool	Stack_eq(StackClass *self, StackClass *other)
{
  StackNode	*a;
  StackNode	*b;

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

static StackClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(StackClass), "Stack",
            (ctor_t) &Stack_ctor, (dtor_t) &Stack_dtor, NULL,
            NULL, /*str */
	    (clone_t) &Stack_clone, /* clone */
            (binary_operator_t) &Stack_add,
	    NULL, /* sub */
	    (binary_operator_t) &Stack_mul,
	    NULL, /* div */
            (binary_comparator_t) &Stack_eq, NULL, NULL, /* gt, lt */
        },
        (len_t) &Stack_len,
        NULL,
        NULL,
        NULL,
        NULL,
	(empty_t) &Stack_empty,
	(swap_t) &Stack_swap,
        NULL,
	(back_t) &Stack_back,
	(to_array_t) &Stack_to_array,
	(to_list_t) &Stack_to_list
    },
    NULL, 0, NULL, NULL,
    (stack_push_t) &Stack_push_back,
    (stack_pop_t) &Stack_pop_back
};

Class* Stack = (Class*) &_descr;
