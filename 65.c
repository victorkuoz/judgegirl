#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_size 1000

char *expression, *buffer;
typedef struct variable {
     char *name;
     int value;
} Variable;

int calculate ( int size, Variable *variables ) {
     //printf("expression = %s\n", expression);
     while ( expression[0] == ')' )
          expression += 2;

     if ( '0' <= expression[0] && expression[0] <= '9' ) {      // number
          char *temp = expression;
          expression = ( strchr(expression, ' ') + 1 );
          return atoi(temp);
     }

     if ( expression[0] == '(' ) {
          char *operator = (expression + 2);
          expression += 4;
          switch ( operator[0] ) {
               case '+' :
                    return calculate(size, variables) + calculate(size, variables);
               case '-' :
                    return calculate(size, variables) - calculate(size, variables);
               case '*' :
                    return calculate(size, variables) * calculate(size, variables);
               case '/' :
                    return calculate(size, variables) / calculate(size, variables);
               default :
                    printf("error\n");
                    exit(0);
          }
     }

     char *deli = strchr(expression, ' ');
     deli[0] = '\0';
     for ( int i = 0; i < size; i++ ) {
          if ( !strcmp(expression, (variables+i)->name) ) {
               expression = (deli+1);
               return (variables+i)->value;
          }
     }
}

int main ( ) {
     int  value = 0, size = 0;
     Variable *variables = (Variable*) calloc(50, sizeof(Variable));
     expression = (char*) calloc((max_size+1), sizeof(char));
     buffer = (char*) malloc(2*sizeof(char));
     fgets(expression, max_size, stdin);

     while ( true ) {
          char *name = (char*) calloc(33, sizeof(char));
          if ( scanf("%s%s%d", name, buffer, &value) == EOF )
               break;
          //printf("%s %s %d\n", name, buffer, value);
          (variables+size)->name = name;
          (variables+size)->value = value;
          size++;
     }
     printf("%d", calculate(size, variables));
     return 0;
}
