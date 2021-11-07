#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

#define length 31

int main () {
     int n;
     scanf("%d", &n);

     FILE *file_in[n];
     char filename[length];
     for ( int i = 0; i < n; i++ ) {
          scanf("%s", filename);
          file_in[i] = fopen( filename, "rb" );
          assert( file_in[i] != NULL );
     }

     int data[n];
     for ( int i = 0; i < n; i++ )
          fread( &data[i], sizeof(int), 1, file_in[i] );


     int index, remain = n;
     while ( remain ) {
          int min = INT_MAX;
          for ( int i = 0; i < n; i++ ) {
               if ( data[i] != (-1) && data[i] < min ) {
                    min = data[i];
                    index = i;
               }
          }
          printf("%d\n", min);
          if ( fread( &data[index], sizeof(int), 1, file_in[index] ) == 0 ) {
               data[index] = (-1);
               remain--;
          }
     }
     for ( int i = 0; i < n; i++ )
          fclose(file_in[i]);
     return 0;
}
