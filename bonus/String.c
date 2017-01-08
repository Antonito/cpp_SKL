/*
** String.c for CppPool in /home/bache_a/work/piscine_cpp/cpp_d03/ex00
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  6 09:02:26 2017 Antoine Baché
** Last update Sun Jan  8 04:44:07 2017 Antoine Baché
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "raise.h"
#include "new.h"
#include "number.h"
#include "String.h"

static void		String_assign_s(Object *this, Object const * str)
{
  StringClass		*self;
  const StringClass	*other;

  if (!this || !str)
    {
      raise("Invalid parameters");
    }
  self = this;
  other = str;
  self->assign_c(self, other->str);
}

static void		String_assign_c(Object *this, char const *s)
{
  StringClass		*self;

  if (!this)
    {
      raise("Invalid parameters");
    }
  self = this;
  free(self->str);
  self->str = NULL;
  if (s)
    self->str = strdup(s);
}

static void		String_append_s(Object *this, Object const *ap)
{
  StringClass		*self;
  const StringClass	*other;

  if (!this || !ap)
    {
      raise("Invalid parameters");
    }
  other = ap;
  self = this;
  self->append_c(this, other->str);
}

static void		String_append_c(Object *this, char const *ap)
{
  StringClass		*self;
  char			*tmp;

  if (!this || !ap)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    asprintf(&tmp, "%s%s", self->str, ap);
  else
    asprintf(&tmp, "%s", ap);
  free(self->str);
  self->str = tmp;
}

static char		String_at(Object const *this, size_t pos)
{
  size_t		len;
  StringClass const	*self;

  if (!this)
    {
      raise("Invalid parameters");
    }
  self = this;
  len = 0;
  if (self->str)
    len = strlen(self->str);
  if (pos < len)
    return (self->str[pos]);
  return (-1);
}

static void		String_clear(Object * const this)
{
  size_t		len;
  StringClass		*self;

  if (!this)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    {
      len = strlen(self->str);
      memset(self->str, '\0', len * sizeof(char));
    }
}

static int		String_size(Object const * const this)
{
  StringClass const	*self;

  if (!this)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    return ((int)strlen(self->str));
  return (-1);
}

static int		String_compare_s(Object *this, const Object *str)
{
  if (!this || !str)
    {
      raise("Invalid parameters");
    }
  return (((StringClass *)this)->compare_c(this, ((StringClass *)str)->str));
}

static int		String_compare_c(Object *this, char const * str)
{
  StringClass		*self;

  if (!this || !str)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    {
      return (strcmp(self->str, str));
    }
  return (-1);
}

static size_t		String_copy(Object *this, char *s, size_t n, size_t pos)
{
  StringClass		*self;
  size_t		i;
  size_t		len;

  if (!this || !s)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    {
      len = strlen(self->str);
      if (pos < len)
	{
	  i = 0;
	  while (i < n && (self->str + pos)[i])
	    {
	      s[i] = (self->str + pos)[i];
	      ++i;
	    }
	  return (i);
	}
    }
  return (0);
}

static char const	*String_c_str(Object const *this)
{
  if (!this)
    {
      raise("Invalid parameters");
    }
  return (((StringClass *)this)->str);
}

static int		String_empty(Object const * const this)
{
  StringClass const	*self;

  if (!this)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    return ((*(self->str)) ? -1 : 1);
  return (1);
}

static int		String_find_s(Object *this, const Object *str, size_t pos)
{
  if (!this || !str)
    {
      raise("Invalid parameters");
    }
  return (((StringClass *)this)->find_c(this, ((StringClass *)str)->str, pos));
}

static int		String_find_c(Object *this, char const *str, size_t pos)
{
  size_t		len;
  char			*found;
  StringClass const	*self;

  if (!this || !str)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    {
      len = strlen(self->str);
      if (pos < len)
	{
	  found = strstr(self->str + pos, str);
	  if (found)
	    return ((int)(found - self->str));
	}
    }
  return (-1);
}

static void		String_insert_c(Object *this, size_t pos, char const *str)
{
  size_t		len;
  size_t		len_str;
  char			*buff;
  size_t		i;
  size_t		j;
  StringClass		*self;

  if (!this || !str)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    {
      len = strlen(self->str);
      len_str = strlen(str);
      pos = (pos > len) ? len : pos;
      buff = malloc(sizeof(char) * (len + len_str + 1));
      if (!buff)
	return ;
      memset(buff, '\0', len + len_str + 1);
      i = 0;
      while (i < pos)
	{
	  buff[i] = self->str[i];
	  ++i;
	}
      j = 0;
      while (j < len_str)
	{
	  buff[j + pos] = str[j];
	  ++j;
	}
      while (i < len)
	{
	  buff[pos + j] = self->str[i];
	  ++j;
	  ++i;
	}
      free(self->str);
      self->str = buff;
    }
}

static void		String_insert_s(Object *this, size_t pos, Object const *str)
{
  if (!this || !str)
    {
      raise("Invalid parameters");
    }
  ((StringClass *)this)->insert_c(this, pos, ((StringClass *)str)->str);
}

static int		String_to_int(Object const *this)
{
  StringClass const	*self;

  if (!this)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    {
      return (atoi(self->str));
    }
  return (0);
}

static void		String_aff(Object const *this)
{
  StringClass const	*self;

  if (!this)
    {
      raise("Invalid parameters");
    }
  self = this;
  if (self->str)
    {
      write(1, self->str, strlen(self->str));
    }
}

static void		String_join_c(Object *this, char delim, char const ** tab)
{
  size_t		i;
  char			*tmp;
  StringClass		*self;

  if (!this || !tab)
    {
      raise("Invalid parameters");
    }
  self = this;
  i = 0;
  if (!tab[0])
    {
      self->clear(this);
      return ;
    }
  while (tab[i])
    {
      if (i != 0 && self->str)
	asprintf(&tmp, "%s%c%s", self->str, delim, tab[i]);
      else
	asprintf(&tmp, "%s", tab[i]);
      free(self->str);
      self->str = tmp;
      ++i;
    }
}

static void		String_join_s(Object *this, char delim, Object *tab)
{
  size_t		i;
  char			*tmp;
  StringClass		*self;
  StringClass		*_tab;

  if (!this || !tab)
    {
      raise("Invalid parameters");
    }
  self = this;
  _tab = tab;
  i = 0;
  if (_tab[0].empty(&_tab[0]) == 1)
    {
      self->clear(this);
      return ;
    }
  while (1)
    {
      if (_tab[i].empty(&_tab[i]) == 1)
	break;
      if (i != 0 && self->str)
	asprintf(&tmp, "%s%c%s", self->str, delim, _tab[i].c_str(&_tab[i]));
      else
	asprintf(&tmp, "%s", _tab[i].c_str(&_tab[i]));
      free(self->str);
      self->str = tmp;
      ++i;
    }
}

static void			String_ctor(Object *this, va_list *ap)
{
  StringClass			*self;
  const char			*s;

  if (!this || !ap)
    {
      raise("Cannot create String");
    }
  self = this;
  s = va_arg(*ap, char *);
  if (s)
    self->str = strdup(s);
  else
    self->str = NULL;
}

static void			String_dtor(Object *this)
{
  if (!this)
    {
      raise("Cannot delete String");
    }
  free(((StringClass *)this)->str);
}

static Object			*String_add(const Object *self, const Object *other)
{
  StringClass			*str;

  str = new(String, ((StringClass *)self)->str);
  str->append_s(str, other);
  return (str);
}

static Object			*String_mul(const Object *self, const Object *other)
{
  int				i;
  const StringClass		*str;
  StringClass			*new_str;
  const Class			*nb;
  int				max;

  str = self;
  nb = other;
  if (!self || !other || memcmp(nb->__name__, "Int32_t", sizeof("Int32_t")))
    {
      raise("Cannot mult String (second argument should be Int object)");
    }
  new_str = NULL;
  i = 0;
  max = *(uintptr_t *)((uintptr_t)nb + sizeof(Number) + sizeof(char *));
  while (i < max)
    {
      if (!new_str)
	{
	  new_str = new(String, str->c_str(str));
	}
      else
	new_str->append_c(new_str, (const char *)str->c_str(str));
      ++i;
    }
  return (new_str);
}

void				String_set(Object *self, ...)
{
  char				*str;
  va_list			ap;

  if (!self)
    {
      raise("Cannot set String");
    }
  va_start(ap, self);
  str = va_arg(ap, char *);
  if (!str)
    raise("Cannot set String");
  ((StringClass *)self)->assign_c(self, str);
  va_end(ap);
}

static Object*			String_clone(const Object *self)
{
  if (!self)
    {
      raise("Cannot clone String");
    }
  return (new(String, ((StringClass *)self)->c_str(self)));
}

static StringClass		_description =
  {
    {
      sizeof(StringClass), "String", &String_ctor, &String_dtor, &String_set,
      (to_string_t)&String_c_str, &String_clone, &String_add,
      NULL, &String_mul, NULL, NULL,
      NULL, NULL
    },
    NULL, &String_assign_s, &String_assign_c, &String_append_s,
    &String_append_c, &String_at, &String_clear, &String_size,
    &String_compare_s, &String_compare_c, &String_copy, &String_c_str,
    &String_empty, &String_find_s, &String_find_c, &String_insert_c,
    &String_insert_s, &String_to_int, &String_aff, &String_join_c,
    &String_join_s
  };

Class *String = (Class *)&_description;
