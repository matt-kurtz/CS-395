/*********************************************
 * Id: kurt0200
 * 
 * Insertion Sort Algorithm
 *  
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int A[], int n);
void printArray(int A[], int n, int slash);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      int len = argc-1;
      int arr[len];
      int ind = 1;
      for (int i = 0; i < len; i++) {
         arr[i] = atoi(argv[ind]);
         ind++;
      }
      InsertionSort(arr, len);
   }
}
// Insertion Sort Algo implementation
void InsertionSort(int A[], int n) {
   printArray(A, n, 0);
   for (int i = 1; i < n; i++) {
      int v = A[i];
      int j = i-1;
      while (j >= 0 && A[j] > v) {
         A[j+1] = A[j];
         j = j-1;
      }
      A[j+1] = v;
      printArray(A, n, i);
   }
}
// print the array
void printArray(int A[], int n, int slash) {
   for (int i = 0; i < n; i++) {
      if (i == slash) {
         printf("%d | ", A[i]);
      }
      else {
         printf("%d ", A[i]);
      }
   }
   printf("\n");
}
