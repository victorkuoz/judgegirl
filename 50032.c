#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 15

bool solved;
int n, m, k;
int *grid, *row, *col, *pos, *neg;
void initialize ( int n ) {
     grid = (int*) calloc( n*n, sizeof(int));
     row = (int*) calloc( n, sizeof(int));
     col = (int*) calloc( n, sizeof(int));
     pos = (int*) calloc( (2*n-1), sizeof(int));
     neg = (int*) calloc( (2*n-1), sizeof(int));
     return;
}
void free_all ( void ) {
     free(grid);
     free(row);
     free(col);
     free(pos);
     free(neg);
     return;
}

void pieces ( int index , int count ) {
     if ( m == count )
          solved = true;
     if ( solved || n*n <= index )
          return;
     int r = ( index / n ), c = ( index % n );
#ifdef debug
     printf("index = %d count = %d\n", index, count);
     for ( int i = 0; i < n; i++ ) {
          for ( int j = 0; j < n; j++ )
               printf("%c", ( !grid[n*i+j] ) ? '.' : 'o');
          printf("\n");
     }
     printf("r = %d c = %d\n", r, c);
#endif // debug

     if ( row[r] < k && col[c] < k && pos[r+c] < k && neg[r-c+n-1] < k ) {
          row[r] += 1;      col[c] += 1;      pos[r+c] += 1;         neg[r-c+n-1] += 1;
          grid[index] = 1;
          pieces( index+1, count+1);
          if ( solved )
               return;
          row[r] -= 1;      col[c] -= 1;      pos[r+c] -= 1;         neg[r-c+n-1] -= 1;
          grid[index] = 0;
     }
     pieces( index+1, count);
     return;
}

int main () {
     while ( scanf("%d%d%d", &n, &m, &k) != EOF ) {
          if ( (n*k) < m ) {
               printf("N\n");
               continue;
          }

          initialize(n);
          solved = false;
          pieces(0, 0);

          if ( !solved )
               printf("N\n");
          else {
               for ( int i = 0; i < n; i++ ) {
                    for ( int j = 0; j < n; j++ )
                         printf("%c", ( !grid[n*i+j] ) ? '.' : 'o');
                    printf("\n");
               }
          }
          free_all();
     }
     return 0;
}
