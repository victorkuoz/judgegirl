#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_w 1000000
#define max_L 101

char string[max_w];
typedef struct {
     char *string;
     int len;
} Dic;

int cmp ( char *string_a, char *string_b, int len_a, int len_b ) {
     if ( len_a == len_b ) {
          if ( strcmp( string_a, string_b ) == 0 )
               return 1;
          int flag = 0;
          for ( int i = 0; i < len_a; i++ ) {
               if ( string_a[i] != string_b[i] )
                    flag++;
               if ( flag > 1 )
                    return (-1);
          }
          return 0;
     }

     if ( strncmp( string_a, string_b, len_a ) == 0 )
          return 0;
     for ( int a = 0, b = 0; a < len_a; a++, b++ ) {
          if ( string_a[a] != string_b[b] && a == b )
               b++;
          if ( string_a[a] != string_b[b] && a != b )
               return (-1);
     }
     return 0;
}

int main ( ) {
     int idx = 0, N, *length = calloc(max_L,sizeof(int));
     scanf("%d", &N);
     Dic *dic[N];
     for ( int i = 0; i < N; i++ ) {
          scanf("%s", &string[idx]);
          dic[i] = (Dic*) malloc(sizeof(Dic));
          dic[i]->string = &string[idx];
          dic[i]->len = strlen(dic[i]->string);
          length[dic[i]->len] = 1;
          idx += ( dic[i]->len + 1 );
     }

     /*for ( int i = 0; i < N; i++ )
          printf("%s %d\n", dic[i]->string, dic[i]->len);*/

     int Q, index[N];
     scanf("%d", &Q);
     char input[max_L];
     for ( int i = 0 ; i < Q; i++ ) {
          scanf("%s", &input);
          int len = strlen(input), type = (-1), n = 0;
          if ( !length[len-1] && !length[len] && !length[len+1] ) {
               printf("!%s\n", input);
               continue;
          }
          for ( int j = 0; j < N; j++ ) {
               int flag;
               if ( dic[j]->len == len )
                    flag = cmp( dic[j]->string, input, dic[j]->len, len );
               else if ( dic[j]->len + 1 == len )
                    flag = cmp( dic[j]->string, input, dic[j]->len, len );
               else if ( len + 1 == dic[j]->len )
                    flag = cmp( input, dic[j]->string, len, dic[j]->len);
               else
                    continue;

               if ( flag == 1 ) {
                    type = flag;
                    break;
               }
               else if ( flag == 0 ) {
                    type = flag;
                    index[n] = j;
                    n++;
               }
          }

          if ( type == 1 )
               printf(">%s\n", input);
          else if ( type == 0 ) {
               printf("?");
               for ( int k = 0; k < n; k++ )
                    printf("%s%c", dic[index[k]]->string, ( k != (n-1) ) ? ' ' : '\n');
          }
          else
               printf("!%s\n", input);
     }
     return 0;
}
