#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 17

bool solved, *chosen;
int n, len, mid, *data, *left_side, *right_side;
void initialize ( void ) {
     data = (int*) malloc(max_size*sizeof(int));
     left_side = (int*) malloc((max_size/2)*sizeof(int));
     right_side = (int*) malloc((max_size/2)*sizeof(int));
     chosen = (bool*) malloc(max_size*sizeof(bool));
     return;
}
int increasing ( const void *ptr1, const void *ptr2 ) {
     if ( *( (int*) ptr1 ) < *( (int*) ptr2) )
          return (-1);
     if ( *( (int*) ptr1 ) > *( (int*) ptr2) )
          return 1;
     return 0;
}
bool keep_going ( int left_idx, int right_idx, int left_torque, int right_torque ) {
     if ( left_idx + 1 == len  )   // initial condition
          return true;
     if ( left_torque > right_torque ) {
          int r_index = ( len - 1 ), l_index = 0;
          for ( int k = (n-1); k >= 0; k-- ) {    // from big to small
               if ( !chosen[k] ) {
                    if ( right_torque + data[k]*(r_index+1)*(r_index+1) < left_torque )
                         return false;
                    if ( right_idx <= r_index ) {
                         right_torque += (r_index+1)*data[k];
                         r_index--;
                    }
                    else {
                         left_torque += (l_index+1)*data[k];
                         l_index++;
                    }
               }
          }
          return ( left_torque <= right_torque );
     }
     else
          return false;
     printf("error error\n");
}

void see_saw ( int left_idx, int right_idx, int left_torque, int right_torque ) {
#ifdef debug
     printf("left = %d right = %d\n", left, right);
     printf("%d %d %d %d\n", left_side[1], left_side[0], right_side[0], right_side[1]);
#endif // debug
     if ( len < left_idx || len < right_idx ) {
          printf("error");
          exit(0);
     }

     if ( left_idx == (-1) && right_idx == len ) {
          if ( left_torque == right_torque )
               solved = true;
          return;
     }
     if ( solved || !keep_going(left_idx, right_idx, left_torque, right_torque) )
          return;

     for ( int k = (n-1); k >= 0 ; k-- ) {
          if ( !chosen[k] ) {
               chosen[k] = true;
               if ( left_idx >= 0 ) {
                    left_side[left_idx] = data[k];
                    see_saw( ( left_idx - 1 ), right_idx, ( left_torque + (left_idx+1)*data[k] ), right_torque );
               }
               else {
                    right_side[right_idx] = data[k];
                    see_saw( left_idx, ( right_idx + 1 ), left_torque, ( right_torque + (right_idx+1)*data[k] ) );
               }
               if ( solved )
                    return;
               left_side[left_idx] = right_side[right_idx] = 0;
               chosen[k] = false;
          }
     }
     return;
}

int main () {
     initialize();
     while ( scanf("%d", &n) != EOF ) {
          len = floor(n/2);
          solved = false;
          for ( int k = 0; k < n; k++ ) {
               scanf("%d", &data[k]);
               chosen[k] = false;
               left_side[k] = right_side[k] = 0;
          }
          qsort(data, n, sizeof(int), increasing);
#ifdef debug
     for ( int i = 0; i < n; i++)
          printf("%d ", data[i]);
     printf("\n");
#endif // debug
          for ( int k = (n-1); k >= 0 ; k-- ) {
               mid = data[k];
               chosen[k] = true;
               see_saw((len-1), 0, 0, 0);
               if ( solved )
                    break;
               chosen[k] = false;
          }

          if ( !solved )
               printf("N\n");
          else{
               for ( int k = (len-1); k >= 0 ; k-- )
                    printf("%d ", left_side[k]);
               printf("_^_ ");
               for ( int k = 0; k < len; k++ )
                    printf("%d%c", right_side[k], ( k != len - 1 ) ? ' ' : '\n');
          }
     }
     return 0;
}
