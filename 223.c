#include <stdio.h>

int main ( ) {
     int l, m;
     scanf("%d%d", &l, &m);

     int plaza[l][l];
     for ( int i = 0 ; i < l; i++ )
          for ( int j = 0; j < l; j++ ) {
               if ( i < (l-m) && j >= (l-m) )
                    plaza[i][j] = 1;
               else
                    plaza[i][j] = 0;
          }

     /*for ( int i = 0; i < l; i++ ) {
          for ( int j = 0; j < l; j++ )
               printf("%d ", plaza[i][j]);
          printf("\n");
     }*/



     return 0;
}
