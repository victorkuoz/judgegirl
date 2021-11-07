#include <stdio.h>
#define max 3

int main (){
     int k, pokemon, prime = (-1), deputy = (-1), teams[max] = {0}, output = 0;

     scanf("%d", &k);
     while( scanf("%d", &pokemon) != EOF ){
          teams[pokemon%3]++;

          if ( pokemon >= prime ){
               deputy = prime;
               prime = pokemon;
          }
          else if ( pokemon > deputy )
               deputy = pokemon;

          if ( teams[0] >= k && teams[1] >= k && teams[2] >= k ){
               output += deputy;
               teams[0] = teams[1] = teams[2] = 0;
               prime = deputy = (-1);
          }
     }

     if ( !teams[0] && !teams[1] && !teams[2] )
          printf("%d", output);
     else if ( deputy == (-1) )
          printf("%d", output + prime);
     else
          printf("%d", output + deputy);
     return 0;
}
