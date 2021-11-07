#include <stdio.h>
#include <stdbool.h>

#define max 3
#define C(x) ( ( a*(x) + b ) % c )
#define swap( a, b ) { int temp = a; a = b; b = temp; }

typedef struct{
     int input, ans;
} Data;

bool flag ( int a, int b, int c ){
     if ( a > b )   swap( a, b );
     if ( b > c )   swap( b, c );
     if ( a > b )   swap( a, b );

     if ( (c-b) == 1 && (b-a) == 1 )
          return true;
     else
          return false;
}

int main (){
     Data data[max];
     int a, b, c, d, e, x, count = 0;

     scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
     while ( scanf("%d", &x) != EOF ){
          count++;
          data[0] = data[1];
          data[1] = data[2];
          data[2].input = x;  data[2].ans = 0;

          while ( !( x >= d && x <= e ) ){
               x = C(x);
               data[2].ans++;
          }

          if ( count >= max && flag( data[0].ans, data[1].ans, data[2].ans ) ){
               printf("%d %d %d", data[0].input, data[1].input, data[2].input);
               return 0;
          }
     }
     printf("Not found");
     return 0;
}
