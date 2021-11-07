#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 10000

char *cur, buffer[max_size+1];
float expected_value ( void ) {
     if ( cur[0] != '(' ) {
          float k = atof(cur);
          cur = strchr(cur, ' ');
          if ( cur != NULL )
               cur++;
          return k;
     }

     cur++;
     float p = expected_value();
     float expr1= expected_value();
     float expr2= expected_value();
     return p*((expr1)+(expr2)) + (1-p)*((expr1)-(expr2));
}

int main ( ) {
     while ( fgets(buffer, max_size, stdin) != NULL ) {
          cur = buffer;
          printf("%.2f\n", expected_value());
     }
     return 0;
}
