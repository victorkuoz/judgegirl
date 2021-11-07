#include <stdio.h>
#include <stdlib.h>
#define index ( m*r + c )

int main ( ) {
     int n, m;
     while ( scanf("%d%d", &n, &m) != EOF ) {
          int *obstacle = (int*) calloc ( n*m, sizeof(int) ), *path = (int*) calloc( n*m, sizeof(int) );

          for ( int r = 0; r < n; r++ )
               for ( int c = 0; c < m; c++ )
                    scanf("%d", &obstacle[index]);

          if ( obstacle[0] ) {
               printf("0\n");
               continue;
          }
          path[0] = 1;

          for ( int r = 0, valid = 0; r < n; r++, valid = 0 ) {
               for ( int c = 0; c < m; c++ ) {
                    if ( !obstacle[index] ) {
                         path[index] += ( r != 0 ) ? path[index-m] : 0;
                         path[index] += ( c != 0 ) ? path[index-1] : 0;
                         if ( path[index] > 9999 )
                              path[index] %= 10000;
                    }
                    valid += path[index];
               }
               if ( !valid )
                    break;
          }
          printf("%d\n", path[n*m-1]);
     }
     return 0;
}
