/*
* kurt0200
*
* testing out why QuickSort is weird
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

struct timeval start, stop;

void QuickSort(int arr[], int l, int r, int len);
int HoarePart(int arr[], int l, int r);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
   int qs[3];
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      int len = atoi(argv[1]);
      int length[3] = {len,
      len*10, len*10*10};
      int s2time;
      for (int i = 0; i < 3; i++) {
         srand(time(NULL));
         if (i != 0) {
            len = len * 10;
         }
         int *arr_qs = malloc(len * sizeof(int));
         for (int j = 0; j < len; j++) {
            int newvalue = rand() % 10;
            arr_qs[j] = newvalue;
         }
         // start timer here
         gettimeofday(&start, NULL);
         QuickSort(arr_qs, 0, len-1, len);
         gettimeofday(&stop, NULL);
         s2time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
         qs[i] = s2time;
         // end timer here
         free(arr_qs);
      }
      printf("QuickSort:\n");
      for (int i = 0; i < 3; i++) {
         printf("   Size %d: %d ms\n", length[i], qs[i]);
      }
   }

}


// QuikSort algo implementation
void QuickSort(int arr[], int l, int r, int len) {
   int s;
   if (l < r) {
      s = HoarePart(arr, l, r);
      QuickSort(arr, l, s-1, len);
      QuickSort(arr, s+1, r, len);
      //printSubArray(arr, l, r, len);
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

