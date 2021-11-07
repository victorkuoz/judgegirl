#include <stdio.h>
#define max 100001

int main ( ) {
     int n;
     char string[max], final_u[26], u[2], v[2];
     scanf("%s%d", &string, &n);

     for ( int i = 0; i < 26; i++ )
          final_u[i] = ( i + 'A' );
     for ( int i = 0; i < n; i++ ) {
          scanf("%s%s", &u, &v);
          for ( int j = 0; j < 26; j++ )
               if ( final_u[j] == v[0] )
                    final_u[j] = u[0];
     }

     for ( int index = 0; string[index] != '\0'; index++ )
          string[index] = final_u[ string[index] - 'A' ];
     printf("%s", string);
     return 0;
}
