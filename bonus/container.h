
#ifndef CONTAINER_H
# define CONTAINER_H

# include "object.h"
# include "iterator.h"

typedef struct Container_s Container;

typedef Iterator* (*iter_t)(Container* self);
typedef size_t (*len_t)(Container* self);
typedef Object* (*getitem_t)(Container* self, ...);
typedef void (*setitem_t)(Container* self, ...);
typedef bool (*empty_t)(Container const *self);
typedef void (*swap_t)(Container *self, Container *other);
typedef Object *(*front_t)(Container *self);
typedef Object *(*back_t)(Container *self);

struct Container_s {
    Class base;
    len_t       __len__;
    iter_t      __begin__;
    iter_t      __end__;
    getitem_t   __getitem__;
    setitem_t   __setitem__;
    empty_t	__empty__;
    swap_t __swap__;
    front_t	__front__;
    back_t	__back__;
};

# define len(c)                 (((Container*) c)->__len__(c))
# define begin(c)               (((Container*) c)->__begin__(c))
# define end(c)                 (((Container*) c)->__end__(c))
# define getitem(c, ...)        (((Container*) c)->__getitem__(c, __VA_ARGS__))
# define setitem(c, ...)        (((Container*) c)->__setitem__(c, __VA_ARGS__))
# define empty(c)		(((Container*) c)->__empty__(c))
# define swap(c)		(((Container*) c)->__swap__(c))
# define front(c)		(((Container*) c)->__front__(c))
# define back(c)		(((Container*) c)->__back__(c))

#endif
