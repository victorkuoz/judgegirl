#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elevator.h"
#define length 1501

char ins[length];

int main ( ) {
     int n;
     scanf("%d", &n);
     Elevator *elevator;

     for ( int i = 0; i < n; i++ ) {
          int u, d, F;
          scanf("%d%d%d", &u, &d, &F);

          elevator = newElevator( u, d, F );

          scanf("%s", &ins);
          int len = strlen(ins);
          for ( int j = 0; j < len; j++ ) {
               int flag;
               if ( ins[j] == 'U' )
                    flag = up(elevator);
               else if ( ins[j] == 'D' )
                    flag = down(elevator);
               if ( flag == 1 )
                    printf("Valid %d\n", getPosition(elevator));
               else if ( flag == 0 )
                    printf("Invalid\n");
               else {
                    printf("Broken\n");
                    break;
               }
          }

          for ( int i = 1; i <= F; i++ ) {
               if ( visited( elevator, i) )
                    printf("%d\n", i);
          }
          free(elevator);
     }


     return 0;
}
