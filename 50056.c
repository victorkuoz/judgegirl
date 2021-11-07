#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max_length 51

typedef struct {
     char name[max_length];
     int amount, p;
} Material;

typedef struct {
     char name[max_length];
     char amount;
} Ingredient;

typedef struct {
     char name[max_length];
     int Q, P;
     Ingredient ingredient[100];
} Product;

int count_profit ( int n, Material material[], Product product ) {
     int quantity = INT_MAX, cost = 0;
     for ( int k = 0; k < product.Q; k++ ) {
          for ( int i = 0; i < n; i++ ) {
               if ( strcmp( product.ingredient[k].name, material[i].name) == 0 ) {
                    cost += product.ingredient[k].amount*material[i].p;
                    if ( material[i].amount/product.ingredient[k].amount < quantity )
                         quantity = material[i].amount/product.ingredient[k].amount;
               }
          }
     }
     return ( product.P - cost )*quantity;
}


int main () {
     int n, m;
     scanf("%d%d", &n, &m);
     Material material[n];
     Product products[m];

     for ( int k = 0 ; k < n; k++ )
          scanf("%s%d%d", &material[k].name, &material[k].amount, &material[k].p);
     for ( int k = 0; k < m; k++ ) {
          scanf("%s%d", &products[k].name, &products[k].Q);
          //products[k].ingredient = malloc(sizeof(Ingredient)*products[k].Q);
          for ( int i = 0; i < products[k].Q; i++ )
               scanf("%s%d", &products[k].ingredient[i].name, &products[k].ingredient[i].amount);
          scanf("%d", &products[k].P);
     }

     int max_profit = (-1);
     char product[max_length];
     for ( int k = 0; k < m; k++ ){
          int profit = count_profit( n, material, products[k]);
          if ( profit > max_profit || ( profit == max_profit && strcmp( products[k].name, product ) < 0 ) ){
               max_profit = profit;
               strcpy( product, products[k].name );
          }
     }
     printf("%s %d", product, max_profit);
     return 0;
}
