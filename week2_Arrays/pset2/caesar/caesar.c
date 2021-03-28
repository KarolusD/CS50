#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXINPUT 100

int main(int argc, char *argv[])
{
  // User pass a key - integer,
  // if user pass more than 1 number or 0 printf Usage: ./caesar key and exit a program
  // if user pass correct key printf Success
  // encrypt message
  // return encrypted message

  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    exit(1);
  }

  printf("Success\n");

  int key;
  sscanf(argv[1], "%d", &key); // changing chars array into int

  char message[MAXINPUT];
  printf("plaintext: ");
  scanf("%[^\n]s", message);

  printf("ciphertext: ");

  for (int i = 0, n = strlen(message); i < n; i++)
  {
    char letter = message[i];

    // handle small letters
    if (letter >= 97 && letter <= 122)
    {
      printf("%c", ((letter - 97 + key + 26) % 26) + 97);
    }
    // handle big letters
    else if (letter >= 65 && letter <= 90)
    {
      printf("%c", ((letter - 65 + key + 26) % 26) + 65);
    }
    else
    {
      printf("%c", letter);
    }
  }
  printf("\n");

  return 0;
}