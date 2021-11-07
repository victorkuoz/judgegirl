#include <stdio.h>
#include <stdbool.h>

int n, k, m, p, ans[100];
bool found = false;
long long int member, clubs[100];
void disjoint_clubs ( int count, int prev_index, long long int prev ) {
     if (found)
          return;
     if ( count == k ) {
          for ( int i = 0; i < k; i++ )
               printf("%d\n", ans[i]);
          found = true;
          return;
     }

     for ( int i = prev_index; i < n; i++ )
          if ( ( prev & clubs[i] ) == 0 ) {
               ans[count] = i;
               disjoint_clubs( count+1, i, prev ^ clubs[i] );
          }
     return;
}

int main ( ) {
     scanf("%d%d", &n, &k);

     for ( int i = 0; i < n; i++ ) {
          scanf("%d", &m);
          for ( int j = 0; j < m; j++ ) {
               scanf("%d", &p);
               member = 1;
               member <<= p;
               clubs[i] += member;
          }
     }
     disjoint_clubs( 0, 0, 0 );
     return 0;
}
