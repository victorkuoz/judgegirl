#include <stdio.h>
#include <string.h>
#include "hangman.h"


int main ( ) {
     int N, G, flag;
     scanf("%d", &N);

     Hangman *ptr;
     char ans[101], gue[201];
     for ( int i = 0; i < N; i++ ) {
          scanf("%s%d%s", &ans, &G, &gue);
          ptr = newGame( ans, G );

          int len = strlen(gue);
          for ( int i = 0; i < len; i++ ) {
               flag = guess( ptr, gue[i] );
               printf("%d ", flag);
               printStatus(ptr);
               if ( flag == (-1) ) {
                    printf("You Lose\n");
                    break;
               }
               if ( solved(ptr) ) {
                    printf("You Win\n");
                    break;
               }
               if ( i == len - 1 )
                    printf("You Quit\n");
          }
     }

     return 0;
}
