#include "eval.h"

int eval(int exp[]) {
     if ( exp[0] == 1 )
          return exp[1];

     int idx_1 = 1, idx_2 = 0;
     int n = exp[0];
     int data[n];

     while (n) {
          if ( exp[idx_1+1] < 1 || exp[idx_1+1] > 4 )
               return (-2147483646);
          else if ( exp[idx_1+1] == 4 && exp[idx_1+2] == 0 )
               return (-2147483647);
          if ( exp[idx_1+1] == 3 )
               exp[idx_1+2] = exp[idx_1]*exp[idx_1+2];
          else if ( exp[idx_1+1] == 4 )
               exp[idx_1+2] = exp[idx_1]/exp[idx_1+2];
          else {
               data[idx_2] = exp[idx_1];
               data[idx_2+1] = exp[idx_1+1];
               idx_2 += 2;
          }
          idx_1 += 2;

          if ( idx_1 == n ) {
               data[idx_2] = exp[idx_1];
               break;
          }
     }

     int ans = data[0];
     for ( int i = 2; i <= idx_2; i += 2 ) {
          if ( data[i-1] == 1 )
               ans += data[i];
          else
               ans -= data[i];
     }
     return ans;
}
