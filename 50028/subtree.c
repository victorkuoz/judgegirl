#include <stdio.h>
#include "subtree.h"

int index;
int subtrees ( Node *node, int label[], int k ) {
     if ( node == NULL )
          return 0;
     int left = subtrees( node->left, label, k );
     int right = subtrees( node->right, label, k );

     if ( node->label == k )   return 1;
     if ( left && right ) {
          label[index] = node->label;
          index++;
          return 1;
     }
     return ( left || right );
}

int getNode(Node *root, int label[], int k) {
     index = 0;
     subtrees( root, label, k );
     return index;
}
