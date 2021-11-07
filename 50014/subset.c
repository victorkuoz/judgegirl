#include <stdlib.h>
#include <stdbool.h>
#include "subset.h"
int flag;
void Selection ( int numbers[], int n, int K, int S, int idx, int count, int sum, int *ans ) {
     if ( flag || sum > K || ( count == S && sum != K ) || ( sum == K && count != S ) )      return;
     if ( sum == K && count == S ) {
          flag = 1;
          return;
     }

     for ( int i = idx; i < n; i++ ) {
          ans[count] = numbers[i];
          Selection( numbers, n, K, S, i+1, count+1, sum+numbers[i], ans );
     }
     return;
}

int subset(int numbers[], int n, int K, int S){
    flag = 0;
    int *ans = calloc(S, sizeof(int));
    Selection( numbers, n, K, S, 0, 0, 0, ans );
    return flag;
}
