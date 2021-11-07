#include <stdlib.h>
#include "trace.h"
void horizontal_trace ( int depth, int num_child, ChildList *child, Answer *ans );
void vertical_trace ( int depth, int num_child, Node *root, Answer *ans );


void horizontal_trace ( int depth, int num_child, ChildList *child, Answer *ans ) {
     vertical_trace( depth, 1, child->node, ans);
     if ( child->next == NULL ) {
          if ( num_child > ans->MaxBranchFactor )
               ans->MaxBranchFactor = num_child;
          return;
     }
     horizontal_trace(depth, num_child+1, child->next, ans);
     return;
}



void vertical_trace ( int depth, int num_child, Node *root, Answer *ans ) {
     if ( root->list == NULL ) {
          if ( depth > ans->Depth )
               ans->Depth = depth;
          (ans->Leaf)++;
          return;
     }

     (ans->InternalNode)++;
     horizontal_trace( depth+1, 1, root->list, ans);
     return;
}


void trace(Node *root, Answer *ans) {
     ans->InternalNode = ans->Leaf = ans->MaxBranchFactor = ans->Depth = 0;
     vertical_trace( 0, 0, root, ans );
     return;
}
