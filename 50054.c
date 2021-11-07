#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 101
typedef struct table {
     char value[length];
     struct table *next;
} Table;

int main () {
     int s, n, q;
     scanf("%d%d%d", &s, &n, &q);
     Table *temp, *tables[s];
     for ( int i = 0; i < s; i++ )
          tables[i] = NULL;

     char value[length];
     for ( int i = 0; i < n; i++ ) {
          scanf("%s", &value);
          int index = 0, len = strlen(value);
          for ( int j = 0; j < len; j++ ) {
               if ( value[j] >= '0' && value[j] <= '9' )
                    index += ( value[j] - '0' );
               else
                    index += (value[j]);
          }
          index %= s;
          if ( tables[index] == NULL ) {
               tables[index] = (Table*) malloc(sizeof(Table));
               strcpy( tables[index]->value, value );
               tables[index]->next = NULL;
          }
          else {
               temp = tables[index];
               while ( temp->next != NULL ) {
                    temp = temp->next;
               }
               temp->next = (Table*) malloc(sizeof(Table));
               strcpy( temp->next->value, value );
               temp->next->next = NULL;
          }
     }

     for ( int i = 0; i < q; i++ ) {
          int flag = 0;
          scanf("%s", &value);
          int index = 0, len = strlen(value);
          for ( int j = 0; j < len; j++ ) {
               if ( value[j] >= '0' && value[j] <= '9' )
                    index += ( value[j] - '0' );
               else
                    index += (value[j]);
          }
          index %= s;
          temp = tables[index];
          while ( temp != NULL ) {
               if ( strcmp( temp->value, value ) == 0 ) {
                    flag = 1;
                    printf("%d\n", index);
                    break;
               }
               temp = temp->next;
          }
          if ( !flag )
               printf("-1\n");
     }

     return 0;
}
