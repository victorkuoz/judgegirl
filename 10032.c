#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_size 501

char *buffer;
typedef struct node {
     char c;
     struct node *children[26];
} Node;

Node *trie ( Node *cur, char *string ) {
     if ( cur == NULL )
          cur = (Node*) calloc(1, sizeof(Node));
     cur->c = string[0];
//printf("cur->c = %c\n", cur->c);
     if ( 'A' <= string[1] && string[1] <= 'Z' ) {
          int index = ( string[1] - 'A' );
          cur->children[index] = trie(cur->children[index], string+1);
     }
     return cur;
}

void print_trie ( Node *cur , char *string) {
     string[0] = cur->c;
     string[1] = '\0';
     printf("%s\n", buffer);

     for ( int index = 0; index < 26; index++ ) {
          if ( cur->children[index] != NULL ) {
               print_trie(cur->children[index], string+1);
          }
     }
     return;
}


int main ( ) {
     char *head = (char*) calloc(max_size, sizeof(char));
     int length = (fread(head, sizeof(char), max_size, stdin) - 1);
     char *rear = (head + length);      // '\0'

     Node *root = (Node*) calloc(1, sizeof(Node));
     root->c = '@';
     for ( int i = 0; i < length; i++ ) {
          int index = ( head[i] - 'A' );
          //printf("index = %d\n", index);
          root->children[index] = trie(root->children[index], head+i);
     }
     //printf("length = %d\n", length);
     for ( int index = 0; index < 26; index++ ) {
          if ( root->children[index] != NULL ) {
               buffer = (char*) calloc(max_size, sizeof(char));
               print_trie(root->children[index], buffer);
               free(buffer);
          }
     }
     return 0;
}
