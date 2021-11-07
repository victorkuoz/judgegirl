#include <stdio.h>

int main ( ) {
     int n, m, x, y;
     while ( scanf("%d%d%d%d", &n, &m, &x, &y) != EOF ) {
          for ( int k = 0; k <= (n*m); k++ ) {
               printf("%d %d\n", x, y);
               if ( x == 0 && y == 0 )       x++;
               else if ( x == 0 )       y--;
               else if ( y%2 == 0 && x == (n-1) )      y++;
               else if ( y%2 == 0 )     x++;
               else if ( y%2 == 1 && x == 1 && y != (m-1) )      y++;
               else      x--;
          }
     }
     return 0;
}
