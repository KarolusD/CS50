#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXINPUT 100

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char input[]);
char *get_string(char input[]);

int main(void)
{
  char *players[2];
  players[0] = get_string("Type word for player 1: ");
  players[1] = get_string("Type word for player 2: ");

  char players_scores[2];

  for (int i = 0; i < 2; i++)
  {
    players_scores[i] = compute_score(players[i]);
  }

  printf("%i\n", players_scores[0]);
  printf("%i\n", players_scores[1]);

  if (players_scores[0] > players_scores[1])
  {
    printf("Player 1 wins!");
  }
  else if (players_scores[0] < players_scores[1])
  {
    printf("Player 2 wins!");
  }
  else
  {
    printf("Tie!");
  }
}

int compute_score(char input[])
{
  int result = 0;
  for (int i = 0, n = strlen(input); i < n; i++)
  {
    char letter = toupper(input[i]);
    result += POINTS[letter - 65];
  }
  return result;
}

char *get_string(char input[])
{
  int length = strlen(input);
  char *user_input;
  user_input = malloc(MAXINPUT);

  for (int i = 0; i < length; i++)
  {
    printf("%c", input[i]);
  }
  scanf("%s", user_input);

  return user_input;
}