#include <stdio.h>
#include "snake.h"

#define right_left 0
#define left_right 1

int snake_order ( int type, int *ptr, int *row, int *column ) {
     if ( type == left_right )
          for ( int c = 0; c < *column; c++ ) {
               if ( *ptr != (*row)*(*column) + c ) {
                    *column = c;
                    return 0;
               }
               ptr++;
          }
     else if ( type == right_left )
          for ( int c = (*column-1); c >= 0; c-- ) {
               if ( *ptr != (*row)*(*column) + c ) {
                    *column = c;
                    return 0;
               }
               ptr++;
          }
     return 1;
}

int snake(int *ptr, int *row, int *column) {
    *row = *column = 1;
    while ( *( ptr + *column - 1 ) == *( ptr + *column ) - 1 )
          (*column)++;
    ptr += (*column);

    while ( *ptr != 0 ) {
          if ( snake_order( (*row-1)%2, ptr, row, column ) == 0 )
               return 0;
          (*row)++;
          ptr += (*column);
    }
    return 1;
}
