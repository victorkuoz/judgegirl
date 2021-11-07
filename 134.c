#include <stdio.h>
#include <stdlib.h>

typedef struct data {
     int level, value;
} Data;
typedef struct node {
     int value;
     struct node *left, *right;
} Node;

int cmp ( const void *ptr1, const void *ptr2 ) {
     Data *data1 = (Data*) ptr1;
     Data *data2 = (Data*) ptr2;
     if ( data1->level != data2->level )
          return data1->level - data2->level;
     return data1->value - data2->value;
}
int dis ( Node *cur, int value ) {
     if ( value < cur->value )
          return dis(cur->left, value) + 1;
     if ( cur->value < value )
          return dis(cur->right, value) + 1;
     return 0;      // important
}
int distance ( Node *cur, int a, int b ) {
     if ( a < cur->value && b < cur->value )
          return distance( cur->left, a, b);
     if ( a > cur->value && b > cur->value )
          return distance(cur->right, a, b);
     return dis(cur, a) + dis(cur, b);
}
Node *construct_tree ( Node *cur, Data *data) {
     if ( cur == NULL ) {
          cur = (Node*) calloc(1, sizeof(Node));
          cur->value = data->value;
     }
     else if ( data->value < cur->value )
          cur->left = construct_tree(cur->left, data);
     else
          cur->right = construct_tree(cur->right, data);
     return cur;
}

int main ( ) {
     int n, a, b;
     scanf("%d", &n);
     Node *root = NULL;
     Data *data_base = (Data*) calloc(n, sizeof(Data));

     for ( int i = 0; i < n; i++ )
          scanf("%d%d", &((data_base+i)->value), &((data_base+i)->level));
     qsort(data_base, n, sizeof(Data), cmp);
     for ( int i = 0; i < n; i++ )
          root = construct_tree(root, (data_base+i));
     free(data_base);

     scanf("%d", &n);
     for ( int i = 0; i < n; i++ ) {
          scanf("%d%d", &a, &b);
          printf("%d\n", distance(root, a, b));
     }
     return 0;
}
