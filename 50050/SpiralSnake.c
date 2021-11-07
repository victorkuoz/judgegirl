#include <stdlib.h>
#include "SpiralSnake.h"

void SpiralSnake(int N, int *snake, int *result) {
     int *G = (int*) malloc(N*N*sizeof(int));
     G[ (N/2)*N + (N/2) ] = snake[0];

     int count = 0, r = (N/2), c = (N/2) - 1;
     for ( int k = 0; k < N; k += 2 ) {
          for ( int i = 1; i <= k; i++ ) {
               count++;
               G[r*N+c] = snake[count];
               if ( i != k )
                    r -= 1;
               else
                    c += 1;
          }
          for ( int i = 1; i <= k; i++ ) {
               count++;
               G[r*N+c] = snake[count];

               if ( i != k )
                    c += 1;
               else
                    r += 1;
          }
          for ( int i = 1; i <= k; i++ ) {
               count++;
               G[r*N+c] = snake[count];

               if ( i != k )
                    r += 1;
               else
                    c -= 1;
          }
          for ( int i = 1; i <= k; i++ ) {
               count++;
               G[r*N+c] = snake[count];

               c -= 1;
          }
     }

     for ( int r = 0; r < N; r++ )
          for ( int c = 0; c < N; c++ )
               result[r*N+c] = G[r*N+c];
     free(G);
     return;
}
