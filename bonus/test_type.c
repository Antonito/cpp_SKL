
#include <stdio.h>
#include <assert.h>
#include "raise.h"
#include "int8_t.h"
#include "int16_t.h"
#include "int32_t.h"
#include "int64_t.h"
#include "uint8_t.h"
#include "uint16_t.h"
#include "uint32_t.h"
#include "uint64_t.h"
#include "new.h"
#include "object.h"

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
  test(new(Int8_t, 12), new(Int8_t, 12), new(Int8_t, 13));
  test(new(Int16_t, 12), new(Int16_t, 12), new(Int16_t, 13));
  test(new(Int32_t, 12), new(Int32_t, 12), new(Int32_t, 13));
  test(new(Int64_t, 12), new(Int64_t, 12), new(Int64_t, 13));
  test(new(Uint8_t, 12), new(Uint8_t, 12), new(Uint8_t, 13));
  test(new(Uint16_t, 12), new(Uint16_t, 12), new(Uint16_t, 13));
  test(new(Uint32_t, 12), new(Uint32_t, 12), new(Uint32_t, 13));
  test(new(Uint64_t, 12), new(Uint64_t, 12), new(Uint64_t, 13));

  Object *a = new(Int64_t, -500);
  Object *b = new(Int32_t, -50);
  Object *c = new(Int16_t, -5);
  Object *d = new(Int8_t, -1);
  Object *e = new(Uint64_t, 500);
  Object *f = new(Uint32_t, 50);
  Object *g = new(Uint16_t, 5);
  Object *h = new(Uint8_t, 1);

  printf("result div: %s\n", str(add(g, b)));
  printf("result div: %s\n", str(mul(f, c)));
  printf("result div: %s\n", str(div(e, d)));
  printf("result div: %s\n", str(sub(d, e)));
  printf("result div: %d\n", eq(c, f));
  printf("result div: %d\n", lt(b, g));
  printf("result div: %d\n", gt(a, h));
  /*printf("result div: %s\n", str(add(a, NULL)));
  printf("result div: %s\n", str(sub(d, NULL)));
  printf("result div: %s\n", str(mul(b, NULL)));
  printf("result div: %s\n", str(div(c, NULL)));
  printf("result div: %d\n", eq(e, NULL));
  printf("result div: %d\n", lt(f, NULL));
  printf("result div: %d\n", gt(f, NULL));*/
  delete(a);
  delete(b);
  delete(c);
  delete(d);
  delete(e);
  delete(f);
  delete(g);
  delete(h);
  return 0;
}
