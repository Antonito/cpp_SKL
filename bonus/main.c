#include <stdio.h>
#include "types.h"
#include "colors.h"

#define DISPLAY(s)	WHITE_BOLD_INTENS""s"\n"CLEAR
#define OK(s)		GREEN_BOLD_INTENS"OK: "s"\n"CLEAR
#define ERROR(s)	RED_BOLD_INTENS"Error: "s"\n"CLEAR
#define LEAVING		CYAN_BOLD_INTENS"Leaving %s\n"CLEAR, __func__
#define	TEST_STR(s)	CYAN_BOLD_INTENS"Testing "s"\n"CLEAR

int	test_types();
int	test_containers();

char	*test_string[] = {"Auto test1", "Auto test2"};

static void		_test_smart_ptr(void)
{
  smart_ptr Object	*val1;

  printf(TEST_STR("Smart pointers"));
  val1 = unique_ptr(Int, 42);
  printf(DISPLAY("Value is -> %s"), str(val1));
  printf(LEAVING);
}

static void		_test_exceptions()
{
  printf(TEST_STR("Exceptions"));
  TRY
    {
      printf(DISPLAY("Trying some stuff.."));
      TRY
	{
	  printf(DISPLAY("Trying some more stuff"));
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

int		main()
{
  smart_ptr Object	*new_val;
  smart_ptr Object	*str;
  smart_ptr Object	*str1;
  Object		*str2;
  smart_ptr Object	*value;
  auto money		= 42.f;

  _test_smart_ptr();
  _test_exceptions();
  return (0);

  str = unique_ptr(String, "Pete et repete sont sur un bateau.");
  str1 = unique_ptr(String, "Pete tombe a l'eau.");
  printf("You have -> $%.2f left on your account.\n", money);

  for (auto i = 0; i < 2; ++i)
    {
      auto str = test_string[i];
      printf("--> %s\n", str);
    }

  value = unique_ptr(Int, 3);
  printf("%s\n", str(str1));
  str2 = mul(str1, value);
  printf("%s\n", str(str2));
  new_val = unique_ptr(Int, 4);
  TRY
    {
      int	i;

      i = 3;
      printf("Hello %d\n", i);
      TRY
	{
	  printf("New Hello\n");
	  THROW(1);
	  printf("I throwed a 1\n");
	}
      CATCH(1)
	{
	  printf("Caught 1 !\n");
	}
      ETRY;
      THROW(2);
      printf("AFTER THROW Val is now -> %d\n", ((ExceptionClass *)_except)->value);
    }
  CATCH(2)
    {
      printf("Caught 2 !\n");
    }
  ETRY;
  delete(str2);
  test_types();
  test_containers();
  return (0);
}
