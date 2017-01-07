/*
** exceptions.h for CppPool in /home/bache_a/work/piscine_cpp/cpp_SKL/bonus
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Jan  7 16:30:20 2017 Antoine Baché
** Last update Sun Jan  8 00:39:19 2017 Antoine Baché
*/

#ifndef EXCEPTIONS_H_
# define EXCEPTIONS_H_

# include <stdint.h>
# include <setjmp.h>
# include "new.h"
# include "object.h"

typedef struct	ExceptionClass ExceptionClass;

/*
** List of defined exceptions
*/
enum ExceptionsCode {
  NO_EXCEPTION = 0,
  NULL_EXCEPTION,
  TEST_EXCEPTION
};

/*
** ExceptionClass
**
** Allows us to implement a try-catch behavior with
** setjmp and longjmp
*/
struct	       ExceptionClass
{
  Class			base;
  jmp_buf		buff;
  enum ExceptionsCode	value;
  enum ExceptionsCode	(*getException)(const ExceptionClass * const self);
};

extern Class	*Exception;

void		_free_exception(Object *);

/*
** Try and catch in GNU C99
**
** Every TRY must end with ETRY. Example:
**
** TRY
** {
** // Some stuff
** THROW(SOME_EXCEPTION);
** }
** CATCH(SOME_EXCEPTION)
** {
** // HANDLE SOME STUFF
** }
** ETRY
**
*/
# define	TRY							\
  do {									\
  __attribute__((cleanup(_free_exception)))Object *_except = new(Exception, NULL); \
  ((ExceptionClass *)_except)->value = setjmp(((ExceptionClass *)_except)->buff); \
  if (!((ExceptionClass *)_except)->value)

# define	THROW(X)							\
  longjmp(((ExceptionClass *)_except)->buff, X);

# define	CATCH(X)							\
  else if (((ExceptionClass *)_except)->getException(_except) == (X))

# define	ETRY								\
  } while (0);

#endif /* !EXCEPTIONS_H_ */
