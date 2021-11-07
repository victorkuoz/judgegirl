#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s_len (100001*2)
#define cmd_len 21

char string[s_len], temp[s_len];

int main ( ) {
     int table[26];
     for ( int i = 0; i < 26; i++ )
          table[i] = i;

     char string[s_len];
     scanf("%s", &string);

     char cmd[cmd_len], s1[2], s2[2];
     while ( scanf("%s", &cmd) != EOF ) {
          if ( !strcmp( cmd, "end" ) ) {
               printf("%s", string);
               return 0;
          }
          else if ( !strcmp( cmd, "replace" ) ) {
               scanf("%s%s", &s1, &s2);
               int len  = strlen(string);
               for ( int i = 0; i < len; i++ )
                    if ( string[i] == s1[0] )
                         string[i] = s2[0];
          }
          else if ( !strcmp( cmd, "remove" ) ) {
               scanf("%s", &s1);
               int len = strlen(string);
               int index = 0;
               for ( int i = 0; i < len; i++ ) {
                    if ( string[i] != s1[0] ) {
                         string[index] = string[i];
                         index++;
                    }
               }
               string[index] = '\0';
          }
          else if ( strcmp( cmd, "addhead" ) == 0 ) {
               char add[2];
               scanf("%s", &add);
               strcpy( temp, add );
               strcat( temp, string );
               strcpy( string, temp );
          }
          else if ( strcmp( cmd, "addtail" ) == 0 ) {
               scanf("%s", &s1);
               strcat( string, s1);
          }
          else {
               printf("invalid command %s", cmd);
               return 0;
          }
     }
     return 0;
}
