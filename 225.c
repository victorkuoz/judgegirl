#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define swap(x,y) { unsigned int temp = x; x = y; y = temp; }
typedef struct person{
    unsigned int id;
    char name[32];
} Person;
typedef struct friends {
    unsigned id1;
    unsigned id2;
} Friend;

int main () {
     FILE *file_ptr = fopen( "friends", "rb" );
     assert( file_ptr != NULL );

     int p;
     fread( &p, 4, 1, file_ptr );
     //printf("%d\n", p);
     Person *persons = (Person*) malloc(p*sizeof(Person));
     fread( persons, sizeof(Person), p, file_ptr );
     /*for ( int i = 0; i < p; i++ )
          printf("%u %s\n", persons[i].id, persons[i].name);*/

     int f;
     fread( &f, 4, 1, file_ptr );
     //printf("%d\n", f);
     Friend *friends = (Friend*) malloc(f*sizeof(Friend));
     fread( friends, sizeof(Friend), f, file_ptr );
     for ( int i = 0; i < f; i++ ) {
          if ( friends[i].id1 > friends[i].id2 )
               swap( friends[i].id1, friends[i].id2 );
          //printf("%u %u\n", friends[i].id1, friends[i].id2);
     }


     int idx1, idx2, flag;
     char s1[32], s2[32];
     while ( scanf("%s", &s1) != EOF && strcmp( s1, "end" ) != 0 ) {
          flag = idx1 = idx2 = (-1);
          scanf("%s", &s2);
          for ( int i = 0; i < p; i++ ) {
               if ( strcmp( persons[i].name, s1 ) == 0 )
                    idx1 = persons[i].id;
               if ( strcmp( persons[i].name, s2 ) == 0 )
                    idx2 = persons[i].id;
               if ( idx1 != (-1) && idx2 != (-1) )
                    break;
          }
          if ( idx1 > idx2 )
               swap( idx1, idx2 );
          for ( int i = 0; i < f; i++ ) {
               if ( ( idx1 == friends[i].id1 && idx2 == friends[i].id2 ) ) {
                    printf("yes\n");
                    flag = 1;
                    break;
               }
          }
          if ( !(flag+1) )
               printf("no\n");
     }
     return 0;
}
