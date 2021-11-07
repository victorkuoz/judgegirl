#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

int x[3], y[3], ans = 0;
int outer_product ( int x1, int y1, int x2, int y2 ) {
     int pro = ( x1*y2 - y1*x2 );
     if ( pro > 0 )
          return 1;
     if ( pro < 0 )
          return (-1);
     return 0;
}
bool inside ( int cur_x, int cur_y ) {
     int pro[3];
     for ( int i = 0; i < 3; i++ )
          pro[i] = outer_product( ( x[i%3] - cur_x ), ( y[i%3] - cur_y ), ( x[(i+1)%3] - cur_x ), ( y[(i+1)%3] - cur_y ) );
     if ( ( pro[0] >= 0 && pro[1] >= 0 && pro[2] >= 0 ) || ( pro[0] <= 0 && pro[1] <= 0 && pro[2] <= 0 ) )
          return true;
     return false;
}

int main ( ) {
     for ( int i = 0; i < 3; i++ )
          scanf("%d%d", &x[i], &y[i]);
     int min_x = ( x[0] <= x[1] && x[0] <= x[2] ) ? x[0] : ( x[1] <= x[2] ) ? x[1] : x[2];
     int min_y = ( y[0] <= y[1] && y[0] <= y[2] ) ? y[0] : ( y[1] <= y[2] ) ? y[1] : y[2];
     int max_x = ( x[0] >= x[1] && x[0] >= x[2] ) ? x[0] : ( x[1] >= x[2] ) ? x[1] : x[2];
     int max_y = ( y[0] >= y[1] && y[0] >= y[2] ) ? y[0] : ( y[1] >= y[2] ) ? y[1] : y[2];

     for ( int i = min_x; i <= max_x; i++ )
          for ( int j = min_y; j <= max_y; j++ )
               if ( inside(i,j) && inside(i+1,j) && inside(i, j+1) && inside(i+1, j+1) )
                    ans++;
     printf("%d", ans);
     return 0 ;
}
