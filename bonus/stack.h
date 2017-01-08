
#ifndef STACK_H
# define STACK_H

# include "container.h"

extern Class* Stack; /* Stack(size, Type, ...)  where ellipsis are Type constructor arguments */

typedef struct StackClass StackClass;

typedef void (*push_t)(StackClass* self, ...);
typedef void (*pop_t)(StackClass* self);

# define push(c, ...)	(((StackClass*) c)->__push_back__(c, __VA_ARGS__))
# define pop(c)		(((StackClass*) c)->__pop_back__(c))
# define top(c)		(((StackClass*) c)->__back__(c))


typedef struct StackNode
{
  Class* _type;
  struct StackNode* next;
}  StackNode;

struct StackClass
{
  Container base;
  Class* _type;
  size_t _size;
  StackNode* _list;
  char *	_str;
  push_t	__push_back__;
  pop_t	__pop_back__;
};


#endif
