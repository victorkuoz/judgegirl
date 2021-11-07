#include <stdio.h>

void Classifier ( int flag, int m, int T, int *w, int *p ) {
     int sum = 0;
     for ( int r = 0; r < m; r++ )
          for ( int c = 0; c < m; c++ )
               sum += p[m*r+c]*w[m*r+c];
     if ( flag == (-1) ) {
          if ( sum >= T)
               printf("1\n");
          else
               printf("0\n");
     }
     else if ( flag && ( sum < T ) )
          for ( int r = 0; r < m; r++ )
               for ( int c = 0; c < m; c++ )
                    if ( p[m*r+c] )
                         w[m*r+c] *= 2;
     else if ( !flag && ( sum >= T ) )
          for ( int r = 0; r < m; r++ )
               for ( int c = 0; c < m; c++ )
                    if ( p[m*r+c] && w[m*r+c] >= 2 )
                         w[m*r+c] /= 2;
     return;
}

int main ( ) {
     int n,m,q;
     scanf("%d%d", &n, &m);
     int flag, T = (2*m*m), w[m*m], p[m*m];

     for ( int r = 0; r < m; r++ )
          for ( int c = 0; c < m; c++ )
               w[m*r+c] = 1;
     for ( int i = 0; i < n; i++ ) {
          scanf("%d", &flag);
          for ( int r = 0; r < m; r++ )
               for ( int c = 0; c < m; c++ )
                    scanf("%d", &p[m*r+c]);
          Classifier( flag, m, T, w, p );
     }

     scanf("%d", &q);
     for ( int i = 0; i < q; i++ ) {
          for ( int r = 0; r < m; r++ )
               for ( int c = 0; c < m; c++ )
                    scanf("%d", &p[m*r+c]);
          Classifier( (-1), m, T, w, p );
     }
     return 0;
}
