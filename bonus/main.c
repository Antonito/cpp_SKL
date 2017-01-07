#include <stdio.h>
#include "smart_ptr.h"
#include "int.h"
#include "exceptions.h"

int	main()
{
  smart_ptr Object	*new_val;
  int		i = 0;

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
  printf("Hello %d\n", i);
  return (0);
}
