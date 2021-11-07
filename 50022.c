#include <stdio.h>
#include <stdbool.h>
#define index (r*m+c)

bool found;
int n, m, ans[32], chosen[32], R[32], C[32], r[32], c[32];

void fill_in ( int count ) {
     if (found)
          return;

     if ( count != 0 && count%m == 0 && r[(count-1)/m] != R[(count-1)/m] )
          return;
     if ( count == (n*m) ) {
          for ( int k = 0; k < m; k++ )
               if ( c[k] != C[k] )
                    return;
          for ( int r = 0; r < n; r++ )
               for ( int c = 0; c < m; c++ )
                    printf("%d%c", ans[index], ( c!=(m-1) ) ? ' ' : '\n');
          found = true;
          return;
     }

     for ( int k = 1; k <= (n*m); k++ ) {
          if ( chosen[k] != 1 && r[count/m] + k <= R[count/m] && c[count%m] + k <= C[count%m] ) {
               ans[count] = k;
               chosen[k] = 1;

               r[count/m] += k;
               c[count%m] += k;

               fill_in( count+1 );
               r[count/m] -= k;
               c[count%m] -= k;
               chosen[k] = 0;
          }
     }
     return;
}

int main ( ) {
     int sum1, sum2;
     while ( scanf("%d%d", &n, &m) != EOF ) {
          sum1 = sum2 = (1+n*m)*(n*m)/2;
          for ( int k = 0; k < n; k++ ) {
               scanf("%d", &R[k]);
               sum1 -= R[k];
               r[k] = 0;
          }
          for ( int k = 0; k < m; k++ ) {
               scanf("%d", &C[k]);
               sum2 -= C[k];
               c[k] = 0;
          }

          if ( sum1 != 0 || sum2 != 0) {
               printf("no solution\n");
               continue;
          }

          found = false;
          for ( int k = 1; k <= n*m; k++ )
               chosen[k] = 0;
          fill_in( 0 );
          if (!found)
               printf("no solution\n");
     }
     return 0;
}

