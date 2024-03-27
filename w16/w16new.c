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
   } else {
      int len = (argc - 1) / 2;
      int arr[len][2];
      int i = 1;
      int j = 0;
      while (i < argc) {
         if (i % 2 != 0) {
            arr[j][0] = atoi(argv[i]);
         } else {
            arr[j][1] = atoi(argv[i]);
            j++;
         }
         i++;
      }
      ConvexHull(arr, len);
      printf("\n");
   }
   return 0;
}

int compare(const void *vp1, const void *vp2) {
   int *p1 = *(int (*)[2]) vp1;
   int *p2 = *(int (*)[2]) vp2;

   if (p1[0] != p2[0])
      return p1[0] - p2[0];
   return p1[1] - p2[1];
}

void ConvexHull(int points[][2], int len) {
   int hull[len][2]; // Array to store the points of the convex hull
   int hullLen = 0;  // Length of the convex hull

   qsort(points, len, sizeof(points[0]), compare);

   // Find the upper hull
   for (int i = 0; i < len; i++) {
      while (hullLen >= 2 && (hull[hullLen - 2][0] - hull[hullLen - 1][0]) * (points[i][1] - hull[hullLen - 1][1]) - (hull[hullLen - 2][1] - hull[hullLen - 1][1]) * (points[i][0] - hull[hullLen - 1][0]) >= 0) {
         hullLen--;
      }
      hull[hullLen][0] = points[i][0];
      hull[hullLen][1] = points[i][1];
      hullLen++;
   }

   // Find the lower hull
   for (int i = len - 2, t = hullLen + 1; i >= 0; i--) {
      while (hullLen >= t && (hull[hullLen - 2][0] - hull[hullLen - 1][0]) * (points[i][1] - hull[hullLen - 1][1]) - (hull[hullLen - 2][1] - hull[hullLen - 1][1]) * (points[i][0] - hull[hullLen - 1][0]) >= 0) {
         hullLen--;
      }
      hull[hullLen][0] = points[i][0];
      hull[hullLen][1] = points[i][1];
      hullLen++;
   }

   printf("The points in Convex Hull are:\n");
      for (int i = hullLen - 1; i >= 0; i--) {
         printf("(%i, %i) ", hull[i][0], hull[i][1]);
      }
      //printf("\n");
 
}


