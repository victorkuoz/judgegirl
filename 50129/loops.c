#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void loops(int N, int *A, int *B[], int ans[4]) {
     int *visited = (int*) calloc(N,sizeof(int)), flag = N;
     ans[0] = ans[2] = INT_MIN;
     ans[1] = ans[3] = INT_MAX;

     while ( flag ) {
          int cur_idx = (-1), start_idx = (-1);
          int len = 0, max = INT_MIN, min = INT_MAX;

          for ( int i = 0; i < N && cur_idx < 0 ; i++ )
               if ( !visited[i] )
                    cur_idx = start_idx = i;

          while ( 1 ) {
               if ( A[cur_idx] > max )
                    max = A[cur_idx];
               if ( A[cur_idx] < min )
                    min = A[cur_idx];
               visited[cur_idx] = 1;
               flag--;
               len++;
               cur_idx = ( B[cur_idx] - A );

               if ( cur_idx == start_idx ) {
                    if ( len > ans[0] ) {
                         ans[0] = len;
                         ans[2] = max;
                    }
                    else if ( len == ans[0] && max > ans[2] )
                         ans[2] = max;
                    if ( len < ans[1] ) {
                         ans[1] = len;
                         ans[3] = min;
                    }
                    else if ( len == ans[1] && min < ans[3] )
                         ans[3] = min;
                    break;
               }
          }
     }

     return;
}
