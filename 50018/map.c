#include "map.h"

void init(Map *map) {
     map->n = 0;
     return;
}
int map(Map *map, const int key, const char *value) {
     for ( int i = 0; i < map->n; i++ )
          if ( map->pairs[i]->key == key ) {
               strcpy( map->pairs[i]->value, value );
               return 0;
          }
     map->pairs[map->n] = (Pair*) malloc(sizeof(Pair));
     map->pairs[map->n]->value = (char*) malloc(length*sizeof(char));
     map->pairs[map->n]->key = key;
     strcpy( map->pairs[map->n]->value, value );
     map->n++;
     return 1;
}
int numPairs(Map *map) {

     return map->n;

}
int pair_cmp ( const void *ptr1, const void *ptr2 ) {
     return ( (*(Pair**)ptr1)->key - (*(Pair**)ptr2)->key );
}
void print(Map *map) {
     qsort( map->pairs, map->n, sizeof(Pair*), pair_cmp);
     printf("----- map begin -----\n");
     for ( int i = 0; i < map->n; i++ )
          printf("%d %s\n", map->pairs[i]->key, map->pairs[i]->value);
     printf("----- end       -----\n");
}
const char *getValue(Map *map, const int key) {
     for ( int i = 0; i < map->n; i++ )
          if ( map->pairs[i]->key == key )
               return map->pairs[i]->value;
     return NULL;
}
int unmap(Map *map, int key) {
     for ( int i = 0; i < map->n; i++ )
          if ( map->pairs[i]->key == key ) {
               free(map->pairs[i]);
               for ( int j = ( i + 1 ); j < map->n; j++ )
                   map->pairs[j-1] = map->pairs[j];
               map->n--;
               return 1;
          }
     return 0;
}
int reverseMap(Map *map, const char *value, int keys[]) {
     qsort( map->pairs, map->n, sizeof(Pair*), pair_cmp );
     int index = 0;
     for ( int i = 0; i < map->n; i++ ) {
          if ( strcmp( map->pairs[i]->value, value ) == 0 ) {
               keys[index] = map->pairs[i]->key;
               index++;
          }
     }
     return index;
}
