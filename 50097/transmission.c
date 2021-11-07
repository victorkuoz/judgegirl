#include <stdio.h>
#include "transmission.h"

 long long int temp_belt[1048576];
void print_binary ( unsigned long long  input ) {
     int data[64] = {0};
     for ( int k = 63; k >= 0; k-- ) {
          if ( input == 0 )
               break;
          data[k] = (input & 1);
          input >>= 1;
     }
     for ( int k = 0; k < 64; k++ )
          printf("%d ", data[k]);
     printf("\n");
     return;
}

void transmission(long long int belt[],int N,int T) {
     T %= (64*N);
     if ( !T )
          return;

     int jump = (T/64);
     for ( int k = 0; k < N; k++ )
          temp_belt[k] = belt[(k+jump)%N];
     for ( int k = 0; k < N; k++ )
          belt[k] = temp_belt[k];


     T %= 64;
     if ( !T )
          return;

     unsigned long long add, flag = 0;
     for ( int k = 0; k < 63; k++ ) {
          if ( k < T )
               flag++;
          flag <<= 1;
     }

     unsigned long long temp = (unsigned long long)temp_belt[0];
     for ( int k = 0; k < N; k++ ) {
          unsigned long long cur = (unsigned long long)temp_belt[k], next;
          cur <<= T;
          if ( k == N-1 )
               next = temp;
          else
               next = (unsigned long long)belt[k+1];

          add = ( ( next & flag ) >> (64-T) );
          belt[k] = (long long int)(cur+add);
     }
     return;
}
