#include <stdlib.h>
#include "tree.h"

Node *my_construct ( int array[], int n, int index ) {
     if ( index >= n )
          return NULL;
     Node *node = (Node*) malloc(sizeof(Node));
     node->label = array[index];
     node->left = my_construct( array, n, (2*index+1) );
     node->right = my_construct( array, n, (2*index+2) );
     return node;
}

Node *construct(int array[], int n) {
     Node *root = my_construct( array, n, 0 );
     return root;
}

