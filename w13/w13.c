/*********************************************
 * Id: kurt0200
 * 
 * Selection Sort
 *  
 *********************************************/
#include <stdio.h>
#include <stdlib.h>

int RussianP(int n, int m);

int main(int argc, char *argv[]) {
   if (argc < 3) {
      printf("N/A\n");
   }
   else {
      int len = 2;
      int arr[2];
      for (int i = 0; i < len; i++) {
         arr[i] = atoi(argv[i+1]);
         //printf("%d ", arr[i]);
      }
      //printf("\n");
      int sum = RussianP(arr[0], arr[1]);
      printf("%20s\n", "------");
      printf("%20d\n", sum);
      
   }
}

int RussianP(int n, int m) {
   if (n == 1) {
      printf("%6d %6d %6d\n", n, m, m);
      return m;
   }
   else if (n % 2 == 0) {
      printf("%6d %6d\n", n, m);
      return RussianP(n/2, m*2);
   }
   else {
      printf("%6d %6d %6d\n", n, m, m);
      return m + RussianP(n/2, m*2);
   }
}
