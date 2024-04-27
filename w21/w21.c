#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// get all permuations up to n
void perm(int arr[], int start, int n);

// swap two values
void swap(int *a, int *b);

// main driver code
int main(int argc, char* argv[]) {
   if (argc < 2) {
      printf("Error: Not enough input\n");
      return -1;
   }

   int n = atoi(argv[1]);
   int arr[n];

   for (int i = 0; i < n; i++) {
      arr[i] = i+1;
   }

   perm(arr, 0, n);

   return 0;
}

// 123
// 132
// 213
// 232
// 312
// 321

// swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// get all permuations up to n
void perm(int arr[], int start, int n) {
   if (start == n - 1){
      for (int i = 0; i < n; i++) {
         printf("%d", arr[i]);
      }
      printf("\n");
      return;
   }

   for (int i = start; i < n; i++) {
      swap(&arr[start], &arr[i]);
      perm(arr, start + 1, n);
      swap(&arr[start], &arr[i]);
   }

   return;
}
