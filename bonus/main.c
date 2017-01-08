#include <stdio.h>
#include <assert.h>
#include "types.h"
#include "colors.h"

#define LINE		WHITE_BOLD_INTENS"----------\n"CLEAR
#define DISPLAY(s)	WHITE_BOLD_INTENS""s"\n"CLEAR
#define OK(s)		GREEN_BOLD_INTENS"OK: "s"\n"CLEAR
#define ERROR(s)	RED_BOLD_INTENS"Error: "s"\n"CLEAR
#define LEAVING		LINE""CYAN_BOLD_INTENS"Leaving %s\n"CLEAR, __func__
#define	TEST_STR(s)	CYAN_BOLD_INTENS"Testing "s"\n"CLEAR""LINE

static void		_test_smart_ptr(void)
{
  smart_ptr Object	*val1;
  smart_ptr Object	*arr = unique_ptr(Array, 3, String, "Toto");
  Object		*toto = clone(arr);
  auto it = begin(arr);
  auto it_end = end(arr);
  smart_ptr Object	*str;
  smart_ptr Object	*str1;
  auto money		= 42.f;

  printf("%s\n", str(toto));
  str = unique_ptr(String, "Pete et repete sont sur un bateau.");
  str1 = unique_ptr(String, "Pete tombe a l'eau.");
  printf("You have -> $%.2f left on your account.\n", money);

  printf(TEST_STR("Smart pointers"));
  val1 = unique_ptr(Int, 42);
  printf(DISPLAY("Value is -> %s"), str(val1));
  while (lt(it, it_end))
    {
      printf(DISPLAY("ArrayContent is -> %s\n"), str(getval(it)));
      incr(it);
    }
  delete(it);
  delete(it_end);
  printf(LEAVING);
}

static void		_test_exceptions(void)
{
  printf(TEST_STR("Exceptions"));
  TRY
    {
      printf(DISPLAY("Trying some stuff.."));
      TRY
	{
	  Object	*str;
	  Object	*mult_str;
	  Object	*final_str;
	  Object        *times;

	  printf(DISPLAY("Trying some more stuff"));
	  str = new(String, "Hello World");
	  times = new(Int, 4);
	  printf(OK("Allocated a String object -> %s"), str(str));
	  ((StringClass *)str)->append_c(str, " !");
	  printf(OK("Added punctuaction -> %s"), str(str));
	  mult_str = mul(str, times);
	  printf(OK("Multiplied str by %s"), str(times));
	  printf(DISPLAY("--> %s"), str(mult_str));
	  final_str = add(mult_str, str);
	  printf(OK("Added one str"));
	  printf(DISPLAY("--> %s"), str(final_str));
	  delete(times);
	  delete(str);
	  delete(mult_str);
	  delete(final_str);
	  printf(DISPLAY("Deleted strings"));
	  printf(DISPLAY("Throwing 2"));
	  THROW(2);
	  printf(ERROR("Should not be displayed"));
	}
      CATCH(1)
	{
	  printf(ERROR("Should not be displayed"));
	}
      CATCH(2)
	{
	  printf(OK("Caught Exception 2"));
	}
      ETRY;
      printf(DISPLAY("Throwing 1"));
      THROW(1);
      printf(ERROR("Should not be displayed"));
    }
  CATCH(0)
    {
      printf(ERROR("Should not be displayed"));
    }
  CATCH(1)
    {
      printf(OK("Caught Exception 1"));
    }
  ETRY
  printf(LEAVING);
}

static void	_test_auto()
{
  char	*test_string[] = {"Auto test1", "Auto test2"};
  auto money = 42.f;

  printf(TEST_STR("Auto"));
  printf(DISPLAY("You have -> $%.2f left on your account.\n"), money);
  for (auto i = 0; i < 2; ++i)
    {
      auto str = test_string[i];

      printf(OK("--> %s"), str);
    }
  printf(LEAVING);
}

void _test_containers(void)
{
  printf(TEST_STR("Containers"));
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
  printf(DISPLAY("%s\n"), str(l));
  delete(l);
  printf(LEAVING);
}

void _test_operations(Object* a, Object* b, Object* c)
{
  printf(DISPLAY("a = %s, b = %s, c = %s"), str(a), str(b), str(c));
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

static void	_test_types()
{
  printf(TEST_STR("Types"));
  _test_operations(new(Int8_t, 12), new(Int8_t, 12), new(Int8_t, 13));
  _test_operations(new(Int16_t, 12), new(Int16_t, 12), new(Int16_t, 13));
  _test_operations(new(Int32_t, 12), new(Int32_t, 12), new(Int32_t, 13));
  _test_operations(new(Int64_t, 12), new(Int64_t, 12), new(Int64_t, 13));
  _test_operations(new(Uint8_t, 12), new(Uint8_t, 12), new(Uint8_t, 13));
  _test_operations(new(Uint16_t, 12), new(Uint16_t, 12), new(Uint16_t, 13));
  _test_operations(new(Uint32_t, 12), new(Uint32_t, 12), new(Uint32_t, 13));
  _test_operations(new(Uint64_t, 12), new(Uint64_t, 12), new(Uint64_t, 13));
  _test_operations(new(Float, 12.0f), new(Float, 12.0f), new(Float, 13.0f));
  _test_operations(new(Double, 12.0), new(Double, 12.0), new(Double, 13.0));
  printf(OK("Stdint tests"));

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
  printf(DISPLAY("================INT============="));
  printf(DISPLAY("result add: %s"), str(result));
  delete(result);
  result = mul(f, c);
  printf(DISPLAY("result mul: %s"), str(result));
  delete(result);
  result = div(e, d);
  printf(DISPLAY("result div: %s"), str(result));
  delete(result);
  result = sub(d, e);
  printf(DISPLAY("result sub: %s"), str(result));
  printf(DISPLAY("result eq: %d"), eq(c, f));
  printf(DISPLAY("result lt: %d"), lt(b, g));
  printf(DISPLAY("result gt: %d"), gt(a, h));
  printf(OK("Ints"));

  printf(DISPLAY("================FLOAT============="));
  delete(result);
  printf(DISPLAY("g: %s"), str(g));
  printf(DISPLAY("i: %s"), str(i));
  result = add(g,i);
  printf(DISPLAY("result add: %s"), str(result));
  delete(result);
  result = mul(g,i);
  printf(DISPLAY("result mul: %s"), str(result));
  delete(result);
  result = div(g,i);
  printf(DISPLAY("result div: %s"), str(result));
  delete(result);
  result = sub(g, i);
  printf(DISPLAY("result sub: %s"), str(result));
  delete(result);
  printf(DISPLAY("result eq: %d"), eq(g, i));
  printf(DISPLAY("result lt: %d"), lt(g, i));
  printf(DISPLAY("result gt: %d"), gt(g, i));
  printf(OK("Float"));

  printf(DISPLAY("================DOUBLE============="));
  printf(DISPLAY("i: %s"), str(i));
  printf(DISPLAY("j: %s"), str(j));
  result = add(i, j);
  printf(DISPLAY("result add: %s"), str(result));
  delete(result);
  result = mul(j, g);
  printf(DISPLAY("result mul: %s"), str(result));
  delete(result);
  result = sub(i, j);
  printf(DISPLAY("result sub: %s"), str(result));
  delete(result);
  printf(DISPLAY("result eq: %d"), eq(i, j));
  printf(DISPLAY("result lt: %d"), lt(i, j));
  printf(DISPLAY("result gt: %d"), gt(i, j));
  printf(OK("Double"));

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
}

int		main(void)
{
  printf(TEST_STR("Main"));
  _test_smart_ptr();
  _test_exceptions();
  _test_auto();
  _test_containers();
  _test_types();
  printf(LEAVING);
  return (0);
}
