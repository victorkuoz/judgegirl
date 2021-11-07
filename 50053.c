#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#define max_len 50

typedef struct {
     char author[max_len];
     char name[max_len];
     int num;
} Book;

int increasing ( const void *ptr1, const void *ptr2 ) {
     int flag = strcmp( ((Book*)ptr1)->author, ((Book*)ptr2)->author );
     if ( flag < 0 )     return (-1);
     if ( flag > 0 )     return 1;
     return 0;
}


int main ( ) {
     int m;
     scanf("%d", &m);
     Book books[m];

     for ( int k = 0; k < m; k++ )
          scanf("%s%s", &books[k].author, &books[k].name);

     qsort( books, m, sizeof(Book), increasing);

     //for ( int k = 0; k < m; k++ )
          //printf("%s %s\n", books[k].author, books[k].name );

     int num;
     char name[max_len];
     for ( int k = 0; k < m; k++ ) {
          scanf("%s%d", &name, &num);

          for ( int i = 0; i < m; i++ ) {
               if ( strcmp( name, books[i].name ) == 0 ) {
                    books[i].num = num;
                    break;
               }
          }
     }

     char prev[max_len];
     strcpy( name, books[0].author);
     strcpy( prev, books[0].author );
     int temp = 0, max = INT_MIN;
     for ( int k = 0; k < m; k++ ) {
          if ( strcmp( prev, books[k].author ) == 0 ) {
               temp += books[k].num;
          }
          else {
               if ( temp > max ) {
                    max = temp;
                    strcpy( name, prev );
               }
               temp = books[k].num;
               strcpy( prev, books[k].author );
          }
     }

     if ( temp > max ) {
          max = temp;
          strcpy( name, prev );
     }

     printf("%s %d", name, max);

     return 0;
}
