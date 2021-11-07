#include <stdio.h>
#include <stdlib.h>

int main ( ) {
     int n, k, m, d, sum = 0;
     scanf("%d%d%d%d", &n, &k, &m, &d);

     int P[k][k], M[n][n];
     for ( int r = 0; r < n; r++ )
          for ( int c = 0; c < n; c++ )
               scanf("%d", &M[r][c]);
     for ( int r = 0; r < k; r++ )
          for ( int c = 0; c < k; c++ ) {
               scanf("%d", &P[r][c]);
               sum += P[r][c];
          }

     int R = (-1), C = (-1);
     for ( int r = 0; r <= (n-k); r++ ) {
          for (int c = 0; c <= (n-k); c++ ) {
               int temp_m = 0, temp_sum = 0;
               for ( int i = 0; i < k; i++ ) {
                    for ( int j = 0; j < k; j++ ) {
                         temp_sum += M[r+i][c+j];
                         if ( P[i][j] != M[r+i][c+j] )
                              temp_m++;
                    }
               }
               if ( temp_m <= m && abs( temp_sum - sum ) <= d ) {
                    R = r;    C = c;
               }
          }
     }
     printf("%d %d", R, C);
     return 0;
}
