#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#define max_terms 4096

typedef struct {
     int coefficient[max_terms];
     int power;
} Polynomial;

void init(Polynomial *poly, int coefficient[], int n);
Polynomial add(Polynomial *poly1, Polynomial *poly2);
Polynomial multiply(Polynomial *poly1, Polynomial *poly2);
void print(Polynomial *poly);

#endif
