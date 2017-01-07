
#ifndef LIST_H
# define LIST_H

# include "container.h"

extern Class* List; /* List(size, Type, ...)  where ellipsis are Type constructor arguments */

typedef struct ListClass ListClass;

typedef void (*push_back_t)(ListClass* self, ...);
typedef void (*push_front_t)(ListClass* self, ...);
typedef void (*pop_back_t)(ListClass* self);
typedef void (*pop_front_t)(ListClass* self);
typedef void (*insert_t)(ListClass* self, ...);

# define push_back(c, ...)	(((ListClass*) c)->__push_back__(c, __VA_ARGS__))
# define push_front(c, ...)	(((ListClass*) c)->__push_front__(c, __VA_ARGS__))
# define pop_back(c)		(((ListClass*) c)->__pop_back__(c))
# define pop_front(c)		(((ListClass*) c)->__pop_front__(c))
# define insert(c, ...)		(((ListClass*) c)->__insert__(c, __VA_ARGS__))

typedef struct ListNode
{
  Class* _type;
  struct ListNode* next;
}  ListNode;

struct ListClass
{
    Container base;
    Class* _type;
    size_t _size;
    ListNode* _list;
    push_back_t	__push_back__;
    push_front_t	__push_front__;
    pop_back_t	__pop_back__;
    pop_front_t	__pop_front__;
    insert_t	__insert__;
};


#endif
