
#include <stdio.h>
#include <assert.h>

#include "int8_t.h"
#include "int16_t.h"
#include "int32_t.h"
#include "int64_t.h"
#include "uint8_t.h"
#include "uint16_t.h"
#include "uint32_t.h"
#include "uint64_t.h"
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
  printf("TESTING INIT STDINT TYPES\n");
  /* test(new(Int8_t, 12), new(Int8_t, 12), new(Int8_t, 13)); */
  /* test(new(Int16_t, 12), new(Int16_t, 12), new(Int16_t, 13)); */
  /* test(new(Int32_t, 12), new(Int32_t, 12), new(Int32_t, 13)); */
  /* test(new(Int64_t, 12), new(Int64_t, 12), new(Int64_t, 13)); */
  /* test(new(Uint8_t, 12), new(Uint8_t, 12), new(Uint8_t, 13)); */
  /* test(new(Uint16_t, 12), new(Uint16_t, 12), new(Uint16_t, 13)); */
  /* test(new(Uint32_t, 12), new(Uint32_t, 12), new(Uint32_t, 13)); */
  /* test(new(Uint64_t, 12), new(Uint64_t, 12), new(Uint64_t, 13)); */
  Object *a = new(Int32_t, 50);
  Object *b = new(Int8_t, 10);

  Object *toto = ((Class *)a)->__add__(b, a);
  printf("toto : %s\n", str(toto));
  delete(toto);
  delete(b);
  delete(a);
  return 0;
}
