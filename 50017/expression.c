#include "expression.h"

bool valid = true;
int expression(char *string) {
     if ( !valid )
          return INT_MIN;

     if ( string[0] == '-' ) {
          int x = expression(++string);
          if ( x != INT_MIN )
               return (-x);
          valid = false;
          return INT_MIN;
     }

     if ( '0' <= string[0] && string[0] <= '9' ) {
          int x = ( atoi(string) < 10 ) ? atoi(string) : INT_MIN;
          if ( x == INT_MIN )
               valid = false;
          return x;
     }

     if ( string[0] == '(' ) {
          int exp_1 = expression(++string);
          if ( exp_1 == INT_MIN )      // invalid
               return INT_MIN;

          int count = 0;
          bool digital = false;
          char *operator = NULL;
          while ( operator == NULL ) {
               if ( string[0] == '(' )
                    count++;
               else if ( string[0] == ')' )
                    count--;
               else if ( '0' <= string[0] && string[0] <= '9' )
                    digital = true;
               else if ( string[0] == '+' || string[0] == '-' || string[0] == '*' || string[0] == '/' ) {
                    if ( !count && digital )
                         operator = string;
               }
               else if ( string[0] == '\0' ) {
                    valid = false;
                    return INT_MIN;
               }
               string++;
          }

          int exp_2 = expression(string);
          if ( exp_2 == INT_MIN )      // invalid
               return INT_MIN;

          switch ( operator[0] ) {
               case '+' :
                    return (exp_1 + exp_2);
               case '-' :
                    return (exp_1 - exp_2);
               case '*' :
                    return (exp_1 * exp_2);
               case '/' :
                    if ( exp_2 != 0 )
                         return (exp_1 / exp_2);
                    valid = false;
                    return INT_MIN;
               default :
                    printf("error");
                    exit(0);
          }
     }
     printf("error");
     exit(0);
}
