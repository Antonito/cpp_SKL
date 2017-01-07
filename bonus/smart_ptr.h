/*
** smart_ptr.h for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/bonus
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 13:20:23 2017 Antoine Baché
** Last update Sat Jan  7 16:26:33 2017 Antoine Baché
*/

#ifndef UNIQUE_PTR_H_
# define UNIQUE_PTR_H_

# include "object.h"

/*
** Called when variable goes out of scope
*/
# define smart_ptr	__attribute__((cleanup(_smart_ptr_free)))

/*
** Available smart pointers
*/
enum	_smart_ptr_mode
  {
    UNIQUE_PTR,
    SHARED_PTR,
    WEAK_PTR
  };

/*
** Initializers
*/
# define unique_ptr(c, ...)	_smart_ptr(c, UNIQUE_PTR, __VA_ARGS__)
# define shared_ptr(c, ...)	_smart_ptr(c, SHARED_PTR, __VA_ARGS__)
# define weak_ptr(c, ...)	_smart_ptr(c, WEAK_PTR, __VA_ARGS__)

void		*_smart_ptr(Class *type, int, ...);
void		_smart_ptr_free(Object *ptr);

#endif /* !UNIQUE_PTR_H */
