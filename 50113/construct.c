#include <stdio.h>
#include <stdlib.h>
#include "construct.h"
#define empty (-1)

Node *Ternary_search_tree ( Node *node, int n ) {
     if ( node == NULL ) {
          node = (Node*) malloc(sizeof(Node));
          node->small = empty;
          node->large = n;
          node->left = node->right = NULL;
     }
     else if ( node->small == empty ) {
          if ( n < node->large )
               node->small = n;
          else {
               node->small = node->large;
               node->large = n;
          }
     }

     else if ( n < node->small )
          node->left = Ternary_search_tree( node->left, n );
     else if ( n > node->large )
          node->right = Ternary_search_tree( node->right, n );
     else //( n > node->small && n < node->large )
          node->mid = Ternary_search_tree( node->mid, n );
     return node;
}

Node*ConstructTree(int sequence[],int N) {
     Node *root = NULL;
     for ( int k = 0; k < N; k++ )
          root = Ternary_search_tree( root, sequence[k] );
     return root;
}
