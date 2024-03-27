/*********************************************
 * Id: kurt0200
 * 
 * Boyer Moore Algorithm Implementation
 *  
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

void printShiftTable(int table[]);
int* GoodSuffixTable(char* needle, int* gsuffix, int m);
void BMImp(char* needle, char* haystack);
int max(int a, int b);

int main(int argc, char *argv[]) {
   if (argc < 3) {
      printf("N/A\n");
   }
   else {
      char* needle = argv[1];
      char* haystack = argv[2];
      BMImp(needle, haystack);
   }
     
}
int max(int a, int b) {
   if (a > b) {
      return a;
   }
   else {
      return b;
   }
}

int* GoodSuffixTable(char* needle, int* gsuffix, int m) {
   for (int i = 0; i < m; i++) {
      gsuffix[i] = 0;
   }

   for (int i = m-1; i >= 0; i--) {
      int j = i - 1;
      while (j >= 0 && strncmp(&needle[i], &needle[j], m - i) != 0) {
         j--;
      }

      if ( strncmp(&needle[i], &needle[j], m - i) == 0 ) {
         gsuffix[m-i] = i-j;
         continue;
      }
      gsuffix[m-i] = m-1;
   }

   for(int i=1; i<m; i++){
      printf("%d %*s %d\n", i, m, &needle[m-i], gsuffix[i]);
   }

   return gsuffix;
}

void BMImp(char* needle, char* haystack) {
   int m = strlen(needle);
   int n = strlen(haystack);

   int bad_table[MAX_ALPHABET];
   int gsuffix_table[m];
   int i, k, d, d1, d2;

   int matches[512];
   int matchFound = 0;

   for (i = 0; i < MAX_ALPHABET; i++) {
       bad_table[i] = m;
   }

   for (i = 0; i < m - 1; i++) {
      bad_table[(int)needle[i]] = max(m - 1 - i, 1);
   }

   printShiftTable(bad_table);

   GoodSuffixTable(needle, gsuffix_table, m);

   i = m - 1;

   printf("%s\n", haystack);
   while (i < n) {
      k = 0;
      while (k < m && needle[m - 1 - k] == haystack[i - k]) {
         k++;
      }

      if (k == m) {
         printf("%*s", abs(i - m + 1), "");
         printf("%s---found\n", needle);
         matches[matchFound++] = i - m + 1;
         i++;
      }
      else {
         d1 = m - k;
         d2 = gsuffix_table[k];

         if (d1 > d2) {
            d = d1;
         }
         else {
            d = d2;
         }

         if (d == 0) {
            d = 1;
         }

         printf("%*s", abs(i - m + 1), "");
         if (d1 == 0 || d2 == 0) {
            printf("%s\n", needle);
         }
         else {
            printf("%s d1=%d d2=%d\n", needle, d1, d2);
         }

         i += d;
      }
   }

   printf("Matches found at locations: ");
   for (int tmp = 0; tmp < matchFound; tmp++) {
      printf("%d", matches[tmp]);
   }
   printf("\n");
}


void printShiftTable(int table[]) {
   int i, start;
   for (start = MIN_WRITEABLE; start < MAX_ALPHABET; start+=TABLE_ROW_LENGTH) {
      for (i = start; i < start+TABLE_ROW_LENGTH; i++) {
         printf("%c\t", i);
      }
      printf("\n");
      for (i = start; i < start+TABLE_ROW_LENGTH; i++) {
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}


