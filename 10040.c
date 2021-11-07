#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 51

int main ( ) {
     int N, Q;
     scanf("%d", &N);
     char voc[N][max_len], s[max_len];
     char *temp = (char*)malloc(max_len*sizeof(char));

     for ( int k = 0; k < N; k++ )
          scanf("%s", voc[k]);

     scanf("%d", &Q);
     for ( int k = 0; k < Q; k++ ) {
          int ans = 0;
          scanf("%s", &s);
          int len_s = strlen(s);

          for ( int i = 0; i < N; i++ ) {
               strcpy( temp, voc[i] );
               int len_temp = strlen(temp);

               for ( int j = 0; j <= ( len_temp - len_s ); j++ ) {
                    if ( strncmp( temp, s, len_s) == 0 ) {
                         ans++;
                         break;
                    }
                    temp++;
               }
          }
          printf("%d\n", ans);
     }
     return 0;
}
