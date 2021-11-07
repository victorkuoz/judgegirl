#include <stdio.h>
#include "bingo.h"
int bingo(const unsigned long long int *board, int *rowColumn) {
     unsigned long long int row = 1;
     for ( int i = 0; i < 7; i++ ) {
          row <<= 1;
          row++;
     }
     row <<= 56;

     for ( int r = 0; r < 8; r++ ) {
          if ( ( (*board) & row ) == row ) {
               *rowColumn = r;
               return 1;
          }
          row >>= 8;
     }

     unsigned long long int column = 128;
     for ( int i = 0; i < 7; i++ ) {
          column <<= 8;
          column += 128;
     }
     for ( int c = 0; c < 8; c++ ) {
          if ( ( (*board) & column ) == column ) {
               *rowColumn = c;
               return 2;
          }
          column >>= 1;
     }

     unsigned long long int diagonal = 128, flag = 128;
     for ( int i = 1; i < 8; i++ ) {
          diagonal <<= 8;
          diagonal += ( flag >> i );
     }
     if ( ( (*board) & diagonal ) == diagonal ) {
          *rowColumn = 0;
          return 3;
     }

     diagonal = flag = 1;
     for ( int i = 1; i < 8; i++ ) {
          diagonal <<= 8;
          diagonal += ( flag << i );
     }
     if ( ( (*board) & diagonal ) == diagonal ) {
          *rowColumn = 1;
          return 3;
     }
     return 0;
}
