#include <stdio.h>
#include "types.h"
#include "colors.h"

#define LINE		WHITE_BOLD_INTENS"----------\n"CLEAR
#define DISPLAY(s)	WHITE_BOLD_INTENS""s"\n"CLEAR
#define OK(s)		GREEN_BOLD_INTENS"OK: "s"\n"CLEAR
#define ERROR(s)	RED_BOLD_INTENS"Error: "s"\n"CLEAR
#define LEAVING		LINE""CYAN_BOLD_INTENS"Leaving %s\n"CLEAR, __func__
#define	TEST_STR(s)	CYAN_BOLD_INTENS"Testing "s"\n"CLEAR""LINE

int	test_types();
int	test_containers();

static void		_test_smart_ptr(void)
{
  smart_ptr Object	*val1;
  smart_ptr Object	*arr = unique_ptr(Array, 3, String, "Toto");
  auto it = begin(arr);
  auto it_end = end(arr);

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

  push_back(list2, l1);
  push_back(list2, l2);
  push_back(list2, l3);

  push_back(l, list);
  push_back(l, list2);
  printf(DISPLAY("%s\n"), str(l));
  delete(l);
  printf(LEAVING);
}

int		main(void)
{
  _test_smart_ptr();
  _test_exceptions();
  _test_auto();
  _test_containers();
  return (0);
#if 0
  test_types();
#endif
}
