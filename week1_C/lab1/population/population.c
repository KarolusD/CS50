#include <stdio.h>

int main(void)
{
  int starting_population_size;
  int ending_population_size;

  do
  {
    printf("Enter starting population size: ");
    scanf("%d", &starting_population_size);

  } while (starting_population_size < 9);

  do
  {
    printf("Enter ending population size: ");
    scanf("%d", &ending_population_size);
  } while (ending_population_size < starting_population_size);

  int current_population_size = starting_population_size;
  int years = 0;

  while (current_population_size < ending_population_size)
  {
    int born_each_year = current_population_size / 3;
    int pass_each_year = current_population_size / 4;

    current_population_size += born_each_year - pass_each_year;
    years++;
  };

  printf("Years: %i", years);
  return 0;
}