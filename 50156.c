#include <stdio.h>
#include <stdlib.h>
#define no_discount 912
#define a_method 1105
#define b_method 0121
typedef struct{
     int discount, price;
     double rate;
} Data;
void initialize(Data *data, int flag, int price, int v, int w, int x, int y, int z){
     if ( flag == a_method )
          data->discount = ( price%2 == 0 ) ? w : v;
     else if ( flag == b_method )
          data->discount = ( price%3 == 0 ) ? x : ( price%3 == 1 ) ? y : z;
     else
          data->discount = 0;
     data->price = price;
     data->rate = (double)data->discount/(double)data->price;
     return;
}
int decreasing_order(const void *ptr_1, const void *ptr_2){
     Data *data_1 = (Data*)ptr_1;
     Data *data_2 = (Data*)ptr_2;

     if ( data_1->rate < data_2->rate )
          return 1;
     if ( data_1->rate > data_2->rate )
          return (-1);
     if ( data_1->price < data_2->price )
          return (-1);
     if ( data_1->price > data_2->price )
          return 1;
     return 0;
}

int main (){
     int a, b, v, w, x, y, z;
     scanf("%d%d%d%d%d%d%d", &a, &b, &v, &w, &x, &y, &z);

     Data datas[6];
     initialize(&datas[0], no_discount, 1, v, w, x, y, z);
     initialize(&datas[1], a_method, a, v, w, x, y, z);
     initialize(&datas[2], a_method, (a+1), v, w, x, y, z);
     initialize(&datas[3], b_method, b, v, w, x, y, z);
     initialize(&datas[4], b_method, (b+1), v, w, x, y, z);
     initialize(&datas[5], b_method, (b+2), v, w, x, y, z);
     qsort(datas, 6, sizeof(Data), decreasing_order);
     printf("%d", datas[0].price);
     return 0;
}
