#include <stdio.h>
#include <stdlib.h>

int main ( ) {
     int n, m, ans;
     scanf("%d", &n);
     int *data = (int*) calloc(n,sizeof(int));

     for ( int i = 0; i < n; i++ ) {
          scanf("%d", &m);
          data[m]++;
          if ( data[m] > 1) {
               printf("%d", m);
               return 0;
          }
     }
}
