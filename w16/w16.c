/*********************************************
 * Id: kurt0200
 * 
 * Convex Hull Implementation
 *  
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

void ConvexHull(int points[][2], int len);
int compare(const void *vp1, const void *vp2);

int main(int argc, char *argv[]) {
   if (argc <= 1 || argc % 2 == 0) {
      printf("Must have at least one coordinate\n");
      return 0;
   }
   else {
      int len = (argc - 1) / 2;
      int arr[len][2];
      int i = 1;
      int j = 0;
      while (i < argc) {
         if (i % 2 != 0) {
            arr[j][0] = atoi(argv[i]);
            //printf("j: %i\ni:%i\narr[%i][0]: %i\n\n", j, i, j, arr[j][0]);
         }
         else {
            arr[j][1] = atoi(argv[i]);
            //printf("j: %i\ni:%i\narr[%i][1]: %i\n\n", j, i, j, arr[j][1]);
            j++;
         }
         i++;
      }
      ConvexHull(arr,len);
      printf("\n");
   }
}

int compare(const void *vp1, const void *vp2) {
    int *p1 = *(int (*)[2])vp1;
    int *p2 = *(int (*)[2])vp2;

    if (p1[0] != p2[0])
        return p1[0] - p2[0];
    return p1[1] - p2[1];
}


void ConvexHull(int points[][2], int len) {
   /*for (int i = 0; i < len; i++) {
      printf("(%i, %i) ", points[i][0], points[i][1]);
   }
   printf("\n");*/
   qsort(points, len, sizeof(points[0]), compare);
   for (int i = 0; i < len; i++) {
      while (len >= 2 && (points[i][0] - points[len - 2][0]) * (points[len - 1][1] - points[i][1]) - (points[len - 1][0] - points[i][0]) * (points[i][1] - points[len - 2][1]) <= 0) {
         len--;
      }
         points[len][0] = points[i][0];
         points[len++][1] = points[i][1];
   }
   for (int i = len - 2, t = len + 1; i >= 0; i--) {
      while (len >= t && (points[i][0] - points[len - 2][0]) * (points[len - 1][1] - points[i][1]) - (points[len - 1][0] - points[i][0]) * (points[i][1] - points[len - 2][1]) <= 0){
         len--;
      }
         points[len][0] = points[i][0];
         points[len++][1] = points[i][1];
   }
   printf("The points in the Convex Hull are:\n");
   for (int i = 0; i < len-1; i++) {
      printf("(%i, %i) ", points[i][0], points[i][1]);
   }
   printf("\n");
}

