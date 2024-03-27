/*********************************************
 * Id: kurt0200
 * 
 * Selection Sort
 *  
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

void printShiftTable(int table[]);
int* ShiftTable(char needle[], int m);
int HorspoolMatch(char needle[], int m, char haystack[], int n);

int main(int argc, char *argv[]) {
   if (argc < 3) {
      printf("N/A\n");
   }
   else {
      int len_needle = strlen(argv[1]);
      int len_haystack = strlen(argv[2]);
      //printf("%s %s\n", argv[1], argv[2]);
      HorspoolMatch(argv[1], len_needle, argv[2], len_haystack);
     
      // Free the array in Horspool Match
   }
}

int* ShiftTable(char needle[], int m) {
   int *Table = malloc(MAX_ALPHABET * sizeof(int));
   for (int i = 0; i < MAX_ALPHABET; i++) {
      Table[i] = m;
   }
   for (int j = 0; j < m-1; j++) {
      Table[(unsigned char)needle[j]] = m-1-j;
   }
   printShiftTable(Table);
   return Table;
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

int HorspoolMatch(char needle[], int m, char haystack[], int n) {
   int matchNum = 0;
   int matches[100];
   int *Table = ShiftTable(needle, m);
   printf("%s\n", haystack);
   int i = m-1;
   while (i <= n-1) {
      int k = 0;
      while (k <= m-1 && needle[m-1-k] == haystack[i-k]) {
         k = k + 1;
      }
      if (k == m) {
         printf("%*s%s---found\n", i-m+1, "", needle);
         matches[matchNum] = (i-m+1);
         matchNum++;
         //return (i - m + 1);
      }
      else {
         printf("%*s%s\n", i-m+1, "", needle);
      }
      i = i + Table[(unsigned char)haystack[i]];
   }
   printf("Matches found at locations:");
   for (int i = 0; i < matchNum; i++) {
      printf(" %d", matches[i]);
   }
   printf("\n");
   free(Table);
   return -1;
}
