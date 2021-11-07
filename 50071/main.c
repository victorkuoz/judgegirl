#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "attraction.h"

int n, m;
int calculate_layer ( int x, int y ) {
     int layer_x = ( x <= abs(x-(n-1)) ) ? x : abs(x-(n-1));
     int layer_y = ( y <= abs(y-(n-1)) ) ? y : abs(y-(n-1));
     return ( layer_x <= layer_y ) ? layer_x : layer_y;
}
int calculate_type ( int x, int y, int layer ) {
     if ( y == layer )
          return 1; // down
     if ( (n-1) - y == layer )
          return 3; // up
     if ( (n-1) - x == layer )
          return 2; // right
     return 4; // left
}
int spots_cmp ( const void *ptr_1, const void *ptr_2 ) {
     Attraction *spot_1 = (Attraction*)ptr_1;
     Attraction *spot_2 = (Attraction*)ptr_2;

     int layer_1 = calculate_layer( spot_1->x, spot_1->y ), layer_2 = calculate_layer( spot_2->x, spot_2->y );
     if ( layer_1 != layer_2 )
          return ( layer_1 - layer_2 );

     int type_1 = calculate_type( spot_1->x, spot_1->y, layer_1 ), type_2 = calculate_type( spot_2->x, spot_2->y, layer_2 );
     if ( type_1 != type_2 )
          return ( type_1 - type_2 );

     switch ( type_1 ) {
          case 1 :
               return ( spot_1->x - spot_2->x );
          case 2 :
               return ( spot_1->y - spot_2->y );
          case 3 :
               return -( spot_1->x - spot_2->x );
          case 4 :
               return -( spot_1->y - spot_2->y );
          default :
               break;
     }
}

int main ( int argc, char *argv[] ) {
     scanf("%d%d", &n, &m);
     Attraction *spots = calloc(m, sizeof(Attraction));

     FILE *file_in = fopen( argv[1], "rb" );
     assert( file_in != NULL );
     fread( spots, sizeof(Attraction), m, file_in );

     qsort( spots, m, sizeof(Attraction), spots_cmp );
     for ( int i = 0; i < m; i++ )
          printf("%d %d\n", (spots+i)->x, (spots+i)->y);
     fclose(file_in);
     return 0;
}
