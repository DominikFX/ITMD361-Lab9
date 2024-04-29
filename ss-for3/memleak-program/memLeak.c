#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <test_case>\n", argv[0]);
    return -1;
  }

  printf("Running Test Case %s!\n", argv[1]);
  test(atoi(argv[1]));

  return 0;
}

struct myStruct {
  int *myList;
};

int test(int num) {
  struct myStruct *s;
  int i, j;

  switch (num) {
  case 1:
  case 2:
    // malloc 8 bytes and optionally free
    char *string = malloc(8 * sizeof(char));
    if (num == 2)
      free(string);
    break;
  case 3:
  case 4:
    // malloc int pointer and optionally free
    int *myNums = malloc(5 * sizeof(int));
    if (num == 4)
      free(myNums);
    break;
  case 5:
  case 6:
    // make a struct with a list and optionally free
    s = malloc(sizeof(*s));
    s->myList = malloc(5 * sizeof(int));
    if (num == 6)
      free(s->myList);
    free(s);
    break;
  case 7:
  case 8:
  case 9:
  case 10:
    // make a struct with 3 sets of numbers and optionally free
    s = malloc(sizeof(*s) * 3);
    for (i = 0; i < 3; i++)
    {
      s->myList = malloc(5 * sizeof(int));
      for (j = 0; j < 5; j++)
      {
        s->myList[j] = j * i;
      }
      s++;
    }
    s--;
    if (num >= 8)
      free(s->myList);
    s--;
    if (num >= 9)
      free(s->myList);
    s--;
    if (num == 10)
      free(s);
    break;
  default:
    // Handle other cases or return an error code
    break;
  }

  return 0;
}
