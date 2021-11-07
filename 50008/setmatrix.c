#include <stdio.h>
#include "setmatrix.h"

void processSetMatrix(int ***ptr) {
    int ***matric_ptr = ptr;
    while ( *matric_ptr != NULL ) {
          int **array_ptr = *matric_ptr;
          while ( *array_ptr != NULL ) {
               int *set_ptr = *array_ptr;
               while ( *set_ptr != 0 ) {
                    printf("%d ", *set_ptr);
                    set_ptr++;
               }
               array_ptr++;
          }
          matric_ptr++;
    }
    return;
}
