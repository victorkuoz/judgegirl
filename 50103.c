#include <stdio.h>
#include <assert.h>
#define length 17

char reverse ( char *c ) {
     char temp = 0;
     for ( int i = 0; i < 8; i++ ) {
          temp += ( ( ( *c >> i ) & 1 ) << ( 7 - i ) );
     }
     return temp;
}

int main ( ) {
     int n;
     char filename_in[length], filename_out[length];
     scanf("%s%s%d", &filename_in, &filename_out, &n);

     FILE *file_in = fopen( filename_in, "rb" );
     assert( file_in != NULL );
     FILE *file_out = fopen( filename_out, "wb" );
     assert( file_out != NULL );

     int start = ftell(file_in);

     char c;
     fseek( file_in, -(n+1)*sizeof(char), SEEK_END );
     int end = ftell(file_in);
     while ( ftell(file_in) != start ) {
          fread( &c, sizeof(char), 1, file_in );
          c = reverse(&c);
          fwrite( &c, sizeof(char), 1, file_out );
          fseek( file_in, (-2)*sizeof(char), SEEK_CUR );
     }

     fread( &c, sizeof(char), 1, file_in );
     c = reverse(&c);
     fwrite( &c, sizeof(char), 1, file_out );
     fseek( file_in, -(sizeof(char)), SEEK_END );


     while ( ftell(file_in) != end ) {
          fread( &c, sizeof(char), 1, file_in );
          c = reverse(&c);
          fwrite( &c, sizeof(char), 1, file_out );
          fseek( file_in, (-2)*sizeof(char), SEEK_CUR );
     }

     fclose(file_in);
     fclose(file_out);
     return 0;
}
