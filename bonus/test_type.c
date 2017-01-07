
#include <stdio.h>
#include <assert.h>

#include "int.h"
#include "int8_t.h"
#include "new.h"

void test(Object* a, Object* b, Object* c)
{
    printf("a = %s, b = %s, c = %s\n", str(a), str(b), str(c));
    assert(eq(a, b));
    assert(!gt(a, b));
    assert(!lt(a, b));
    assert(!eq(a, c));
    assert(eq(a, b));
    assert(gt(c, a));

    delete(a);
    delete(b);
    delete(c);
}


int main()
{
    test(new(Int, 12), new(Int, 12), new(Int, 13));
    test(new(Int8_t, 12), new(Int8_t, 12), new(Int8_t, 13));
    return 0;
}
