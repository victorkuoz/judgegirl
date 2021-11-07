#include <stdio.h>
#define replace( left, right, Left, Right ) ( left + right > Left + Right  || ( left + right == Left + Right && left > Left ) )

int main () {
     int pre_prev, prev, cur, index = 2;
     int p1 = 1, p2 = 1, p, left = 2, right = 2, Left = 0, Right = 0;

     scanf("%d%d", &pre_prev, &prev);
     while ( scanf("%d", &cur) != EOF ) {
          index++;
          if ( (prev-pre_prev)*(cur-prev) > 0 ) {   // increasing or decreasing
               if ( p2 == 1 )
                    left++;
               else
                    right++;
          }
          else {
               if ( p2 != 1 ) {
                    if ( replace( left, right, Left, Right ) ) {
                         p = p1;
                         Left = left;
                         Right = right;
                    }
                    p1 = p2;
                    left = right;
               }
               p2 = index-1;
               right = 2;
          }
          pre_prev = prev;
          prev = cur;
     }

     if ( p2 == 1 )
          printf("0");
     else if ( replace( left, right, Left, Right ) )
          printf("%d %d", left + right - 1, p1);
     else
          printf("%d %d", Left + Right - 1, p);
     return 0;
}
