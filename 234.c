#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define swap(a,b) { int temp = a; a = b; b = temp; }

int main ( ) {
     long long int a, b, c;
     int root[3];
     scanf("%lld%lld%lld", &a, &b,&c);

     if ( !a && !b && !c )
          root[0] = root[1] = root[2] = 0;
     else if ( !b && !c ) {
          root[0] = root[1] = 0;
          root[2] = (-a);
     }
     else if ( !c ) {
          root[0] = 0;
          root[1] = ( (-a) + sqrt( a*a - 4*b ) )/2;
          root[2] = ( (-a) - sqrt( a*a - 4*b ) )/2;
     }
     else {
          int count = 0;
          for ( long long int  i = -abs(c); i <= abs(c) && count < 3; i++ ) {
               if (  i != 0 && abs(c) % abs(i) == 0 && ( i*i*i + a*i*i + b*i + c ) == 0 ) {
                    root[count] = i;
                    count++;
               }
          }
          if ( count == 1)
               root[1] = root[2] = root[0];
          else if ( count == 2 )
               root[2] = (-a) - ( root[0] + root[1] );
     }

     for ( int i = 2; i > 0; i-- )
          for ( int j = 0; j < i; j++ )
               if ( root[j] < root[j+1] )
                    swap(root[j],root[j+1]);

     printf("%d %d %d", (-root[0]), (-root[1]), (-root[2]));
     return 0;
}
