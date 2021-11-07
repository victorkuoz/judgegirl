#include <stdio.h>

typedef struct {
    int b, e, c, r;
} Attack;

int decide_damage ( int R, int normal, Attack attacks[] ) {
     int type, max_damage = (-1);
     for ( int k = 0; k < 3; k++ ) {
          int r = attacks[k].r, b = attacks[k].b, c = attacks[k].c, e = attacks[k].e;

          if ( r == (-1) ) {
               if ( R <= c && b > max_damage )
                    { type = k; max_damage = b; }
               else if ( R > c && b + ( R - c )*e > max_damage )
                    { type = k; max_damage = b + ( R - c )*e; }
          }
          else if ( R - r >= c && b + ( R - r - c )*e > max_damage )
               { type = k; max_damage = b + ( R - r - c )*e; }
     }

     if ( normal > max_damage )
          return normal;
     attacks[type].r = R;
     return max_damage;
}

int main () {
     int R, H, g, normal;
     Attack attacks[3];

     scanf("%d%d%d", &R, &H, &g);
     for ( int k = 0; k < 3; k++ )
          scanf("%d%d%d", &attacks[k].b, &attacks[k].e, &attacks[k].c);
     scanf("%d", &normal);

     int cur_H = H;
     attacks[0].r = attacks[1].r = attacks[2].r = (-1);

     for ( int r = 0; r < R; r++ ){
          cur_H -= decide_damage( r, normal, attacks );
          printf("%d ", cur_H);

          if ( cur_H <= 0 )   return 0;
          if ( cur_H + g >= H )     cur_H = H;
          else      cur_H += g;
     }
     return 0;
}
