#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

//#define ZIGZAG
#define TOPDOWN
//#define BOTTOMUP

Node *merge(Node *list[], int K) {
     Node *temp = NULL;
     int *finished = (int*) calloc(K,sizeof(int)), n, k = K;
#ifdef ZIGZAG
     int top_down = 1;
     for ( n = 0; n < K; n++ ) {
          if ( list[n] != NULL ) {
               temp = list[n];
               list[n] = list[n]->next;
               n++;
               break;
          }
          else
               finished[n]++;
     }
     Node *root = temp;
     while ( k > 1 ) {
          if ( top_down ) {
               for ( int i = n; i < K; i++ ) {
                    if ( !finished[i] ) {
                         if ( list[i] != NULL ) {
                              temp->next = list[i];
                              temp = temp->next;
                              list[i] = list[i]->next;
                         }
                         else {
                              finished[i]++;
                              k--;
                         }
                    }
               }
               top_down--;
               n = (K-1);
          }
          else {
               for ( int i = n; i >= 0; i-- ) {
                    if ( !finished[i] ) {
                         if ( list[i] != NULL ) {
                              temp->next = list[i];
                              temp = temp->next;
                              list[i] = list[i]->next;
                         }
                         else {
                              finished[i]++;
                              k--;
                         }
                    }
               }
               top_down++;
               n = 0;
          }
     }
#endif // ZIGZAG

#ifdef TOPDOWN
     for ( n = 0; n < K; n++ ) {
          if ( list[n] != NULL ) {
               temp = list[n];
               list[n] = list[n]->next;
               n++;
               break;
          }
          else
               finished[n]++;
     }
     Node *root = temp;
     while ( k > 1 ) {
          for ( int i = n; i < K; i++ ) {
               if ( !finished[i] ) {
                    if ( list[i] != NULL ) {
                         temp->next = list[i];
                         temp = temp->next;
                         list[i] = list[i]->next;
                    }
                    else {
                         finished[i]++;
                         k--;
                    }
               }
          }
          n = 0;
     }
#endif // TOPDOWN
#ifdef BOTTOMUP
     for ( n = (K-1); n >= 0; n-- ) {
          if ( list[n] != NULL ) {
               temp = list[n];
               list[n] = list[n]->next;
               n--;
               break;
          }
          else
               finished[n]++;
     }
     Node *root = temp;
     while ( k > 1 ) {
          for ( int i = n; i >= 0; i-- ) {
               if ( !finished[i] ) {
                    if ( list[i] != NULL ) {
                         temp->next = list[i];
                         temp = temp->next;
                         list[i] = list[i]->next;
                    }
                    else {
                         finished[i]++;
                         k--;
                    }
               }
          }
          n = (K-1);
     }
#endif // BOTTOMUP

     free(finished);
     return root;
}
