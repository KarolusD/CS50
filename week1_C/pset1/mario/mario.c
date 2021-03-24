#include <stdio.h>
#include <string.h>

int main(void)
{
  int height;

  do
  {
    printf("Pyramid height (1-8): ");
    scanf("%d", &height);
  } while (height > 8 || height < 1);

  for (int i = 1; i <= height; i++)
  {
    char pyramid_right[100];
    char pyramid_left[100];

    // print spaces
    for (int s = 1; s <= height - i; s++)
    {
      printf(" ");
    }

    // print hashes
    for (int h = 1; h <= 2 * i; h++)
    {
      // spaces inbetween left and right part of the pyramid
      if (h == i + 1)
      {
        printf("  ");
      }
      printf("#");
    }
    // new line
    printf("\n");
  }

  return 0;
}
