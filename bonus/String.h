/*
** String.h for CppPool in /home/bache_a/work/piscine_cpp/cpp_d03/ex00
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Jan  6 09:01:56 2017 Antoine Baché
** Last update Sat Jan  7 23:04:10 2017 Antoine Baché
*/

#ifndef STRING_H_
# define STRING_H_

# include <stddef.h>
# include "object.h"

typedef struct		StringClass
{
  Class			base;
  char			*str;
  void			(*assign_s)(Object *this, Object const * str);
  void			(*assign_c)(Object *this, char const *s);
  void			(*append_s)(Object *this, Object const *ap);
  void			(*append_c)(Object *this, char const *ap);
  char			(*at)(Object const *this, size_t pos);
  void			(*clear)(Object *this);
  int			(*size)(Object const *this);
  int			(*compare_s)(Object *this, const Object *str);
  int			(*compare_c)(Object *this, char const * str);
  size_t		(*copy)(Object *this, char *s, size_t n, size_t pos);
  char const		*(*c_str)(Object const *this);
  int			(*empty)(Object const *this);
  int			(*find_s)(Object *this, const Object *str, size_t pos);
  int			(*find_c)(Object *this, char const *str, size_t pos);
  void			(*insert_c)(Object *this, size_t pos, char const *str);
  void			(*insert_s)(Object *this, size_t pos, Object const *str);
  int			(*to_int)(Object const *this);
  void			(*aff)(Object const *this);
  void			(*join_c)(Object *this, char delim, char const ** tab);
  void			(*join_s)(Object *this, char delim, Object *tab);
}			StringClass;

extern Class	*String;

#endif /* !STRING_H_ */
