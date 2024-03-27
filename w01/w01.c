/*********************************************
 * Id: kurt0200
 * 
 * Finds the minimum distance between elements
 * in an array. 
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("%s\n", "No args!");
   }
   else {
      int arr[argc];
      for (int i = 1; i < argc; i++) {
         arr[i] = atoi(argv[i]);
         //printf("%d\n", arr[i]);
      }
      int dmin = abs(arr[0]-arr[1]); // assign dmin to be the first "distance" calculation
      for (int i = 0; i < argc; i++) {
         for (int j = 0; j < argc; j++) {
            if ((i != j) && (abs(arr[i]-arr[j]) < dmin)) {
               dmin = abs(arr[i]-arr[j]);
            }
         }
      }
      printf("%d\n", dmin); 
   }
}
