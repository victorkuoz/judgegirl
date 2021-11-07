#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 128

typedef struct {
     char *name;
     int w;
} Ingredient;
typedef struct {
     int act, in, w;
     Ingredient *active[2], *inactive[5];
} Medicine;

void init(Medicine *medicine);
int addActive(Medicine *medicine, char *name, int weight);
int addInactive(Medicine *medicine, char *name, int weight);
void print(Medicine *medicine);
int totalWeight(Medicine *medicine);
char *maxIngredient(Medicine *medicine);
