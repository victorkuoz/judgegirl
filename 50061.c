#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int n, donation[64], hate[64][64], max = INT_MIN;
void raise ( int index, int temp, int *candidate ) {
     int stop = 1;
     for ( int i = 0; i < n; i++ )
          if ( candidate[i] ) {
               stop = 0;
               break;
          }
     if ( stop || index == n ) {
          if ( temp > max )
               max = temp;
          return;
     }

     if ( candidate[index] ) {
          int *next = (int*) malloc(n*sizeof(int));
          for ( int i = 0; i < n; i++ ) {
               next[i] = candidate[i];
               if ( hate[index][i] )
                    next[i] = 0;
          }
          raise( index+1, temp+donation[index], next );
          free(next);
     }
     raise( index+1, temp, candidate );
     return;
}

int main ( ) {
     scanf("%d", &n);
     for ( int k = 0; k < n; k++ )
          scanf("%d", &donation[k]);
     for ( int i = 0; i < n; i++ )
          for ( int j = 0; j < n; j++ )
               scanf("%d", &hate[i][j]);
     int *candidate = (int*) calloc(n, sizeof(int));
     for ( int i = 0; i < n; i++ )
          candidate[i] = 1;
     raise( 0, 0, candidate );
     printf("%d", max);
     return 0;
}
