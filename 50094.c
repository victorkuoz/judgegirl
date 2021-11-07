#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 101

void word_learning ( int index, int r, int T, int *chosen, int *table, char *ans ) {
     int c, max = T;
     for ( int i = 0; i < 26; i++ ) {
          if ( table[26*r+i] > max && !chosen[i] ) {
               max = table[26*r+i];
               c = i;
          }
     }

     if ( max > T ) {
          ans[index] = c + 'a';
          chosen[c] = 1;
          word_learning( index+1, c, T, chosen, table, ans );
     }
     else
          ans[index] = '\0';
     return;
}


int main ( ) {
     int T, r, c;
     scanf("%d", &T);
     char s[length], ans[27];
     int *table = (int*) calloc(26*26, sizeof(int));
     int *chosen = (int*) calloc(26, sizeof(int));

     while ( scanf("%s", &s) != EOF ) {
          int len = strlen(s);
          for ( int i = 0; i < (len-1); i++ ) {
                    r = s[i] - 'a', c = s[i+1] - 'a';
                    table[26*r+c]++;
          }
     }

     int max = T;
     for ( int i = 0; i < 26; i++ )
          for ( int j = 0; j < 26; j++ ) {
               printf("%d%c", table[26*i+j], ( j != 25 ) ? ' ' : '\n');
               if ( table[26*i+j] > max && i != j ) {
                    r = i;
                    max = table[26*i+j];
               }
          }

     if ( max > T ) {
          ans[0] = r + 'a';
          chosen[r] = 1;
          word_learning( 1, r, T, chosen, table, ans );
          printf("%s", ans);
     }
     return 0;
}
