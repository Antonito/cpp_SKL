/*
** smart_ptr.h for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/bonus
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 13:20:23 2017 Antoine Baché
** Last update Sun Jan  8 00:11:51 2017 Antoine Baché
*/

//
// \file smart_ptr.h
// \brief Smart pointers in GNU C99
//
#ifndef UNIQUE_PTR_H_
# define UNIQUE_PTR_H_

# include "object.h"

//
// Called when variable goes out of scope
//
# define smart_ptr	__attribute__((cleanup(_smart_ptr_free)))

//
// \enum _smart_ptr_mode
// \brief Possible smart pointer, only UNIQUE_PTR is implemented right now
//
enum	_smart_ptr_mode
  {
    UNIQUE_PTR,
    SHARED_PTR,
    WEAK_PTR
  };

//
// Initializers
//
# define unique_ptr(c, ...)	_smart_ptr(c, UNIQUE_PTR, __VA_ARGS__)
# define shared_ptr(c, ...)	_smart_ptr(c, SHARED_PTR, __VA_ARGS__)
# define weak_ptr(c, ...)	_smart_ptr(c, WEAK_PTR, __VA_ARGS__)

void		*_smart_ptr(Class * const type, int, ...);
void		_smart_ptr_free(Object *ptr);

#endif /* !UNIQUE_PTR_H */
