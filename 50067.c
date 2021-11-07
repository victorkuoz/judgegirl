#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main ( ) {
     char filename[16];
     scanf("%s", &filename);
     FILE *file_in = fopen( filename, "rb" );

     int flag, para;
     char c;
     while ( fread( &flag, sizeof(int), 1, file_in ) != 0 ) {
          if ( flag == 1 ) {
               for ( int i = 0; i < 4; i++ ) {
                    fread( &c, sizeof(char), 1, file_in );
                    printf("%c", c);
               }
               continue;
          }
          if ( flag == 2 ) {
               fseek( file_in, sizeof(int), SEEK_CUR );
               while ( fread( &c, sizeof(char), 1, file_in) != 0 ) {
                    if ( c == '\0' )
                         break;
                    printf("%c", c);
               }
               continue;
          }
          fread( &para, sizeof(int), 1, file_in );
          if ( flag == 0 )
               printf("%d", para);
          else if ( flag == 3 )
               fseek( file_in, (para-8), SEEK_CUR ) ;
          else if ( flag == 4 )
               fseek( file_in, para, SEEK_SET );
          else if ( flag == 5 )
               fread( &para, sizeof(int), 1, file_in );
          else {
               printf("Seek end");
               return 0;
          }
     }

     return 0;
}
