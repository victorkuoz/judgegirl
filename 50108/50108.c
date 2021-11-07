#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

typedef struct {
     int index, value;
} Data;

int decreasing ( const void *ptr_1, const void *ptr_2 ) {
     Data *data_1 = (Data*)ptr_1;
     Data *data_2 = (Data*)ptr_2;

     if ( data_1->value < data_2->value )    return 1;
     if ( data_1->value > data_2->value )    return (-1);
     return 0;
}

int find_kth ( int sequence[], int N ) {
     Data *datas = (Data*) malloc( sizeof(Data)*N );
     for ( int k = 0; k < N; k++ ) {
          datas[k].value = sequence[k];
          datas[k].index = k;
     }
     qsort(datas, N, sizeof(Data), decreasing);

     int index = datas[MAXLENGTH-1].index;
     free(datas);
     return index;
}

Node* ConstructTree(int sequence[], int N) {
     Node *node = (Node*) malloc( sizeof(Node) );

     if ( N == 1 ) {
          node->left = node->right = NULL;
          node->value = sequence[N-1];
     }
     else if ( N < MAXLENGTH ) {
          node->left = ConstructTree(sequence, N-1);
          node->value = sequence[N-1];
          node->right = NULL;
     }
     return node;

     int index = find_kth(sequence, N);
     node->value = sequence[index];
     if ( index == 0 ) {
          node->left = NULL;
          node->right = ConstructTree( sequence+index+1, N-index-1 );
     }
     else if ( index == N-1 ) {
          node->left = ConstructTree(sequence, index);
          node->right = NULL;
     }
     else {
          node->left = ConstructTree(sequence, index);
          node->right = ConstructTree( sequence+index+1, N-index-1 );
     }
     return node;
}
