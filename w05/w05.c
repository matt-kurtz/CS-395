/*********************************************
 * Id: kurt0200
 * 
 * Tower of Hanoi w5
 *  
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TowerOfHanoi(int nDisks, char* fromPeg, char* toPeg, char* withPeg);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      int nDisks = atoi(argv[1]);
      char *fromPeg = "A";
      char *toPeg = "C";
      char *withPeg = "B";
      //printf("%d\n", nDisks);
      TowerOfHanoi(nDisks, fromPeg, toPeg, withPeg);

   }

}
// Tower of Hanoi implementation function
void TowerOfHanoi(int nDisks, char* fromPeg, char* toPeg, char* withPeg) {
   if (nDisks == 1) {
      printf("Move %s to %s\n", fromPeg, toPeg);
   }
   else if (nDisks > 1) {
      TowerOfHanoi(nDisks-1, fromPeg, withPeg, toPeg);
      printf("Move %s to %s\n", fromPeg, toPeg);
      TowerOfHanoi(nDisks-1, withPeg, toPeg, fromPeg);
   }
   return;

}
