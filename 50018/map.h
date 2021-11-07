#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#define max 1024
#define length 128

typedef struct {
     int key;
     char *value;
} Pair;
typedef struct {
     int n;
     Pair *pairs[max] ;
 } Map;

void init(Map *map);
int map(Map *map, const int key, const char *value);
int numPairs(Map *map);
void print(Map *map);
const char *getValue(Map *map, const int key);
int unmap(Map *map, int key);
int reverseMap(Map *map, const char *value, int keys[]);

