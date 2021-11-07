#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 30
#define len (7+1)

typedef struct {
     char string[len];
} Ans;

int valid_1( char *x ) {
     for ( int i = 0; i < (len-2); i++ )
          if ( !isalnum( x[i] ) )
               return 0;
     return 1;
}
int valid_2 ( char *x ) {
     int sum = 0;
     for ( int i = 0; i < (len-2); i++ )
          if ( isdigit( x[i] ) )
               sum += ( x[i] - '0' );
     if ( !(sum%7) )   return 0;
     return 1;
}
int valid_3 ( char *x ) {
     for ( int i = 0; i < (len-2) ; i++ ) {
          int flag = 1;
          for ( int j = (i+1); j < (len-2); j++ )
               if ( x[i] == x[j] )
                    flag++;
          if ( flag > 2 )
               return 0;
     }
     return 1;
}
int valid_4 ( int type, char *x ) {
     for ( int i = 0; i < (len-3); i++ )
          if ( i != (type-1) && x[i] == '4' && x[i+1] == '4' )
               return 0;
     return 1;
}
int ans_cmp ( const void *ptr1, const void *ptr2 ) {
     Ans *ans1 = (Ans*) ptr1;
     Ans *ans2 = (Ans*) ptr2;

     if ( ans1->string[2] == '-' && ans2->string[3] == '-' )
          return (-1);
     if ( ans1->string[3] == '-' && ans2->string[2] == '-' )
          return 1;
     return strcmp( ans1->string, ans2->string );
}

int main ( ) {
     int n, type, index = 0;
     scanf("%d", &n);

     Ans ans[N];
     char string[len], x[len-2];
     for ( int i = 0; i < n; i++ ) {
          scanf("%s", &string);
          int count = 0;
          for ( int i = 0; i < (len-1); i++ ) {
               if ( string[i] != '-' ) {
                    x[count] = string[i];
                    count++;
               }
               else
                    type = i;
          }
          if ( count != 6 || !( type == 2 || type == 3 ) )   continue;
          if ( valid_1(x) && valid_2(x) && valid_3(x) && valid_4( type, x ) ) {
               strcpy( ans[index].string, string );
               index++;
          }
     }


     qsort( ans, index, sizeof(Ans), ans_cmp );
     for ( int i = 0; i < index; i ++ )
          printf("%s\n", ans[i].string);

     return 0;
}
