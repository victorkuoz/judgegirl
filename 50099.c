#include <stdio.h>

int balance_point ( int n, int data[] ) {
     for ( int k = 0; k < n; k++ ) {
          int left = 0, right = 0;
          for ( int i = 0; i < k && k != 0; i++ )
               left += data[i]*(k-i);
          for ( int i = (k+1); i < n && k != (n-1); i++ )
               right += data[i]*(i-k);
          if ( left == right )
               return k;
     }
     return (-1);
}

void seesaw_chandelier( int n, int start, int data[], int ans[] ) {
     if ( n < 3 )
          return;
     int index = balance_point( n, data );
     if ( index == (-1) )
          return;
     ans[start+index] = 1;
     seesaw_chandelier( index, start, data, ans );
     seesaw_chandelier( n-index-1, (start+index+1), data+(index+1), ans );
     return;
}

int main ( ) {
     int n;
     scanf("%d", &n);

     int data[n], ans[n];
     for ( int k = 0; k< n; k++ ) {
          scanf("%d", &data[k]);
          ans[k] = 0;
     }

     seesaw_chandelier( n, 0, data, ans );

     for ( int k = 0; k < n; k++ )
          if ( ans[k] )
               printf("%d\n", k);

     return 0;
}
