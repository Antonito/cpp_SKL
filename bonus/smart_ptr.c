/*
** smart_ptr.c for Cpp_SKL in /home/bache_a/work/piscine_cpp/cpp_SKL/bonus
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 13:19:56 2017 Antoine Baché
** Last update Sun Jan  8 00:11:47 2017 Antoine Baché
*/

//
// \file smart_ptr.c
// \brief Smart pointers in GNU C99
//
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "raise.h"
#include "new.h"
#include "smart_ptr.h"

//
// \struct Smart_ptr
//
typedef struct	Smart_ptr
{
  Class		*_type;
  Object	*_ptr;
}	        Smart_ptr;

//
// \fn void _smart_ptr(Class * const type, int mode, ...)
// \param type The object's descriptor
// \param mode UNIQUE_PTR, SHARED_PTR or WEAK_PTR
// \brief Allocate a smart pointer
//
void		*_smart_ptr(Class * const type, int mode, ...)
{
  Smart_ptr	*ptr;
  va_list	ap;
  Class		*tmp;

  if (!type)
    raise("Incorrect arguments !");
  ptr = malloc(sizeof(Smart_ptr) + type->__size__);
  if (!ptr)
    raise("Out of memory !");
  ptr->_type = type;
  va_start(ap, mode);
  ptr->_ptr = ptr + 1;
  tmp = va_new(ptr->_type, &ap);
  va_end(ap);
  memcpy(ptr + 1, tmp, tmp->__size__);
  free(tmp);
  return (ptr->_ptr);
}

//
// \fn void _smart_ptr_free(Object *ptr)
// \param ptr The ptr contained in the smart_ptr
// \brief Deallocate a smart pointer, automatically called when pointer goes out of scope
//
__attribute__((always_inline)) inline void		_smart_ptr_free(Object *ptr)
{
  Smart_ptr	*meta;

  if (!ptr || !*(void **)ptr)
    raise("Incorrect argument !");
  ptr = *(void **)ptr;
  meta = (Smart_ptr *)((uintptr_t)ptr - sizeof(Smart_ptr));
  ((Class *)meta->_ptr)->__del__(meta->_ptr);
  free(meta);
}
