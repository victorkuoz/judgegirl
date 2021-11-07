#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

Node* mk_list(int n) {
     Node *head = (Node*) calloc(1, sizeof(Node)), *rear = head;
     head->v = sp_rand();
     head->next = NULL;

     for (int i = 1; i < n; i++) {
          Node *u = (Node*) calloc(1, sizeof(Node));
          u->v = sp_rand();
          u->next = NULL;
          rear->next = u;
          rear = rear->next;
     }
     return head;
}
void rm_list(Node *head) {
     Node *temp;
     while ( head->next != NULL ) {
          temp = head->next;
          head->next = temp->next;
          free(temp);
    }
    free(head);
    return;
}
