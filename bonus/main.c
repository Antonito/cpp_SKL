#include <stdio.h>
#include "raise.h"
#include "smart_ptr.h"
#include "int.h"
#include "exceptions.h"
#include "String.h"
#include "float.h"

int	test_types();
int	test_containers();

int	main()
{
  smart_ptr Object	*new_val;
  smart_ptr Object	*str;
  smart_ptr Object	*str1;
  Object		*str2;
  smart_ptr Object	*value;
  smart_ptr auto Object	*money;

  str = unique_ptr(String, "Pete et repete sont sur un bateau.");
  str1 = unique_ptr(String, "Pete tombe a l'eau.");
  money = unique_ptr(Float, 40.0f);
  printf("You have -> $%s left on your account.\n", str(money));
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
