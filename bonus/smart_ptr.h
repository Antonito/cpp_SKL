/*
** smart_ptr.h for cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/bonus
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 13:20:23 2017 Antoine Baché
** Last update Sun Jan  8 00:34:47 2017 Antoine Baché
*/

#ifndef UNIQUE_PTR_H_
# define UNIQUE_PTR_H_

# include "object.h"

/*
** Put it in front of variable definition
** The destructor will be called automatically when variable
** goes out of scope
*/
# define smart_ptr	__attribute__((cleanup(_smart_ptr_free)))

/*
** Avaible smart pointers
** UNIQUE_PTR is the only available right now
*/
enum	_smart_ptr_mode
  {
    UNIQUE_PTR,
    SHARED_PTR,
    WEAK_PTR
  };


# define unique_ptr(c, ...)	_smart_ptr(c, UNIQUE_PTR, __VA_ARGS__)
# define shared_ptr(c, ...)	_smart_ptr(c, SHARED_PTR, __VA_ARGS__)
# define weak_ptr(c, ...)	_smart_ptr(c, WEAK_PTR, __VA_ARGS__)

/*
** Allocate a smart pointer
*/
void		*_smart_ptr(Class * const type, int, ...);

/*
** Deallocate a smart pointer
*/
void		_smart_ptr_free(Object *ptr);

#endif /* !UNIQUE_PTR_H */
