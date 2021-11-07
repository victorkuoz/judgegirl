#include "memory.h"

void initMemory(Memory *memory, int length) {
     memory->next = (Interval*) malloc(sizeof(Interval));

     memory->next->start = 0;
     memory->size = memory->next->length = length;
     memory->next->next = NULL;
     return;
}
void printMemory(Memory *memory) {
     Interval *ptr = memory->next;
     printf("==========\n");
     while ( ptr != NULL ) {
               printf("start %d, length %d\n", ptr->start, ptr->length);
          ptr = ptr->next;
     }
     return;
}
void allocateMemory(Memory *memory, int start, int length) {
     if ( length == 0 || start < 0 || start + length > memory->size )
          return;
     Interval *ptr, *temp;
     if ( memory->next != NULL && start >= memory->next->start && start <= memory->next->start + memory->next->length ) {
          if ( start == memory->next->start && length == memory->next->length ) {
              temp = memory->next->next;
              free(memory->next);
              memory->next = temp;
          }
          else if ( start == memory->next->start ) {
               memory->next->start = start + length;
               memory->next->length -= length;
          }
          else if ( start + length == memory->next->start + memory->next->length )
               memory->next->length -=length;
          else {
               Interval *add = (Interval*) malloc(sizeof(Interval));
               add->start = start + length;
               add->length = memory->next->length - ( start - memory->next->start ) - length;
               add->next = memory->next->next;
               memory->next->length = start - memory->next->start;
               memory->next->next = add;
          }
          return;
     }
     ptr = memory->next;
     while ( ptr != NULL ) {
          if ( ptr->next != NULL && ptr->next->start <= start && start + length <= ptr->next->start + ptr->next->length ) {
               if ( ptr->next->start == start && start + length == ptr->next->start + ptr->next->length ) {
                    temp = ptr->next->next;
                    free(ptr->next);
                    ptr->next = temp;
               }
               else if ( ptr->next->start == start ) {
                    ptr->next->start = start + length;
                    ptr->next->length -= length;
               }
               else if ( start + length == ptr->next->start + ptr->next->length )
                    ptr->next->length -= length;
               else {
                    Interval *add = malloc(sizeof(Interval));
                    add->start = start + length;
                    add->length = ptr->next->length - ( add->start - ptr->next->start );
                    add->next = ptr->next->next;

                    ptr->next->length = start - ptr->next->start;
                    ptr->next->next = add;
               }
               return;
          }
          else
               ptr = ptr->next;
     }
     return;
}
void freeMemory(Memory *memory, int start, int length){
     if ( length < 0 || start < 0 || ( start + length ) > memory->size )
          return;
     if ( memory->next == NULL ) {
          Interval *add = (Interval*) malloc(sizeof(Interval));
          add->start = start;
          add->length = length;
          add->next = NULL;
          memory->next = add;
          return;
     }
     if ( start + length == memory->next->start ) {
          memory->next->start = start;
          memory->next->length += length;
          return;
     }
     else if ( start + length < memory->next->start ) {
          Interval *add = (Interval*) malloc(sizeof(Interval));
          add->start = start;
          add->length = length;
          add->next = memory->next;
          memory->next = add;
          return;
     }

     Interval *ptr = memory->next, *temp;
     while ( ptr != NULL ) {
          if ( ptr->next == NULL ) {
               if ( ptr->start + ptr->length == start )
                    ptr->length += length;
               else if ( ptr->start + ptr->length < start ) {
                    Interval *add = (Interval*) malloc(sizeof(Interval));
                    add->start = start;
                    add->length = length;
                    add->next = NULL;
                    ptr->next = add;
               }
               return;
          }

          if ( ptr->start + ptr->length <= start && start + length <= ptr->next->start ) {
               if ( ptr->start + ptr->length == start && start + length == ptr->next->start ) {
                    ptr->length += ( length + ptr->next->length );
                    temp = ptr->next->next;
                    free(ptr->next);
                    ptr->next = temp;
               }
               else if ( ptr->start + ptr->length == start )
                    ptr->length += length;
               else if ( start + length == ptr->next->start ) {
                    ptr->next->start = start;
                    ptr->next->length += length;
               }
               else {
                    Interval *add = (Interval*) malloc(sizeof(Interval));
                    add->start = start;
                    add->length = length;
                    add->next = ptr->next;
                    ptr->next = add;
               }
               return;
          }
          ptr = ptr->next;
     }
     return;
}
