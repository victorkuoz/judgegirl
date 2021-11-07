#include <stdio.h>
#include "blockmover.h"
void printBlock(unsigned long long int *block) {
     for ( int i = 0; i < 64; i++ ) {
          printf("%d", ( *block >> i ) & 1 );
          if ( i%8 == 7 )     printf("\n");
     }
     return;
}
void initialize(unsigned long long int *block, int row, int column, int size) {
     (*block) = 0;
     if ( ( row + size > 8 ) || ( column + size > 8 ) )     return;
     unsigned long long int flag = 1;

     for ( int i = 1; i < size; i++ ) {
          flag <<= 1;
          flag += 1;
     }

     flag <<= column;
     //printBlock(&flag);
     *block += flag;
     for ( int i = 1; i < size; i++ ) {
          (*block) <<= 8;
          (*block) += flag;
     }

     (*block) <<= 8*row;
     //printBlock(block);
     return;
}
int moveLeft(unsigned long long int *block) {
     if ( ( *block & 72340172838076673 )  != 0 )     return 0;
     *block = ( (*block) >> 1 );
     return 1;
}
int moveRight(unsigned long long int *block) {
     unsigned long long int right_limit = 0, flag = 1;
     for ( int j = 7; j < 64; j += 8 )
          right_limit += ( flag << j );
     if ( ( *block & right_limit ) != 0 )     return 0;
     *block = ( (*block) << 1 );
     return 1;
}
int moveUp(unsigned long long int *block){
     if ( ( *block & 255 ) != 0 )     return 0;
     *block = ( (*block) >> 8 );
     return 1;
}
int moveDown(unsigned long long int *block){
     unsigned long long int down_limit = 0, flag = 1;
     for ( int i = 56; i < 64; i++ )
          down_limit += ( flag << i );
     if ( ( *block & down_limit ) != 0 )     return 0;
     *block = ( (*block) << 8 );
     return 1;
}
