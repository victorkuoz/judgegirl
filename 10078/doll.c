#include <stdlib.h>
#include "doll.h"
Doll *newDoll(char top, char bottom) {
     Doll *doll = (Doll*) malloc(sizeof(Doll));
     doll->top = top;
     doll->bottom = bottom;
     doll->interior = NULL;
     return doll;
}
void package(Doll *outer, Doll *inter){
     outer->interior = inter;
     return;
}
const char* doll_c_str(Doll *doll){
     int n = 0;
     for ( Doll *ptr = doll; ptr != NULL; ptr = ptr->interior )
          n += 2;
     char *string = (char*) malloc((n+1)*sizeof(char));
     int idx1 = 0, idx2 = (n-1);
     for ( Doll *ptr = doll; ptr != NULL; ptr = ptr->interior, idx1++, idx2-- ) {
          string[idx1] = ptr->top;
          string[idx2] = ptr->bottom;
     }
     string[n] = '\0';
     return string;
}
