#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main ( ) {
     int n, m, t, s, output = 0;
     scanf("%d%d", &n, &m);
     int *c = (int*) calloc(n, sizeof(int));

     int index, min;
     for ( int k = 0; k < m; k++ ) {
          min = INT_MAX;
          scanf("%d%d", &t, &s);
          for ( int i = 0; i < n; i++ ) {
               if ( c[i] <= t ) {
                    c[i] = (t+s);
                    index = (-1);
                    break;
               }
               else if ( c[i] < min ) {
                    min = c[i];
                    index = i;
               }
          }

          if ( index != (-1) ) {
               output += ( c[index] - t );
               c[index] += s;
          }
     }
     printf("%d", output);
     return 0;
}
