#include <stdio.h>
#include "tree.h"

void traversal(Node *root, int N, int command[]) {
     int index = 0;
     Node *nodes[1000];
     nodes[index] = root;

     for ( int i = 0; i < N; i++ ) {
          switch ( command[i] ) {
               case 0 :
                    printf("%d\n", nodes[index]->label);
                    return;
               case 1 :
                    printf("%d\n", nodes[index]->label);
                    break;
               case 2 :
                    index--;
                    break;
               case 3 :
                    if ( nodes[index]->left != NULL ) {
                         nodes[index+1] = nodes[index]->left;
                         index++;
                    }
                    else {
                         printf("%d\n", nodes[index]->label);
                         return;
                    }
                    break;
               case 4 :
                    if ( nodes[index]->right != NULL ) {
                         nodes[index+1] = nodes[index]->right;
                         index++;
                    }
                    else {
                         printf("%d\n", nodes[index]->label);
                         return;
                    }
                    break;
               case 5 :
                    if ( nodes[index-1]->left != NULL && nodes[index-1]->right != NULL ) {
                         if ( nodes[index-1]->left != nodes[index] )
                              nodes[index] = nodes[index-1]->left;
                         else
                              nodes[index] = nodes[index-1]->right;
                    }
                    else {
                         printf("%d\n", nodes[index]->label);
                         return;
                    }
                    break;
               default :
                    printf("%d\n", nodes[index]->label);
                    return;
          }
     }
     return;
}
