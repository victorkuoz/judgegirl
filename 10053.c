#include <stdio.h>
#define max 4

int n, grid[max][max], chosen[max][max], ans[3];
void R_C_game ( int player, int prev, int sum1, int sum2 ) {
     int flag = 0;
     if ( player == 1 ) {
          for ( int c = 0; c < n; c++ ) {
               if ( chosen[prev][c] )  continue;
               flag = 1;
               chosen[prev][c] = 1;
               R_C_game( 2, c, sum1 + grid[prev][c], sum2 );
               chosen[prev][c] = 0;
          }
     }
     else {
          for ( int r = 0; r < n; r++ ) {
               if ( chosen[r][prev] ) continue;
                    flag = 1;
                    chosen[r][prev] = 1;
                    R_C_game( 1, r, sum1, sum2 + grid[r][prev] );
                    chosen[r][prev] = 0;
          }
     }
     if ( !flag ) {
          if ( sum1 > sum2 )  ans[0]++;
          else if ( sum1 < sum2 )  ans[1]++;
          else ans[2]++;
     }
     return;
}

int main ( ) {
     while ( scanf("%d", &n) != EOF ) {
          for ( int i = 0; i < n; i++ )
               for ( int j = 0; j < n; j++ ) {
                    scanf("%d", &grid[i][j]);
                    chosen[i][j] = 0;
               }
          ans[0] = ans[1] = ans[2] = 0;
          R_C_game( 1, 0, 0, 0 );
          printf("%d %d %d\n", ans[0], ans[1], ans[2]);
     }
     return 0;
}
