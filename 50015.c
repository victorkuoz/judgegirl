#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 850

int rules[26][26] = {0};

void words ( int n, int m, int index, int *table, char *ans ) {
     if ( index > 1 ) {
          int r = ( ans[index-2] - 'a' ), c = ( ans[index-1] - 'a' );
          if ( rules[r][c] )
               return;
     }

     if ( index == n ) {
          ans[index] = '\0';
          printf("%s\n", ans);
          return;
     }

     for ( int i = 0; i < 26; i++ ) {
          if ( table[i] != 0 ) {
                    table[i]--;
                    ans[index] =  i + 'a';
                    words( n, m, index+1, table, ans );
                    table[i]++;
          }
     }
     return;
}

int main ( ) {
     char string[30];
     scanf("%s", &string);
     int table[26] = {0}, n = strlen(string);
     for ( int i = 0; i < n; i++ )
          table[ ( string[i] - 'a' ) ]++;

     int m;
     scanf("%d", &m);
     char rule[3];
     for ( int i = 0; i < m; i++ ) {
          scanf("%s", &rule);
          int r = ( rule[0] - 'a' ), c = ( rule[1] - 'a' );
          rules[r][c] = 1;
     }

     char *ans = (char*) malloc((n+1)*sizeof(char));
     words( n, m, 0, table, ans );
     return 0;
}
