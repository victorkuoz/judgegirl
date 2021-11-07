#include <stdio.h>
#include <stdlib.h>
#define max 10
void derangement( int n, int seat_index, int *chosen, int *data, int *ans ) {
     if ( seat_index == n ) {
          for ( int i = 0; i < n; i++ )
               printf("%c", ans[i] + 'A');
          printf("\n");
          return;
     }
     for ( int i = 0; i < n; i++ )
          if ( data[ i*n+seat_index ] != 1 && !chosen[i] ) {
               ans[seat_index] = i;
               chosen[i] = 1;
               derangement( n, seat_index+1, chosen, data, ans );
               chosen[i] = 0;
          }
     return;
}

int main ( ) {
     int n, m, x, y, ans[max];
     while ( scanf("%d%d", &n, &m) != EOF ) {
          int *chosen = (int*) calloc( max, sizeof(int) );
          int *data = (int*) calloc( max*max, sizeof(int) );
          for ( int i = 0; i < m; i++ ) {
               scanf("%d%d", &x, &y);
               data[ (x-1)*n + (y-1) ] = 1;
          }
          derangement( n, 0, chosen, data, ans );
          free(chosen);
          free(data);
     }
     return 0;
}
