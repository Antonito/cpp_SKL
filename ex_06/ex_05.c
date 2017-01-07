
#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "int.h"
#include "new.h"


int main()
{
  Object* list = new(List, Int);
    Object* it;
    Object* it_end;

    printf("ok\n");
    push_back(list, new(Int, 1));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));
    push_back(list, new(Int, 2));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));
    push_back(list, new(Int, 3));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));
    push_back(list, new(Int, 4));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));
    push_back(list, new(Int, 5));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));
    push_back(list, new(Int, 6));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));
    push_back(list, new(Int, 7));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));
    push_back(list, new(Int, 8));
    printf("list[%ld] = %s\n", len(list) - 1, str(getitem(list, len(list) - 1)));

    it = begin(list);
    it_end = end(list);
    printf("array size: %zu\n", len(list));
    setitem(list, 5, 12);
    setitem(list, 6, 13);
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }

    delete(it);
    delete(it_end);
    delete(list);
    return 0;
}
