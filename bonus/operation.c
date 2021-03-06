#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raise.h"
#include "object.h"
#include "number.h"

enum Type {INT8_T, INT16_T, INT32_T, INT64_T, FLOAT, DOUBLE};

Object *	check_op(const Object *a, const Object *b, char op)
{
  Number *_a = (Number *)a;
  Number *_b = (Number *)b;
  enum Type type_a;
  enum Type type_b;

  if (a == NULL || b == NULL)
    raise("you cannot do operations with NULL values");

  if (strncmp(_a->base.__name__, "Int8_t", 6) == 0 || strncmp(_a->base.__name__, "Uint8_t", 7) == 0)
    type_a = INT8_T;

  if (strncmp(_a->base.__name__, "Int16_t", 7) == 0 || strncmp(_a->base.__name__, "Uint16_t", 8) == 0)
    type_a = INT16_T;

  if (strncmp(_a->base.__name__, "Int32_t", 7) == 0 || strncmp(_a->base.__name__, "Uint32_t", 8) == 0)
    type_a = INT32_T;

  if (strncmp(_a->base.__name__, "Int64_t", 7) == 0 || strncmp(_a->base.__name__, "Uint64_t", 8) == 0)
    type_a = INT64_T;

  if (strncmp(_a->base.__name__, "Float", 5) == 0)
    type_a = FLOAT;

  if (strncmp(_a->base.__name__, "Double", 6) == 0)
    type_a = DOUBLE;

  if (strncmp(_b->base.__name__, "Int8_t", 6) == 0 || strncmp(_b->base.__name__, "Uint8_t", 7) == 0)
    type_b = INT8_T;

  if (strncmp(_b->base.__name__, "Int16_t", 7) == 0 || strncmp(_b->base.__name__, "Uint16_t", 8) == 0)
    type_b = INT16_T;

  if (strncmp(_b->base.__name__, "Int32_t", 7) == 0 || strncmp(_b->base.__name__, "Uint32_t", 8) == 0)
    type_b = INT32_T;

  if (strncmp(_b->base.__name__, "Int64_t", 7) == 0 || strncmp(_b->base.__name__, "Uint64_t", 8) == 0)
    type_b = INT64_T;

  if (strncmp(_b->base.__name__, "Float", 5) == 0)
    type_b = FLOAT;

  if (strncmp(_b->base.__name__, "Double", 6) == 0)
    type_b = DOUBLE;

  switch(op)
    {
    case '+':
	if (type_a > type_b)
		return _a->real_add(a, b, false);
	else
		return _b->real_add(b, a, true);
	break;
    case '-':
	if (type_a > type_b)
		return _a->real_sub(a, b, false);
	else
		return _b->real_sub(b, a, true);
	break;
    case '*':
	if (type_a > type_b)
		return _a->real_mul(a, b, false);
	else
		return _b->real_mul(b, a, true);
	break;
    case '/' :
	if (type_a > type_b)
		return _a->real_div(a, b, false);
	else
		return _b->real_div(b, a, true);
	break;
    default:
	break;
    }
  return (NULL);
}

bool	check_cmp(const Object *a, const Object *b, char op)
{
  Number *_a = (Number *)a;
  Number *_b = (Number *)b;
  enum Type type_a;
  enum Type type_b;

  if (a == NULL || b == NULL)
    raise("you cannot do comparaisons with NULL values");

  if (strncmp(_a->base.__name__, "Int8_t", 6) == 0 || strncmp(_a->base.__name__, "Uint8_t", 7) == 0)
    type_a = INT8_T;

  if (strncmp(_a->base.__name__, "Int16_t", 7) == 0 || strncmp(_a->base.__name__, "Uint16_t", 8) == 0)
    type_a = INT16_T;

  if (strncmp(_a->base.__name__, "Int32_t", 7) == 0 || strncmp(_a->base.__name__, "Uint32_t", 8) == 0)
    type_a = INT32_T;

  if (strncmp(_a->base.__name__, "Int64_t", 7) == 0 || strncmp(_a->base.__name__, "Uint64_t", 8) == 0)
    type_a = INT64_T;

  if (strncmp(_a->base.__name__, "Float", 5) == 0)
    type_a = FLOAT;

  if (strncmp(_a->base.__name__, "Double", 6) == 0)
    type_a = DOUBLE;


  if (strncmp(_b->base.__name__, "Int8_t", 6) == 0 || strncmp(_b->base.__name__, "Uint8_t", 7) == 0)
    type_b = INT8_T;

  if (strncmp(_b->base.__name__, "Int16_t", 7) == 0 || strncmp(_b->base.__name__, "Uint16_t", 8) == 0)
    type_b = INT16_T;

  if (strncmp(_b->base.__name__, "Int32_t", 7) == 0 || strncmp(_b->base.__name__, "Uint32_t", 8) == 0)
    type_b = INT32_T;

  if (strncmp(_b->base.__name__, "Int64_t", 7) == 0 || strncmp(_b->base.__name__, "Uint64_t", 8) == 0)
    type_b = INT64_T;

  if (strncmp(_b->base.__name__, "Float", 5) == 0)
    type_b = FLOAT;

  if (strncmp(_b->base.__name__, "Double", 6) == 0)
    type_b = DOUBLE;

  switch(op)
    {
    case '=' :
	if (type_a > type_b)
		return _a->real_eq(a, b);
	else
		return _b->real_eq(b, a);
	break;
    case '<' :
	if (type_a > type_b)
		return _a->real_lt(a, b);
	else
		return _b->real_gt(b, a);
	break;
    case '>' :
	if (type_a > type_b)
		return _a->real_gt(a, b);
	else
		return _b->real_lt(b, a);
	break;
    default:
	break;
    }
  return (false);
}
