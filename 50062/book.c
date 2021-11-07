#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

int author_compare ( const void *ptr1, const void *ptr2 ) {
     BookAuthor *data1 = (BookAuthor*) ptr1;
     BookAuthor *data2 = (BookAuthor*) ptr2;
     return strcmp ( data1->book_title, data2->book_title );
}
int selling_compare ( const void *ptr1, const void *ptr2 ) {
     BookSelling *data1 = (BookSelling*) ptr1;
     BookSelling *data2 = (BookSelling*) ptr2;
     int flag = strcmp ( data1->book_title, data2->book_title );
     if ( flag != 0 )
          return flag;
     return ( data1->date - data2->date );
}

BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]) {
     qsort( authorArr, N, sizeof(BookAuthor), author_compare );
     qsort( sellingArr, M, sizeof(BookSelling), selling_compare );
#ifdef debug
     for ( int i = 0; i < N; i++ )
          printf("%s %s\n", authorArr[i].book_title, authorArr[i].author);
     for ( int i = 0; i < M; i++ )
          printf("%s %d %d\n", sellingArr[i].book_title, sellingArr[i].date, sellingArr[i].selling);
#endif // debug
     BookInfoList *list = (BookInfoList*) malloc(sizeof(BookInfoList));
     list->num = 0;

     int start = 0, flag;
     for ( int i = 0; i < N; i++ ) {
          flag = 0;
          for ( int j = start; j < M; j++ ) {
               if ( strcmp( authorArr[i].book_title, sellingArr[j].book_title ) == 0 ) {
                    flag = 1;
                    strcpy( list->books[list->num].book_title, authorArr[i].book_title );
                    strcpy( list->books[list->num].author, authorArr[i].author );
                    list->books[list->num].date = sellingArr[j].date;
                    list->books[list->num].selling = sellingArr[j].selling;
                    (list->num)++;
               }
               else if ( flag ){
                    start = j;
                    break;
               }
          }
     }
     return *list;
}
