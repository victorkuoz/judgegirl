#ifndef PANGFENG_H
#define PANGFENG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_student 256

typedef struct student {
     char *name;
     int *score;
} Student;
typedef struct Examtable {
     int dim_k, dim_n;
     Student *students;
} ExamTable;

void init(ExamTable *self, int n);
void addrow(ExamTable *self, char *name, int score[]);
void print(ExamTable *self, int order[]);

#endif
