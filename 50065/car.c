#include <stdio.h>
#include <stdlib.h>
#include "car.h"

#define stop 0
#define add 1
#define right 2
#define left 3
#define up 4
#define down 5

int move ( CarStatus *car, Command *command, CarStatusList *list ) {
     if ( command->t == add ) {
          car->g += command->v;
          return 1;
     }
     if ( command->t == stop || car->g - command->v < 0 )
          return 0;
     if ( command->t == right )
          car->x += command->v;
     else if ( command->t == left )
          car->x -= command->v;
     else if ( command->t == up )
          car->y += command->v;
     else if ( command->t == down )
          car->y -=  command->v;
     else
          return 0;
     car->g -= command->v;

     list->status[list->num] = *car;
     (list->num)++;
     return 1;
}


CarStatusList carSimulation ( CarStatus car, Command commands[] ) {
     CarStatusList *list = (CarStatusList*) malloc(sizeof(CarStatusList));
     list->num = 0;

     int flag = 1;
     for ( int i = 0; flag; i++ )
          flag = move( &car, &commands[i], list );
     return *list;
}
