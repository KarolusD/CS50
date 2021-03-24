#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validate_card_number(char input[])
{
  int length = strlen(input);

  int odd_nums_res = 0;
  int even_nums_res = 0;

  for (int i = length - 1; i >= 0; i--)
  {
    // changing char (ascii) to number (decimal)
    int odd_num = input[i] - '0';

    // starting from the first number on the end (odd)
    if ((length - i) % 2 == 1)
    {
      odd_nums_res += odd_num;
    }
    else
    {
      // changing char (ascii) to number (decimal)
      int even_num_doubled = (input[i] - '0') * 2;

      if (even_num_doubled < 10)
      {
        even_nums_res += even_num_doubled;
      }
      else
      {
        char even_num_products[3];
        // change int to chars array
        sprintf(even_num_products, "%d", even_num_doubled);
        even_nums_res += (even_num_products[0] - '0') + (even_num_products[1] - '0');
      }
    }
  }
  int result = odd_nums_res + even_nums_res;

  if (result % 10 == 0)
  {
    int first_num = input[0] - '0';
    int second_num = input[1] - '0';

    switch (length)
    {
    // Probably VISA
    case 13:
      if (first_num == 4)
      {
        printf("VISA\n");
        return true;
      }

      printf("INVALID\n");
      return false;

    // Probably AMERICAN EXPRESS
    case 15:
      if (first_num == 3 && (second_num == 4 || second_num == 7))
      {
        printf("AMEX\n");
        return true;
      }

      printf("INVALID\n");
      return false;

    // Probably MASTER CARD or VISA
    case 16:
      if (first_num == 5 && (second_num == 1 || second_num == 2 || second_num == 3 || second_num == 4 || second_num == 5))
      {
        printf("MASTERCARD\n");
        return true;
      }
      else if (first_num == 4)
      {
        printf("VISA\n");
        return true;
      }

      printf("INVALID\n");
      return false;

    // Otherwise INVALID
    default:
      printf("INVALID\n");
      return false;
    }
  }

  printf("INVALID\n");
  return false;
}