#include <stdio.h>
#include <stdlib.h>
#include "City_Grid.h"
int visited[10000];
int count ( City *city) {
     if ( visited[city->label] )
          return 0;
     visited[city->label] = 1;

     if ( city->east != NULL && city->north != NULL ) {
          if ( city->east->north != NULL && city->north->east != NULL )
               return 1 + count(city->east) + count(city->north);
          return count(city->east) + count(city->north);
     }
     if ( city->east != NULL )
          return count(city->east);
     if ( city->north != NULL )
          return count(city->north);
     return 0;
}

int City_Grid(City *capital) {
     for ( int i = 0; i < 10000; i++ )
          visited[i] = 0;
     int ans = count(capital);
     return ans;
}

