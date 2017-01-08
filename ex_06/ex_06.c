
#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "int.h"
#include "new.h"

void	print_list(Object *list)
{
  size_t	len = len(list);
  Object	*it = begin(list);
  Object	*_end = end(list);

  printf("List[%lu]\n", len);
  while (!eq(it, _end))
    {
      printf("%s", str(getval(it)));
      incr(it);
    }
  printf("\n");
  delete(it);
  delete(_end);
}

int main()
{
  Object* l = new(List, List);
  Object* list = new(List, List);
  Object* l1 = new(List, Int);
  Object* l2 = new(List, Int);
  Object* l3 = new(List, Int, 5, new(Int, 42));

  push_back(l1, new(Int, 1));
  push_back(l1, new(Int, 2));
  push_back(l2, new(Int, 3));
  push_back(l2, new(Int, 4));
  push_back(l2, new(Int, 5));
  push_back(l3, new(Int, 6));
  push_back(l3, new(Int, 7));
  push_back(l3, new(Int, 8));

  push_back(list, l1);
  push_back(list, l2);
  push_back(list, l3);

  Object* list2 = new(List, List);
  Object* l11 = new(List, Int);
  Object* l12 = new(List, Int);
  Object* l13 = new(List, Int);

  push_back(l11, new(Int, 1));
  push_back(l11, new(Int, 2));
  push_back(l12, new(Int, 3));
  push_back(l12, new(Int, 4));
  push_back(l12, new(Int, 5));
  push_back(l13, new(Int, 6));
  push_back(l13, new(Int, 7));
  push_back(l13, new(Int, 8));

  push_back(list2, l11);
  push_back(list2, l12);
  push_back(list2, l13);

  push_back(l, list);
  push_back(l, list2);
  printf("%s\n", str(l));
  delete(l);
  return 0;
}
