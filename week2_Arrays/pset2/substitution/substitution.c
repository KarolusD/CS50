#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXINPUT 100
#define ALPHABET_LENGTH 26

bool keycheck(char *key);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage ./subsitution key");
    return 1;
  }
  else if (strlen(argv[1]) != 26)
  {
    printf("Key must contain 26 characters.");
    return 1;
  }
  else if (keycheck(argv[1]) == false)
  {
    printf("Key must contain different letters.");
    return 1;
  }

  char message[MAXINPUT];
  printf("plaintext: ");
  scanf("%[^\n]s", message);

  char *key = argv[1];

  printf("ciphertext: ");

  for (int i = 0, n = strlen(message); i < n; i++)
  {
    bool is_letter = false;
    bool is_big = false;

    if ((message[i] >= 65 && message[i] <= 90) || message[i] >= 96 && message[i] <= 122)
    {
      is_letter = true;
    }

    if (message[i] >= 65 && message[i] <= 90)
    {
      is_big = true;
    }

    if (is_big && is_letter)
    {
      message[i] = toupper(key[message[i] - 65]);
    }
    else if (is_letter)
    {
      message[i] = tolower(key[message[i] - 97]);
    }

    printf("%c", message[i]);
  }
  printf("\n");

  return 0;
}

bool keycheck(char *key)
{
  int char_set[128] = {0};

  for (int i = 0, n = strlen(key); i < n; i++)
  {
    // handle invalid chars
    if (key[i] < 65 || (key[i] > 90 && key[i] < 97) || key[i] > 122)
    {
      return false;
    }

    // handle chars duplication
    if (char_set[(int)key[i]] == 1)
    {
      return false;
    }
    else
    {
      char_set[(int)key[i]] = 1;
    }
  }
  return true;
}