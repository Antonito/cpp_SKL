
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
#include "float.h"
#include "double.h"
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
  test(new(Float, 12.0f), new(Float, 12.0f), new(Float, 13.0f));
  test(new(Double, 12.0), new(Double, 12.0), new(Double, 13.0));

  Object *a = new(Int64_t, -500);
  Object *b = new(Int32_t, -50);
  Object *c = new(Int16_t, -5);
  Object *d = new(Int8_t, -1);
  Object *e = new(Uint64_t, 500);
  Object *f = new(Uint32_t, 50);
  Object *g = new(Uint16_t, 5);
  Object *h = new(Uint8_t, 1);
  Object *i = new(Float, 4.2);
  Object *j = new(Double, 5.2);

  Object *result = add(g, b);
  printf("================TEST STDINT=============\n");
  printf("result add: %s\n", str(add(g, b)));
  delete(result);
  result = mul(f, c);
  printf("result mul: %s\n", str(result));
  delete(result);
  result = div(e, d);
  printf("result div: %s\n", str(result));
  delete(result);
  result = sub(d, e);
  printf("result sub: %s\n", str(result));
  printf("result eq: %d\n", eq(c, f));
  printf("result lt: %d\n", lt(b, g));
  printf("result gt: %d\n\n", gt(a, h));

  printf("================TEST FLOAT=============\n");
  delete(result);
  result = add(g,i);
  printf("result add: %s\n", str(result));
  delete(result);
  result = mul(g,i);
  printf("result mul: %s\n", str(result));
  delete(result);
  result = div(g,i);
  printf("result div: %s\n", str(result));
  delete(result);
  printf("result sub: %s\n", str(sub(i, e)));
  printf("result eq: %d\n", eq(c, i));
  printf("result lt: %d\n", lt(i, g));
  printf("result gt: %d\n", gt(a, i));

  printf("================TEST DOUBLE=============\n");
  printf("j: %s\n", str(j));
  printf("i: %s\n", str(i));
  printf("result add: %s\n", str(add(i, j)));
  printf("result mul: %s\n", str(mul(j, g)));
  printf("result div: %s\n", str(div(i, j)));
  printf("result sub: %s\n", str(sub(i, j)));
  printf("result eq: %d\n", eq(i, j));
  printf("result lt: %d\n", lt(i, j));
  printf("result gt: %d\n", gt(i, j));

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
  delete(i);
  delete(j);
  return 0;
}
