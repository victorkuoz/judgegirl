#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define idx (n*r+c)

int ans = INT_MAX;
void traveling ( int count, int r, int n, int *grid, int *chosen, int temp ) {
     if ( count == n ) {
          if ( temp + grid[r*n] < ans )
               ans = temp+grid[r*n];
          return;
     }
     if ( temp >= ans )
          return;
     for ( int c = 1; c < n; c++ )
          if ( !chosen[c] ) {
               chosen[c] = 1;
               traveling( count+1, c, n, grid, chosen, temp + grid[idx] );
               chosen[c] = 0;
          }
     return;
}

int main ( ) {
     int n;
     scanf("%d", &n);

     int *grid = calloc( n*n, sizeof(int) );
     int *chosen = (int*) calloc( n, sizeof(int) );
     for ( int r = 0; r < n; r++ )
          for ( int c = 0; c < n; c++ )
               scanf("%d", &grid[idx]);
     traveling( 1, 0, n, grid, chosen, 0 );
     printf("%d", ans);
     return 0;
}
