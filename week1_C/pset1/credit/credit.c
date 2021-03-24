#include <stdio.h>
#include <string.h>

#include "validate_number.h"
#include "validate_card_number.h"

#define MAXINPUT 100

int main(void)
{
  char input[MAXINPUT] = "";

  do
  {
    printf("Enter card number: ");
    scanf("%s", input);

  } while (validate_number(input) == 0);

  validate_card_number(input);
  return 0;
}
