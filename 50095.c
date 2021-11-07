#include <stdio.h>
#include <string.h>

int Li[1024] = {0};
char **F[1024];
char *S[16384];
char W[10000000];
char c, *temp;

int main ( ) {
     int n, m, l1, w1, l2, w2;
     scanf("%d", &n);
     int idx_S = 0, idx_W = 0;
     for ( int idx_F = 0; idx_F < n; idx_F++ ) {
          F[idx_F] = &(S[idx_S]);
          while ( scanf("%s%c", &W[idx_W], &c) != EOF ) {
               Li[idx_F]++;
               S[idx_S] = &(W[idx_W]);
               idx_S++;
               idx_W += ( strlen(&W[idx_W]) + 1 );
               if ( c == '\n' )
                    break;
          }
     }

     scanf("%d", &m);
     for ( int i = 0; i < m; i++ ) {
          scanf("%d%d%d%d", &l1, &w1, &l2, &w2);
          temp = *( F[l1] + w1 );
          *( F[l1] + w1 ) = *( F[l2] + w2 );
          *( F[l2] + w2 ) = temp;
     }
     for ( int idx_F = 0; idx_F < n; idx_F++ )
          for ( idx_S = 0; idx_S < Li[idx_F]; idx_S++ )
               printf("%s%c", *( F[idx_F] + idx_S ), ( idx_S != Li[idx_F] - 1 ) ? ' ' : '\n');
     return 0;
}
