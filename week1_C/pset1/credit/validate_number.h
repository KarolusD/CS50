#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool validate_number(char input[])
{
  int length = strlen(input);

  for (int i = 0; i < length; i++)
  {
    if (!isdigit(input[i]))
    {
      return false;
    }
  }
  return true;
}