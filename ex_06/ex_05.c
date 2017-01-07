
#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "int.h"
#include "new.h"

void	print_list(Object *list)
{
  size_t	len = len(list);
  Object	*it = begin(list);
  Object	*end = end(list);

  printf("List[%ld]\n", len);
  while (!eq(it, end))
    {
      printf("%s", str(getval(it)));
      incr(it);
    }
  printf("\n");
  delete(it);
  delete(end);
}

int main()
{
  Object* list = new(List, Int);

    push_back(list, new(Int, 1));
    push_back(list, new(Int, 2));
    push_back(list, new(Int, 3));
    push_back(list, new(Int, 4));
    push_back(list, new(Int, 5));
    push_back(list, new(Int, 6));
    push_back(list, new(Int, 7));
    push_back(list, new(Int, 8));

    print_list(list);

    insert(list, 5, new(Int, 5));
    pop_front(list);

    print_list(list);

    pop_back(list);
    push_front(list, new(Int, 0));
    print_list(list);

    printf("array size: %zu\n", len(list));
    setitem(list, 5, 12);
    setitem(list, 6, 13);

    delete(list);
    return 0;
}
