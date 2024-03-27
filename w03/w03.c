/*********************************************
 * Id: kurt0200
 * 
 * Brute force way of finding n^2
 *  
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

int expo(int n);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("No args!!\n");
   }
   else {
      int ans = expo(atoi(argv[1]));
      printf("%d\n", ans);
   }
}
// recursive function needed for assignment
int expo(int n) {
   if (n < 1) {
      return 1;
   }
   else {
      return expo(n-1) + expo(n-1);
   }

}
