#include <stdio.h>

int main () {
     int n, input, data[101];
     for ( int k = 1; k < 101; k++ )
          data[k] = (-1);

     scanf("%d", &n);
     for ( int k = 0; k < n; k++ ) {
          scanf("%d", &input);
          printf("%d", k);
          if ( data[input] == (-1) )
               data[input] = k;
          else {
               printf(" %d %d", data[input], input);
               data[input] = (-1);
          }
          if ( k != n )  printf("\n");
     }
     return 0;
}
