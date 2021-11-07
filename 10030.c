#include <stdio.h>
#include <stdlib.h>

int main ( ) {
     int n, m, input;
     unsigned *data;

     while ( scanf("%d%d", &n, &m) != EOF ) {
          data = (unsigned*) calloc(n*m, sizeof(unsigned));
          for ( int i = 0; i < n; i++ ) {
               for ( int j = 0; j < m; j++ ) {
                    scanf("%d", &input)
               }
          }



          free(data);
     }
     return 0;
}
