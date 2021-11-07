#include <stdio.h>
#define length (32+1)

int main ( ) {
     char string[length];
     scanf("%s", &string);

     int n, input, index = 0, temp[5];
     scanf("%d", &n);
     for ( int i = 0; i < n; i++ ) {
          scanf("%d", &input);
          for ( int i = 31; i >= 0; i-- ) {
               temp[index] = ( ( input >> i ) & 1 );
               if ( index == 4 ) {
                    index = temp[0]*16 + temp[1]*8 + temp[2]*4 + temp[3]*2 + temp[4];
                    printf("%c", string[index]);
                    index = 0;
               }
               else
                    index++;
          }
     }
     return 0;
}
