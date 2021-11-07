#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct {
     int n, start, *data;
} ARRAY;

int increasing ( const void *ptr1, const void *ptr2 );
void init(ARRAY *a,  int left, int right);
int set(ARRAY *a, int index, int value);
int get(ARRAY *a, int index);
void print(ARRAY *a);
void sort(ARRAY *a);

#endif
