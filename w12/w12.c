/*********************************************
 * Id: kurt0200
 * 
 * Compare Sorts
 *  
 * To run, compile with "gcc w12.c -o w12"
 * Next, for example, running with 100 elements, "./w12 100"
 * As stated in instructions, it'll take a little while to run so be patient!
 * 
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

struct timeval start, stop;

// Selection Sort
void SS(int arr[], int n);

// QuickSort
void QuickSort(int arr[], int l, int r, int len);
int HoarePart(int arr[], int l, int r);
void swap(int *a, int *b);

// Insertion Sort
void InsertionSort(int A[], int n);

int main(int argc, char *argv[]) {
   // storing times in below arrays
   // [0] = original time (ex. 10)
   // [1] = time * 10 (ex. 100)
   // [2] = time * 10 * 10 (ex. 1000)
   int ss[3]; 
   int is[3];
   int qs[3];
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      int len = atoi(argv[1]);
      int length[3] = {len, 
      len*10, len*10*10};
      int s1time;
      int s2time;
      int s3time;
      for (int i = 0; i < 3; i++) {
         srand(time(NULL));
         if (i != 0) {
            len = len * 10;
         }
         int *arr_ss = malloc(len * sizeof(int));
         int *arr_qs = malloc(len * sizeof(int));
         int *arr_is = malloc(len * sizeof(int));
         for (int j = 0; j < len; j++) {
            int newvalue = rand() % 10;
            arr_ss[j] = newvalue;
            arr_qs[j] = newvalue;
            arr_is[j] = newvalue;
         }
         // start timer here
         gettimeofday(&start, NULL);
         SS(arr_ss, len);
         gettimeofday(&stop, NULL);
         s1time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
         ss[i] = s1time;
         // end timer here
         
         // start timer here
         gettimeofday(&start, NULL);
         QuickSort(arr_qs, 0, len-1, len);
         gettimeofday(&stop, NULL);
         s2time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
         qs[i] = s2time;
         // end timer here

         // start timer here
         gettimeofday(&start, NULL);
         InsertionSort(arr_is, len);
         gettimeofday(&stop, NULL);
         s3time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
         is[i] = s3time;

         // end timer here 
         //printf("Time #%d\n", i+1);
         //printf("Length: %d\n", len);
         free(arr_ss);
         free(arr_qs);
         free(arr_is);
      }
      //printf("Length: %d\n", len);

      printf("Selection Sort:\n");
      for (int i = 0; i < 3; i++) {
         printf("   Size %d: %d ms\n", length[i], ss[i]);
      }
      printf("QuickSort:\n");
      for (int i = 0; i < 3; i++) {
         printf("   Size %d: %d ms\n", length[i], qs[i]);
      }
      printf("Insertion Sort:\n");
      for (int i = 0; i < 3; i++) {
         printf("   Size %d: %d ms\n", length[i], is[i]);
      }
   
   }
   /*for (int i = 0; i < 3; i++) {
      printf("ss[%d]: %d\n", i, ss[i]);
      printf("qs[%d]: %d\n", i, qs[i]);
      printf("is[%d]: %d\n", i, is[i]);
   }*/
}

// Selection Sort implementation
void SS(int arr[], int n) {
   //printArray(arr, n);
   for (int i = 0; i < n-1; i++) {
      int min = i;
      for (int j = i+1; j < n; j++) {
         if (arr[j] < arr[min]) {
            min = j;
         }
      }
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
      //printArray(arr, n);
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

// Insertion Sort Algo implementation
void InsertionSort(int A[], int n) {
   //printArray(A, n, 0);
   for (int i = 1; i < n; i++) {
      int v = A[i];
      int j = i-1;
      while (j >= 0 && A[j] > v) {
         A[j+1] = A[j];
         j = j-1;
      }
      A[j+1] = v;
      //printArray(A, n, i);
   }

}
// Selection Sort:
//    Size 1000: 145 ms
//    Size 100000: 14518 ms
//    Size 1000000: 1456970 ms
// Quick Sort:
//    Size 10000: 0 ms
//    Size 100000: 9 ms
//    Size 1000000: 106 ms
// Insertion Sort:
//    Size 10000: 71 ms
//    Size 100000: 7269 ms
//    Size 1000000: 728481 ms
