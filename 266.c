#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
     char string[11];
     int len;
} Data;
Data *datas[100];

int edit_distance ( int sidx_1, int sidx_2, int didx_1, int didx_2 ) {
     if ( sidx_1 == datas[didx_1]->len && sidx_2 == datas[didx_2]->len )
          return 0;
     if ( sidx_1 == datas[didx_1]->len )
          return datas[didx_2]->len - sidx_2;
     if ( sidx_2 == datas[didx_2]->len )
          return datas[didx_1]->len - sidx_1;

     if ( datas[didx_1]->string[sidx_1] == datas[didx_2]->string[sidx_2] )
          return edit_distance( sidx_1+1, sidx_2+1, didx_1, didx_2 );
     int a = edit_distance( sidx_1+1, sidx_2, didx_1, didx_2 ), b = edit_distance( sidx_1, sidx_2+1, didx_1, didx_2 );
     return (a<b) ? (1+a) : (1+b);
}

int main ( ) {
     int n = (-1);
     do {
          n++;
          datas[n] = (Data*) malloc(sizeof(Data));
     }
     while ( scanf("%s", &datas[n]->string) != EOF );
     free(datas[n]);

     for ( int i = 0; i < n; i++ )
          datas[i]->len = strlen(datas[i]->string);

     int temp, distance = INT_MAX, idx_1 = 101, idx_2 = 101;
     for ( int i = 0; i < n; i++ ) {
          for ( int j = (i+1); j < n; j++ ) {
               temp = edit_distance( 0, 0, i, j );
               if ( temp < distance || ( temp == distance && 1000*(i+1) + (j+1) < 1000*idx_1 + idx_2 ) ){
                    distance = temp;
                    idx_1 = (i+1);
                    idx_2 = (j+1);
               }
          }
     }
     printf("%d %d %d", distance, idx_1, idx_2);
     return 0;
}
