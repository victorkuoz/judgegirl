#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100
//bool found;
int n, m, table[max][max], ans[max];

int independent_people ( int remain, int count, int *candidate ) {
     if ( count == m ) {
          for ( int i = 0; i < m; i++ )
               printf("%d%c", ans[i], ( i != m-1 ) ? ' ' : '\n');
          return 1;
     }
     if ( remain + count < m || !remain )
          return 0;

     int cur_idx = candidate[0], temp = 0;
     int *next = (int*) calloc(n, sizeof(int));
     for ( int i = 0; i < remain; i++ )
          if ( !table[cur_idx][candidate[i]] )
               next[temp++] = candidate[i];
     ans[count] = cur_idx;
     return independent_people( temp, count+1, next) || independent_people( remain-1, count, candidate+1 );
}

int main ( ) {
     while ( scanf("%d%d", &n, &m) != EOF ) {

          for ( int r = 0; r < n; r++ )
               for ( int c = 0; c < n; c++ )
                    scanf("%d", &table[r][c]);

          if ( m > n )
               printf("no solution\n");
          else {
               int *candidate = (int*) malloc(n*sizeof(int));
               for ( int i = 0; i < n; i++ )
                    candidate[i] = i;
               int found = independent_people( n, 0, candidate );
               if ( !found )
                    printf("no solution\n");
               free(candidate);
          }
     }
     return 0;
}
