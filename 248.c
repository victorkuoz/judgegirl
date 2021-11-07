#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 9
#define index(r,c) ( max_size*(r) + c )

int *grid, *cur;
bool solved = false, *ans;

int dr[max_size] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dc[max_size] = {1, 0, -1, 1, 0, -1, 1, 0, -1};

void add_mine ( int r, int c, int k ) {
     for ( int i = 0; i < 9; i++ )
          if ( 0 <= (r+dr[i]) && (r+dr[i]) < max_size && 0 <= (c+dc[i]) && (c+dc[i]) < max_size )
               cur[index((r+dr[i]), (c+dc[i]))] += k;
     return;
}

void Mine_field ( int r, int c ) {
     if (solved)
          return;
     
     if ( c > (max_size-1) ) {
          if ( r > 0 ) {
               for ( int i = (r-1), j = 0; j < 9; j++ )
                    if ( grid[index(i,j)] != cur[index(i,j)] )
                         return;
          }
          
          if ( r == (max_size-1) ) {
               for ( int i = r, j = 0; j < 9; j++ )
                    if ( grid[index(i,j)] != cur[index(i,j)] )
                         return;
               solved = true;
               return;
          }
          Mine_field(r+1,0);
          return;
     }

     Mine_field(r,c+1);
     if ( !solved ) {
          ans[index(r,c)] = true;
          add_mine(r,c,1);
          Mine_field(r,c+1);
          if ( !solved ) {
               ans[index(r,c)] = false;
               add_mine(r,c,(-1));
          }
     }
     return;
}

int main () {
     ans = (bool*) calloc(max_size*max_size, sizeof(bool));
     grid = (int*) calloc(max_size*max_size, sizeof(int));
     cur = (int*) calloc(max_size*max_size, sizeof(int));
     for ( int r = 0; r < max_size; r++ )
          for ( int c = 0; c < max_size; c++ )
               scanf("%d", &grid[index(r,c)]);
     Mine_field(0, 0);
     if ( !solved )
          printf("no solution\n");
     else {
          for ( int r = 0; r < max_size; r++ ) {
               for ( int c = 0; c < max_size; c++ )
                    printf("%d%c", ans[index(r,c)] ? 1 : 0, (c != (max_size-1)) ? ' ' : '\n');
          }
     }
     return 0;
}
