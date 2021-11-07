#include <stdio.h>
#include <stdlib.h>
#include "activity.h"

int act_cmp ( const void *ptr1, const void *ptr2 ) {
     return ( ((Activity*)ptr1)->end - ((Activity*)ptr2)->end );
}
int select(Activity activities[], int n) {
     int count = 0, end = 0;
     qsort( activities, n, sizeof(Activity), act_cmp);
     for ( int i = 0; i < n; i++ ) {
          if ( end <= activities[i].start ) {
               count++;
               end = activities[i].end;
#ifdef PRINT
               printf("%d %d\n", activities[i].start, activities[i].end);
#endif // PRINT
          }
     }
     return count;
}
