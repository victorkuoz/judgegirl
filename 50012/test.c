#include <stdio.h>
#define N 8

unsigned long long left_limit = 0, right_limit = 0, up_limit = 0, down_limit = 0, flag = 1;
int main ( ) {
     for ( int j = 0; j < N*N; j += N )
          left_limit += ( flag << j );
     for ( int j = (N-1); j < N*N; j += N )
          right_limit += ( flag << j );
     for ( int i = 0; i < N; i++ )
          up_limit += ( flag << i );
     for ( int i = 56; i < N*N; i++ )
               down_limit += ( flag << i );

     printf("%llu\n%llu\n%llu\n%llu\n", left_limit, right_limit, up_limit, down_limit);
     return 0;
}
