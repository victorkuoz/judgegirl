#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "componentPart.h"

int calculate_price ( int cur, ComponentPart list[] ) {
     if ( list[cur].price == 0 )
          for ( int i = 0; i < list[cur].numComponent; i++ )
               list[cur].price += calculate_price( list[cur].componentPartList[i], list );
     return list[cur].price;
}

int increasing ( const void *ptr1, const void *ptr2 ) {
     return strcmp( (*((ComponentPart**)ptr1))->name, (*((ComponentPart**)ptr2))->name );
}

void findPrice(int N, ComponentPart list[]) {
     ComponentPart *list_ptr[N];

     for ( int k = 0; k < N; k++ ) {
          if ( list[k].numComponent )
               calculate_price( k, list );
          list_ptr[k] = &list[k];
     }

     qsort( list_ptr, N, sizeof(ComponentPart*), increasing );
     for ( int k = 0; k < N; k++ )
          printf("%s %d\n", list_ptr[k]->name, list_ptr[k]->price);
     return;
}
