#include <stdlib.h>
#include "elevator.h"

struct Elevator {
     int u, d, p, F, *visited, invalid;
     char pre;
};
typedef struct Elevator Elevator;
Elevator* newElevator(int u, int d, int F) {
     Elevator *elevator = (Elevator*) malloc(sizeof(Elevator));
     elevator->u = u;
     elevator->d = d;
     elevator->p = 1;
     elevator->F = F;
     elevator->visited = (int*) calloc((F+1),sizeof(int));
     elevator->visited[1] = 1;
     elevator->pre = 'V';
     elevator->invalid = 0;
     return elevator;
}
int up(Elevator* elevator) {
     int floor = ( elevator->p + elevator->u );
     if ( floor <= elevator->F ) {
          elevator->p = floor;
          elevator->visited[floor] = 1;
          elevator->invalid = 0;
          elevator->pre = 'U';
          return 1;
     }
     if ( elevator->pre == 'U' )
          elevator->invalid++;
     else
          elevator->invalid = 1;
     elevator->pre = 'U';
     if ( elevator->invalid < 4 )
          return 0;
     return (-1);
}
int down(Elevator* elevator) {
     int floor = ( elevator->p - elevator->d );
     if ( floor >= 1 ) {
          elevator->p = floor;
          elevator->visited[floor] = 1;
          elevator->invalid = 0;
          elevator->pre = 'D';
          return 1;
     }
     if ( elevator->pre == 'D' )
          elevator->invalid++;
     else
          elevator->invalid = 1;
     elevator->pre = 'D';
     if ( elevator->invalid < 4 )
          return 0;
     return (-1);

}
int visited(Elevator* elevator, int floor) {
     if ( floor < 1 || floor > elevator->F )
          return 0;
     if ( elevator->visited[floor] )
          return 1;
     return 0;
}
int getPosition(Elevator* elevator) {
     return elevator->p;
}
