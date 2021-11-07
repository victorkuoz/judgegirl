#include <stdio.h>
#include "polynomial.h"

void init(Polynomial *poly, int coefficient[], int n){
     poly->power = (n-1);
     for ( int k = 0; k < n; k++ )
          poly->coefficient[k] = coefficient[k];
     return;
}
Polynomial add(Polynomial *poly1, Polynomial *poly2) {
     Polynomial poly;
     int n = ( poly1->power >= poly2->power ) ? ( poly1->power+1 ) : ( poly2->power+1 );

     poly.power = (n-1);
     for ( int k = 0; k < n; k++ )
          poly.coefficient[k] = 0;
     for ( int k = 0; k < n; k++ ) {
               poly.coefficient[k] += poly1->coefficient[k];
               poly.coefficient[k] += poly2->coefficient[k];
     }
     return poly;
}
Polynomial multiply(Polynomial *poly1, Polynomial *poly2){
     Polynomial poly;
     int n = (poly1->power+poly2->power+1);

     poly.power = (n-1);
     for ( int k = 0; k < n; k++ )
          poly.coefficient[k] = 0;
     for ( int i = 0; i <= poly1->power; i++ )
          for ( int j = 0; j <= poly2->power; j++ )
               poly.coefficient[i+j] += poly1->coefficient[i]*poly2->coefficient[j];
     return poly;
}
void print(Polynomial *poly) {
     for ( int k = poly->power; k >= 0; k-- ) {
          if ( poly->coefficient[k] != 0 ) {
               printf("%+d", poly->coefficient[k]);
               if ( k == 1 )
                    printf("x");
               else if ( k != 0 )
                    printf("x^%d", k);
          }
     }
     printf("\n");
     return;
}
