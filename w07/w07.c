/*********************************************
 * Id: kurt0200
 * 
 * Tower of Hanoi w07
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
      char *start = "A";
      char *end = "C";
      char *with = "B";
      //printf("%d\n", nDisks);
      TowerOfHanoi(nDisks, start, end, with);

   }

}
// Tower of Hanoi implementation function
void TowerOfHanoi(int nDisks, char* fromPeg, char* toPeg, char* withPeg) {
   if (nDisks < 1) {
      return; // do nothing
   } 
   TowerOfHanoi(nDisks-1, fromPeg, toPeg, withPeg);
   printf("Move %s to %s\n", fromPeg, withPeg);
   if (nDisks > 1) {
      TowerOfHanoi(nDisks-2, toPeg, withPeg, fromPeg);
      printf("Move %s to %s\n", toPeg, fromPeg);
      TowerOfHanoi(nDisks-2, withPeg, fromPeg, toPeg);
   } 
   printf("Move %s to %s\n", withPeg, toPeg);
   TowerOfHanoi(nDisks-1, fromPeg, toPeg, withPeg);
}
