#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int index, num;
} Data;
typedef struct {
     int small, large, sum;
} Pair;

int data_cmp ( const void *ptr1, const void *ptr2 ) {
     return ( ((Data*)ptr1)->num -  ((Data*)ptr2)->num );
}
int pair_cmp ( const void *ptr1, const void *ptr2 ) {
#ifdef INC
     if ( ((Pair*)ptr1)->sum != ((Pair*)ptr2)->sum )
          return ( ((Pair*)ptr1)->sum - ((Pair*)ptr2)->sum );
     return ( ((Pair*)ptr1)->small - ((Pair*)ptr2)->small );
#endif // INC
#ifdef DEC
     if ( ((Pair*)ptr1)->sum != ((Pair*)ptr2)->sum )
          return ( ((Pair*)ptr2)->sum - ((Pair*)ptr1)->sum );
     return ( ((Pair*)ptr2)->large - ((Pair*)ptr1)->large );
#endif // DEC
}

void pairPrint(int numbers[], int n){
    Data datas[n];
    for ( int i = 0; i < n; i++ ) {
          datas[i].index = i;
          datas[i].num = numbers[i];
    }
    qsort( datas, n, sizeof(Data), data_cmp);

    Pair pairs[(n/2)];
    for ( int i = 0, j = (n-1); i < (n/2); i++, j-- ) {
          pairs[i].small = ( datas[i].index < datas[j].index ) ? ( datas[i].index ) : ( datas[j].index );
          pairs[i].large = ( datas[i].index < datas[j].index ) ? ( datas[j].index ) : ( datas[i].index );
          pairs[i].sum = ( datas[i].num + datas[j].num );
    }
    qsort( pairs, (n/2), sizeof(Pair), pair_cmp);

     for ( int i = 0; i < (n/2); i++ ) {
#ifdef INC
     printf("%d = numbers[%d] + numbers[%d]\n", pairs[i].sum, pairs[i].small, pairs[i].large);
#endif // INC
#ifdef DEC
     printf("%d = numbers[%d] + numbers[%d]\n", pairs[i].sum, pairs[i].large, pairs[i].small);
#endif // DEC
     }
    return;
}
