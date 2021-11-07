#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 5

int increasing ( const void *ptr_1, const void *ptr_2 ) {
     if ( *(char*)ptr_1 < *(char*)ptr_2 )
          return -1;
     if ( *(char*)ptr_1 > *(char*)ptr_2 )
          return 1;
     return 0;
}
void transform ( char *ans ) {
     int k = 0;
     for ( k = 0; k < 5 && ans[k] != '\0'; k++ )
          ans[k] = toupper(ans[k]);
     qsort(ans, k, sizeof(char), increasing);
     return;
}
int main () {
     int n, r, w, m, score;
     char ans[max+1];

     while ( scanf("%d%d%d", &n, &r, &w) != EOF ) {
          char Ans[n][max+1];
          for ( int k = 0; k < n; k++ )
               scanf("%s", &Ans[k]);

          scanf("%d", &m);
          for ( int k = 0; k < m; k++ ) {
               score = 0;
               for ( int i = 0; i < n; i++ ) {
                    scanf("%s", &ans);
                    if ( strcmp( ans, "N/A") != 0 ) {
                         transform(ans);
                         if ( strcmp( ans, Ans[i] ) == 0 )
                              score += r;
                         else
                              score -= w;
                    }
               }
               score = ( score < 0 ) ? 0: score;
               printf("%d\n", score);
          }
     }
     return 0;
}
