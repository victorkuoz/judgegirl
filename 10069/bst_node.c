#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

bstNode* bstNode_getLson(bstNode *self) {
    return self->lson;
}
bstNode* bstNode_getRson(bstNode *self) {
    return self->rson;
}
void bstNode_setLson(bstNode *self, bstNode *u) {
    self->lson = u;
}
void bstNode_setRson(bstNode *self, bstNode *u) {
    self->rson = u;
}
void bstNode_print(bstNode *self) {
    printf("%d ", *(int *)(self->extra));
}

int bstNode_init(bstNode *obj) {
    obj->getLson = bstNode_getLson;
    obj->getRson = bstNode_getRson;
    obj->setLson = bstNode_setLson;
    obj->setRson = bstNode_setRson;
    obj->print = bstNode_print;
    obj->extra = (void *) malloc(sizeof(int));
    return 1;
}
void bstNode_destroy(bstNode *obj) {
    free(obj->extra);
}

Object bstNodeProto = {
    .init = bstNode_init,
    .destroy = bstNode_destroy
};

bstNode* construct ( bstNode *cur, int key ) {
     if ( cur == NULL ) {
          bstNode *new = calloc(1, sizeof(bstNode));
          new->proto = key;
          return new;
     }

}

bstNode* buildBST(int A[], int n) {
     bstNode *new;
}
