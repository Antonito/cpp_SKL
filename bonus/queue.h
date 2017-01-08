
#ifndef QUEUE_H
# define QUEUE_H

# include "container.h"
# include "stack.h"

extern Class* Queue; /* Queue(size, Type, ...)  where ellipsis are Type constructor arguments */

typedef struct QueueClass QueueClass;

typedef void (*queue_push_t)(QueueClass* self, ...);
typedef void (*queue_pop_t)(QueueClass* self);

# define queue_push(c, ...)	(((QueueClass*) c)->__push_back__(c, __VA_ARGS__))
# define queue_pop(c)		(((QueueClass*) c)->__pop_back__(c))

typedef struct QueueNode
{
  Class* _type;
  struct QueueNode* next;
}  QueueNode;

struct QueueClass
{
  Container base;
  Class* _type;
  size_t _size;
  QueueNode* _list;
  char *	_str;
  queue_push_t	__push_back__;
  queue_pop_t	__pop_front__;
};

#endif
