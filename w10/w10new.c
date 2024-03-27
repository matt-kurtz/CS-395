/*********************************************
 * Id: kurt0200
 * 
 * Selection Sort
 *  
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int arr[], int l, int r, int len);
int HoarePart(int arr[], int l, int r);
void swap(int *a, int *b);
void printSubArray(int arr[], int l, int r, int len);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      int len = argc-1;
      int arr[len];
      int index = 1;
      for (int i = 0; i < len; i++) {
         arr[i] = atoi(argv[index]);
         index++;
         //printf("%d ", arr[i]);
      }
      printf("\n");
      QuickSort(arr, 0, len-1, len);
      /*for (int i = 0; i < len; i++) {
         printf("%d ", arr[i]);
      }
      printf("\n");*/
      printSubArray(arr, 0, len, len);
   }
}

// QuikSort algo implementation
void QuickSort(int arr[], int l, int r, int len) {
   int s;
   if (l < r) {
      s = HoarePart(arr, l, r);
      QuickSort(arr, l, s-1, len);
      QuickSort(arr, s+1, r, len);
      printSubArray(arr, l, r, len);
   }

}
// Hoare's Partitioning Algo
int HoarePart(int arr[], int l, int r) {
   int p = arr[l];
   int i = l;
   int j = (r + 1);
   do {
      do {
         i++;
      } while (arr[i] < p);
      do {
         j--;
      } while (arr[j] > p);
      swap(&arr[i], &arr[j]);
   } while (i < j);
   swap(&arr[i], &arr[j]);
   swap(&arr[l], &arr[j]);
   return j;
}
// swaps two indices
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
// prints subarray
void printSubArray(int arr[], int l, int r, int len) {
   for (int i = 0; i < l; i++) {
      printf("%d ", arr[i]);
   }
   printf("[");
   for (int i = l; i <= r && i < len; i++) {
      if (i == l) {
         printf("%d", arr[i]);
      }
      else {
         printf(" %d", arr[i]);
      }
   }
   printf("] ");
   for (int i = r + 1; i < len; i++) {
      printf(" %d", arr[i]);
   }
   printf(" \n");
   return;
}
