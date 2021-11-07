#include <stdio.h>
#include <stdbool.h>

#define max_size 4
#define index(r,c) (max_size*r + c + 1)%16

bool success;
int grid[max_size][max_size];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

void puzzle ( int r, int c, int remain, int wrong) {
#ifdef debug
     for ( int r = 0; r < max_size; r++ )
          for ( int c = 0; c < max_size; c++ )
               printf("%d%c", grid[r][c], ( c != max_size - 1 ) ? ' ' : '\n');
     printf("r = %d c = %d remain = %d wrong = %d\n", r, c, remain, wrong);
#endif // debug
     success = (!wrong) ? true : success;
     if ( success || remain < wrong || !remain )
          return;

     for ( int i = 0; i < max_size; i++ ) {
          int next_r = r + dr[i], next_c = c + dc[i], next_wrong = wrong;
          if ( 0 <= next_r && next_r < max_size && 0 <= next_c && next_c < max_size ) {
               if ( grid[next_r][next_c] == index(next_r, next_c) )
                    next_wrong++;
               else if ( grid[next_r][next_c] == index(r, c) )
                    next_wrong--;

               grid[r][c] = grid[next_r][next_c];
               grid[next_r][next_c] = 0;

               puzzle( next_r, next_c, (remain-1), next_wrong );

               grid[next_r][next_c] = grid[r][c];
               grid[r][c] = 0;
          }
     }
     return;
}

int main ( ) {
     int k;
     while ( scanf("%d", &k) != EOF ) {
          int next_r, next_c, wrong = 0;
          for ( int r = 0; r < max_size; r++ ) {
               for ( int c = 0; c < max_size; c++ ) {
                    scanf("%d", &grid[r][c]);
                    if ( !grid[r][c] ) {
                         next_r = r;
                         next_c = c;
                    }
                    else if ( grid[r][c] != index(r,c) )
                         wrong++;
               }
          }
          success = false;
          puzzle(next_r, next_c, k, wrong);
          printf("%c\n", (success) ? '1' : '0');
     }
     return 0;
}
