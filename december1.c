#include <stdio.h>
#include <stdlib.h>


/*
 * ACT's Advent of Code Attempt
 * December 1st, 2022
 * Completed December 1st, 2022, 19:49 PM PST
 */

// Stolen from TutorialsPoint for the sake of effeciency.
int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {

  FILE *FileStream = fopen("input.txt", "r");

  // This will be used as a buffer to read the current line.
  char CurrentReadAmount[16];

  // This will be used as a storage of the highest total calorie on a single
  // elf. By the end of the program, this will be the answer.
  int CurrentHighestElf[3] = {0, 0, 0};

  // This is the current number to be used.
  int CurrentCountedElf = 0;

  for (int i = 0; i < 2254; i++) {

    fgets(CurrentReadAmount, 16, FileStream);

    CurrentCountedElf = CurrentCountedElf + atoi(CurrentReadAmount);

    // This signifies that there's a "new elf" on the block, as the kids would
    // say (You can tell that I'm going insane because of that horrid attempt at
    // a joke in my code.) As such, the CurrentCountedElf is compared to the
    // CurrentHighestElf - if the Current Counted Elf is greater, then we have a
    // new Current Highest Elf! If not, we only reset CurrentCountedElf to zero.
    if (CurrentReadAmount[0] == '\n') {

      qsort(CurrentHighestElf, 3, sizeof(int), cmpfunc);

      for (int j = 0; j < 3; j++) {
        if (CurrentCountedElf > CurrentHighestElf[j]) {
          CurrentHighestElf[j] = CurrentCountedElf;
          break;
        }
      }

      CurrentCountedElf = 0;
    }
  }

  for (int i = 0; i < 3; i++)
    printf("\n Elf #%d: %d", i, CurrentHighestElf[i]);

  printf("\nTotal: %d",
         CurrentHighestElf[0] + CurrentHighestElf[1] + CurrentHighestElf[2]);
  return 0;
}
