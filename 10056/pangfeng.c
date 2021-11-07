#include "pangfeng.h"

void init(ExamTable *self, int n) {
     self->dim_k = 0;
     self->dim_n = n;
     self->students = (Student*) calloc(max_student, sizeof(Student));
     return;
}
void addrow(ExamTable *self, char *name, int score[]) {
     int k = self->dim_k, n = self->dim_n;

     self->students[k].name = (char*) calloc(strlen(name)+1, sizeof(char));
     strcpy(self->students[k].name, name);
     self->students[k].score = (int*) calloc(n, sizeof(int));

     for ( int i = 0; i < n; i++ )
          self->students[k].score[i] = score[i];
     self->dim_k++;
     return;
}
int cmp_n, cmp_order[128];
int cmp ( const void *ptr1, const void *ptr2 ) {
     Student *student1 = (Student*) ptr1;
     Student *student2 = (Student*) ptr2;

     for ( int i = 0; i < cmp_n; i++ ) {
          int x = student1->score[cmp_order[i]], y = student2->score[cmp_order[i]];
          if ( x > y )
               return (-1);
          if ( x < y )
               return (1);
     }
     return strcmp(student1->name, student2->name);
}

void print(ExamTable *self, int order[]) {
     cmp_n = self->dim_n;
     for ( int i = 0; i < cmp_n; i++ )
          cmp_order[i] = order[i];
     qsort(self->students, self->dim_k, sizeof(Student), cmp);

     puts("----- table begin -----");
     for ( int i = 0; i < self->dim_k; i++ ) {
          printf("%s, ", self->students[i].name);
          for ( int j = 0; j < cmp_n; j++ )
               printf("%d%s", self->students[i].score[j], ( j != cmp_n - 1 ) ? ", " : "\n" );
     }
     puts("----- end         -----");
     return;
}
