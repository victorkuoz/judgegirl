#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define length 31

int main ( ) {
     char filename[length];
     scanf("%s", &filename);
     FILE *file_in = fopen( filename, "r" );
     assert( file_in != NULL );

     char pre = '\n', c;
     int line = 0, word = 0, byte = 0, is_word = 0;
     while ( ( c = fgetc(file_in) ) != EOF ) {
          if ( c == '\n' )
               line++;
          if ( !isalpha(c) )
               is_word = 0;
          else if ( !is_word ) {
               is_word = 1;
               word++;
          }
          byte++;
          pre = c;
     }
     if ( pre != '\n' )
          line++;

     printf("%d %d %d", line, word, byte);
     return 0;
}
