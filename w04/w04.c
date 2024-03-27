/*********************************************
 * Id: kurt0200
 * 
 * Array of floats Printed
 *  
 *********************************************/

#include <stdio.h>
#include <stdlib.h>


void printMatrix(int n, float A[n][n+1]);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("N/A\n");
   } 
   else {
      int n = atoi(argv[1]);
      float A[n][n+1];
      int ind = 2;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n+1; j++) {
            A[i][j] = atoi(argv[ind++]);
            //printf("%f ", A[i][j]);
         }
         //printf("\n");
      }
      printMatrix(n, A);
      for (int i = 0; i < n-2; i++) {
         for (int j = i+1; j < n-1; j++) {
            float tempji = A[j][i];
            for (int k = i; k < n; k++) {
               A[j][k] = A[j][k] - (A[i][k] * tempji / A[i][i]);
            }
         }
         printMatrix(n, A);
      }
   }

}
// prints matrix 
void printMatrix(int n, float A[n][n+1]) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n+1; j++) {
         printf("%.2f ", A[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}
