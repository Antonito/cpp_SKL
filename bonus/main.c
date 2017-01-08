#include <stdio.h>
#include "raise.h"
#include "smart_ptr.h"
#include "int.h"
#include "exceptions.h"
#include "String.h"
#include "array.h"
#include "float.h"
#include "auto.h"

int	test_types();
int	test_containers();

char	*test_string[] = {"Auto test1", "Auto test2"};

int	main()
{
  smart_ptr Object	*new_val;
  smart_ptr Object	*str;
  smart_ptr Object	*str1;
  Object		*str2;
  smart_ptr Object	*value;
  auto money		= 42.f;

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
  //  test_types();
  test_containers();
  return (0);
}
