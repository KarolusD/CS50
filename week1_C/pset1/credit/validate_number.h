#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool validate_number(char input[])
{
  for (int i = 0; i < strlen(input); i++)
  {
    if (!isdigit(input[i]))
    {
      return false;
    }
  }
  return true;
}