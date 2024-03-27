/*********************************************
 * Id: kurt0200
 * 
 * w08 Brute Force
 *  
 *********************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BruteForceStringMatch(char p[], char t[]);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      printf("Matches found at locations:");
      BruteForceStringMatch(argv[2], argv[1]);
   }

}
// Algorithm implementation
void BruteForceStringMatch(char T[], char P[]) {
   int n = strlen(T);
   int m = strlen(P);
   int matchFound = 0;
   for (int i = 0; i < (n-m+1); i++) {
      int j = 0;
      while (j < m && P[j] == T[i+j]) {
         j = j+1;
      }
      if (j == m) {
         printf(" %d", i);
         matchFound = 1;
      }
   }
   printf("\n");
   if (matchFound == 0) {       
      printf("No match found\n");
   }
   return;   
}
