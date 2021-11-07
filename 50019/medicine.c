#include "medicine.h"

void init(Medicine *medicine) {
     medicine->act = medicine->in = medicine->w = 0;
     /*for ( int i = 0; i < 2; i++ )
          medicine->active[i] = NULL;
     for ( int i = 0; i < 5; i++ )
          medicine->inactive[i] = NULL;*/
     return;
}
int addActive(Medicine *medicine, char *name, int weight) {
     for ( int i = 0; i < medicine->act; i++ ) {
          if ( strcmp( name, medicine->active[i]->name ) == 0 ) {
               medicine->w += weight;
               medicine->active[i]->w += weight;
               return medicine->active[i]->w;
          }
     }
     if ( medicine->act < 2 ) {
          medicine->w += weight;
          medicine->active[medicine->act] = (Ingredient*) malloc(sizeof(Ingredient));
          medicine->active[medicine->act]->name = (char*) malloc(len*sizeof(char));
          strcpy( medicine->active[medicine->act]->name, name );
          medicine->active[medicine->act]->w = weight;
          medicine->act++;
          return weight;
     }
     return (-1);
}
int addInactive(Medicine *medicine, char *name, int weight) {
     for ( int i = 0; i < medicine->in; i++ ) {
          if ( strcmp( name, medicine->inactive[i]->name ) == 0 ) {
               medicine->w += weight;
               medicine->inactive[i]->w += weight;
               return medicine->inactive[i]->w;
          }
     }
     if ( medicine->in < 5 ) {
          medicine->w += weight;
          medicine->inactive[medicine->in] = (Ingredient*) malloc(sizeof(Ingredient));
          medicine->inactive[medicine->in]->name = (char*) malloc(len*sizeof(char));
          strcpy( medicine->inactive[medicine->in]->name, name );
          medicine->inactive[medicine->in]->w = weight;
          medicine->in++;
          return weight;
     }
     return (-1);
}
int cmp ( const void *ptr1, const void *ptr2 ) {
     Ingredient *ing1 = *((Ingredient**)ptr1);
     Ingredient *ing2 = *((Ingredient**)ptr2);

     int flag = ( ing2->w - ing1->w);
     if ( flag != 0 )
          return flag;
     return strcmp( ing1->name, ing2->name);
}
void print(Medicine *medicine) {
     qsort( medicine->active, medicine->act, sizeof(Ingredient*), cmp );
     qsort( medicine->inactive, medicine->in, sizeof(Ingredient*), cmp );
     printf("----- Active Ingredient begin   -----\n");
     for ( int i = 0; i < medicine->act; i++ )
          printf("%d %s\n", medicine->active[i]->w, medicine->active[i]->name);
     printf("----- end                       -----\n----- Inactive Ingredient begin -----\n");
     for ( int i = 0; i < medicine->in; i++ )
          printf("%d %s\n", medicine->inactive[i]->w, medicine->inactive[i]->name);
     printf("----- end                       -----\n");
     return;
}
int totalWeight(Medicine *medicine) {
     return medicine->w;
}
char *maxIngredient(Medicine *medicine) {
     if ( !( medicine->act + medicine->in ) )
          return NULL;

     int max = (-1);
     char *ptr;
     for ( int i = 0; i < medicine->act; i++ ) {
          if ( medicine->active[i]->w > max ) {
               ptr = medicine->active[i]->name;
               max = medicine->active[i]->w;
          }
          else if ( medicine->active[i]->w == max && strcmp( medicine->active[i]->name, ptr ) < 0 )
               ptr = medicine->active[i]->name;
     }

     for ( int i = 0; i < medicine->in; i++ ) {
          if ( medicine->inactive[i]->w > max ) {
               ptr = medicine->inactive[i]->name;
               max = medicine->inactive[i]->w;
          }
          else if ( medicine->inactive[i]->w == max && strcmp( medicine->inactive[i]->name, ptr ) < 0 )
               ptr = medicine->inactive[i]->name;
     }
     return ptr;
}
