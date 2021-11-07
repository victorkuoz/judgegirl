#include "array.h"
#define n (a->n)
#define start (a->start)
#define initial (INT_MIN+1)

int increasing ( const void *ptr1, const void *ptr2 ) {
     if ( *(int*)ptr1 < *(int*)ptr2 )        return (-1);
     if ( *(int*)ptr1 > *(int*)ptr2 )        return 1;
     return 0;
}
void init(ARRAY *a,  int left, int right) {
     start = left;
     n = ( right - left + 1 );
     a->data = (int*) malloc(n*sizeof(int));

     for ( int k = 0; k < n; k++ )
          a->data[k] = initial;
}
int set(ARRAY *a, int index, int value) {
     if ( index - start >= 0 && index - start <= n ) {
          a->data[index - start] = value;
          return 1;
     }
     return INT_MIN;
}
int get(ARRAY *a, int index) {
     if ( index - start >= 0 && index - start <= n )
          return a->data[index - start];
     return INT_MIN;
}
void print(ARRAY *a) {
     for ( int k = 0; k < n; k++ ) {
          if ( a->data[k] != initial )
               printf("%d\n", a->data[k]);
          else
               printf("No value\n");
     }
     return;
}
void sort(ARRAY *a) {
     qsort( a->data, n, sizeof(int), increasing);
     return;
}
