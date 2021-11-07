#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 4000

char *buffer;
typedef struct node {
     int value;
     struct node *left, *right;
} Node;
void HLHR ( Node *cur );
void HRHL ( Node *cur );

void HLHR ( Node *cur ) {
     if ( cur != NULL ) {
          printf("%d\n", cur->value);
          HRHL(cur->left);
          printf("%d\n", cur->value);
          HRHL(cur->right);
     }
     return;
}
void HRHL ( Node *cur ) {
     if ( cur != NULL ) {
          printf("%d\n", cur->value);
          HLHR(cur->right);
          printf("%d\n", cur->value);
          HLHR(cur->left);
     }
     return;
}
Node *construct_tree ( void ) {
     if ( '0' <= buffer[0] && buffer[0] <= '9' ) {
          Node *new = (Node*) calloc(1, sizeof(Node));
          new->value = atoi(buffer);
          buffer = strpbrk(buffer, ",)");
          return new;
     }
     if ( buffer[0] == '(' ) {
          Node *new = (Node*) calloc(1, sizeof(Node));
          buffer++;
          new->left = construct_tree();
          buffer++;
          new->right = construct_tree();
          buffer++;
          if ( new->left != NULL )
               new->value += new->left->value;
          if ( new->right != NULL )
               new->value += new->right->value;
          return new;
     }
}

int main ( ) {
     buffer = (char*) calloc(max_size + 1, sizeof(char));
     scanf("%s", buffer);
     Node *root = construct_tree();
     HLHR(root);
     return 0;
}
