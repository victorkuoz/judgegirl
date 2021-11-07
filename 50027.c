#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define length 31

typedef struct {
    int balance;
    char name[128];
    int gender;
} Account;
Account *accounts[1024];

int account_cmp ( const void *ptr1, const void *ptr2 ) {
     return strcmp( (*((Account**)ptr1))->name, (*((Account**)ptr2))->name );
}

int main () {
     char filename_in[length], filename_out[length];
     scanf("%s%s", &filename_in, &filename_out);
     FILE *file_in = fopen( filename_in, "rb" );
     assert( file_in != NULL );
     FILE *file_out = fopen( filename_out, "wb" );
     assert( file_out != NULL );

     int m = 0;
     accounts[m] = (Account*) malloc(sizeof(Account));
     while ( fread( accounts[m], sizeof(Account), 1, file_in) != 0 ) {
          if ( accounts[m]->balance < 0 || ( accounts[m]->gender != 0 && accounts[m]->gender != 1 ) )
               continue;
          int len = strlen( accounts[m]->name ), valid = 1;
          for ( int i = 0; i < len; i++ )
               if ( !isalpha(accounts[m]->name[i]) && accounts[m]->name[i] != ' ' ) {
                    valid = 0;
                    break;
               }
          if ( !valid )
               continue;
          m++;
          accounts[m] = (Account*) malloc(sizeof(Account));
     }

     qsort( accounts, m, sizeof(Account*), account_cmp );

     for ( int i = 0; i < m; i++ ) {
          fwrite( accounts[i], sizeof(Account), 1, file_out );
     }
     fclose(file_in);
     fclose(file_out);
     return 0;
}
