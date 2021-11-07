#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define length 31

typedef struct {
    int balance;
    int accountNum;
    int zipcode;
    int age;
} Account;
Account *accounts[100000];

int account_cmp ( const void *ptr1, const void *ptr2 ) {
     return (*(Account**)ptr1)->accountNum -  (*(Account**)ptr2)->accountNum;
}

int zip_cmp ( const void *ptr1, const void *ptr2 ) {
     return (*(Account**)ptr1)->zipcode -  (*(Account**)ptr2)->zipcode;
}

int age_cmp ( const void *ptr1, const void *ptr2 ) {
     return (*(Account**)ptr1)->age -  (*(Account**)ptr2)->age;
}

int main () {
     char filename_in[length];
     scanf("%s", filename_in);

     FILE *file_in = fopen( filename_in, "rb" );
     assert( file_in != NULL );

     int n = (-1);
     do {
          n++;
          accounts[n] = (Account*) malloc(sizeof(Account));
     }
     while ( fread( accounts[n], sizeof(Account), 1, file_in ) != 0 );

     qsort( accounts, n, sizeof(Account*), account_cmp );
     printf("account, age, zipcode, balance\n");
     for ( int i = 0; i < n; i++ )
          printf("%d, %d, %d, %d\n", accounts[i]->accountNum, accounts[i]->age, accounts[i]->zipcode, accounts[i]->balance);

#if defined(SORTBY) && SORTBY == ZIPCODE
     printf("zipcode, sum_balance\n");
     qsort( accounts, n, sizeof(Account*), zip_cmp );

     int pre = accounts[0]->zipcode, sum = 0;
     for ( int i = 0; i < n; i++ ) {
          if ( accounts[i]->zipcode == pre )
               sum += accounts[i]->balance;
          else {
               printf("%d, %d\n", pre, sum);
               pre = accounts[i]->zipcode;
               sum = accounts[i]->balance;
          }
     }
     printf("%d, %d", pre, sum);

#elif defined(SORTBY) && SORTBY == AGE
     printf("age, sum_balance\n");
     qsort( accounts, n, sizeof(Account*), age_cmp );

     int pre = accounts[0]->age, sum = 0;
     for ( int i = 0; i < n; i++ ) {
          if ( accounts[i]->age == pre )
               sum += accounts[i]->balance;
          else {
               printf("%d, %d\n", pre, sum);
               pre = accounts[i]->age;
               sum = accounts[i]->balance;
          }
     }
     printf("%d, %d", pre, sum);
#endif // defined

     fclose(file_in);
     return 0;
}
