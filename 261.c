#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool solved = false;

typedef struct num {
     int **arr, len;
} Num;

bool check ( Num *nums ) {
     unsigned long long n[3] = {0};
     for ( int i = 0; i < 3; i++ )
          for ( int j = (nums[i].len-1), k = 1; j >= 0; j--, k*=10 )
               n[i] += ( (*nums[i].arr[j])*k );
     return (n[0]*n[1] == n[2]);
}

void puzzle_equation ( int cur, Num *nums, int *alphabet, bool *exist ) {
     if (solved);
     else if ( cur > 25 )
          solved = check(nums);
     else if ( !exist[cur] )
          puzzle_equation((cur+1), nums, alphabet, exist);
     else {
          for ( int i = 1; i <= 9 && (!solved); i++ ) {
               alphabet[cur] = i;
               puzzle_equation((cur+1), nums, alphabet, exist);
          }
     }
     return;
}

int main (void) {
     int *alphabet = (int*) calloc(26, sizeof(int)), digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
     bool *exist = (bool*) calloc(26, sizeof(bool));
     char *input = (char*) calloc(10, sizeof(char));
     Num *nums = (Num*) calloc(3, sizeof(Num));
     for ( int i = 0; i < 3; i++ ) {
          scanf("%s", input);
          nums[i].len = strlen(input);
          nums[i].arr = (int**) calloc(nums[i].len, sizeof(int*));

          for ( int j = 0; j < nums[i].len; j++ ) {
               char cur_c = input[j];
               if ( '0' <= cur_c && cur_c <= '9' ) 
                    nums[i].arr[j] = &(digits[(cur_c-'0')]);
               else {
                    exist[(cur_c-'A')] = true;
                    nums[i].arr[j] = &(alphabet[(cur_c-'A')]);
               }
          }
     }

     puzzle_equation(0, nums, alphabet, exist);

     for ( int i = 0; i < 3; i++ ) {
          for ( int j = 0; j < nums[i].len; j++ )
               printf("%d", *(nums[i].arr[j]));
          printf("%s", (i==0) ? " x " : (i==1) ? " = " : "\n");
     }
     return 0;
}
