#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define length 12

typedef struct {
     char name[length];
     int money;
} Data;
Data *datas[1024];

int datas_cmp ( const void *ptr1, const void *ptr2 ) {
     int flag = ( (*(Data**)ptr1)->money - (*(Data**)ptr2)->money );
     if ( flag != 0 )
          return flag;
     return strcmp( (*(Data**)ptr1)->name, (*(Data**)ptr2)->name);
}

int main ( int argc, char *argv[]) {
     int n = (-1);
     FILE *file_ptr = fopen( argv[1], "rb" );
     assert( file_ptr != NULL );

     do {
          n++;
          datas[n] = (Data*) malloc(sizeof(Data));
     }
     while ( fread( datas[n], sizeof(Data), 1, file_ptr ) != 0 );
     fclose(file_ptr);
     /*for ( int i = 0; i < n; i++ )
          printf("%s %d\n", datas[i]->name, datas[i]->money);*/
     qsort( datas, n, sizeof(Data*), datas_cmp );
     /*for ( int i = 0; i < n; i++ )
          printf("%s %d\n", datas[i]->name, datas[i]->money);*/
     unsigned long long lower = 0, upper = 999;
     int count = 0, max = datas[n-1]->money, idx = (-1);
     for ( int i = 0; i < n; i++ ) {
          if ( datas[i]->money == max && idx == (-1) )
               idx = i;
          if ( datas[i]->money > upper ) {
               if ( count != 0 ) {
                    printf("%d\n", count);
                    count = 0;
               }
               lower = (datas[i]->money/1000)*1000;
               upper = (datas[i]->money/1000)*1000 + 999;
          }
          count++;
     }
     if ( count != 0 )
          printf("%d\n", count);
     printf("%s\n%s\n", datas[0]->name, datas[idx]->name);

     if ( n%2 )
          printf("%d", datas[n/2]->money);
     else {
          unsigned long long a = datas[n/2]->money;
          unsigned long long b = datas[n/2-1]->money;
          unsigned long long ave = (a+b)/2;
          printf("%llu", ave);
     }
     return 0;
}
