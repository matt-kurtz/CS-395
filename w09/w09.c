/*********************************************
 * Id: kurt0200
 * 
 * Selection Sort
 *  
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int arr[], int n);
void SS(int arr[], int n);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("N/A\n");
   }
   else {
      int len = argc - 1;
      int arr[len];
      int index = 1;
      for (int i = 0; i < len; i++) {
         arr[i] = atoi(argv[index]);
         index++;
      }
      //printArray(arr, len);
      SS(arr, len);
      
   }


}
// prints array
void printArray(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

// Selection Sort implementation
void SS(int arr[], int n) {
   printArray(arr, n);
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
      printArray(arr, n);
   }

}
