#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define length 51

typedef struct {
     char string[length];
     int cost;
} Data;
Data *datas[20];

int n, min = INT_MAX;
void selection ( int index, int temp, int *selected ) {
     if ( temp >= min )
          return;

     int stop = 1;
     for ( int i = 0; i < 26; i++ ) {
          if ( !selected[i] ) {
               stop = 0;
               break;
          }
     }
     if ( stop ) {
          min = temp;
          return;
     }

     if ( index == n )
          return;

     int *next = (int*) malloc(26*sizeof(int));
     for ( int i = 0; i < 26; i++ )
          next[i] = selected[i];
     int len = strlen( datas[index]->string );
     for ( int i = 0; i < len; i++ )
          next[ (datas[index]->string[i]) - 'a' ] = 1;
     selection( index+1, temp + datas[index]->cost, next );
     free(next);
     selection( index+1, temp, selected );
     return;
}

int main ( ) {
     scanf("%d", &n);
     for ( int i = 0; i < n; i++ ) {
          datas[i] = (Data*) malloc(sizeof(Data));
          scanf("%s%d", &(datas[i]->string), &(datas[i]->cost));
     }
     /*for ( int i = 0; i < n; i++ )
          printf("%s %d\n", datas[i]->string, datas[i]->cost);*/

     int *selected = (int*) calloc(26,sizeof(int));
     selection( 0, 0, selected );
     printf("%d", min);

     return 0;
}
