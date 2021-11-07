#include <stdio.h>
#include <stdlib.h>

int main ( ) {
     int N, input;
     scanf("%d", &N);

     int index = 0, prev, cur;
     for ( int i = 0; i < N; i++ ) {
          scanf("%d", &input);
          if ( i == 0 )
               prev = ( input >> 31 ) & 1;
          for ( int j = 31; j >= 0; j-- ) {
               cur = ( input >> j ) & 1;
               if ( cur != prev ) {
                    printf("\n");
                    for ( int k = 0; k < (index%40); k++ )
                         printf(" ");
                    prev = cur;
               }
               printf("%d", cur);
               index++;
          }
     }
     return 0;
}
