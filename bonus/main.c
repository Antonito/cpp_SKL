#include <stdio.h>
#include "smart_ptr.h"
#include "int.h"

int	main()
{
  smart_ptr Object	*new_val;

  new_val = unique_ptr(Int, 4);
  printf("Int str is -> %s\n", str(new_val));
  return (0);
}
