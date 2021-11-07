#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"

struct Hangman {
     char *ans, *output;
     int len, g, G, *flag, win;
};
typedef struct Hangman Hangman;

Hangman* newGame(char *answer, int G) {
     Hangman *new = (Hangman*) malloc(sizeof(Hangman));
     int len = strlen(answer);
     new->ans = (char*) malloc((len+1)*sizeof(int));
     strcpy( new->ans, answer );
     new->output = (char*) malloc((len+1)*sizeof(int));
     for ( int i = 0; i < len; i++ )
          new->output[i] = '*';
     new->output[len] = '\0';
     new->len = len;
     new->g = 0;
     new->G = G;
     new->flag = (int*) calloc(26, sizeof(int));
     for ( int i = 0; i < len; i++ ) {
          int index = answer[i] - 'a';
          new->flag[index] = 1;
     }
     new->win = 0;
     return new;
}
int guess(Hangman* hangman, char ch) {
     int index = ch - 'a';
     if ( hangman->flag[index] == 0 ) {
          hangman->g++;
          if ( hangman->g >= hangman->G )
               return (-1);
          return 0;
     }
     else if ( hangman->flag[index] == 1 ) {
          hangman->flag[index] = 2;
          for ( int i = 0; i < hangman->len; i++ ) {
               if ( hangman->ans[i] == ch )
                    hangman->output[i] = ch;
          }
          hangman->win = 1;
          for ( int i = 0; i < 26; i++ )
               if ( hangman->flag[i] == 1 ) {
                    hangman->win = 0;
                    break;
               }
     }
     return 1;
}
void printStatus(Hangman* hangman) {
     printf("%s\n", hangman->output);
}
int solved(Hangman* hangman) {
     return hangman->win;
}
