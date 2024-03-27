/*********************************************
 * Id: kurt0200
 * 
 * Tower of Hanoi w06
 *  
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TowerOfHanoi(int nDisks, char* start, char* end);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      int nDisks = atoi(argv[1]);
      char *start = "A";
      char *end = "C";
      //printf("%d\n", nDisks);
      TowerOfHanoi(nDisks, start, end);

   }

}
// Tower of Hanoi implementation function
void TowerOfHanoi(int nDisks, char* start, char* end) {
   char* middle = "B";
   if (nDisks == 1) {
      printf("Move %s to %s\n", start, middle);
      printf("Move %s to %s\n", middle, end);
   }
   else {
      TowerOfHanoi(nDisks-1, start, end);
      printf("Move %s to %s\n", start, middle);
      TowerOfHanoi(nDisks-1, end, start);
      printf("Move %s to %s\n", middle, end);
      TowerOfHanoi(nDisks-1, start, end);

   }
   return;

}
