#include <stdio.h>
#include <stdlib.h>

typedef struct Interval {
     int start, length;
     struct Interval *next;
} Interval;
typedef struct {
     int size;
     Interval *next;
} Memory;

void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);
