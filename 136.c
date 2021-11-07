#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define length (80+1)

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main ( ) {
     char filename_in[length], filename_out[length];
     scanf("%s%s", &filename_in, &filename_out);

     FILE *file_in = fopen( filename_in, "rb" ), *file_out = fopen( filename_out, "wb" );
     assert( file_in != NULL && file_out != NULL );

     Student *temp = (Student*) malloc(sizeof(Student));
     fprintf( file_out, "<table border=\"1\">\n");
     fprintf( file_out, "<tbody>\n");
     while ( fread( temp, sizeof(Student), 1, file_in) != 0 ) {
          fprintf( file_out, "<tr>\n");
          fprintf( file_out, "<td>%s</td>\n", temp->name);
          fprintf( file_out, "<td>%d</td>\n", temp->id);
          fprintf( file_out, "<td>%s</td>\n", temp->phone);
          fprintf( file_out, "<td>%f, %f, %f, %f</td>\n", temp->grade[0], temp->grade[1], temp->grade[2], temp->grade[3]);
          fprintf( file_out, "<td>%d, %d, %d</td>\n", temp->birth_year, temp->birth_month, temp->birth_day);
          fprintf( file_out, "</tr>\n");
     }
     fprintf( file_out, "</tbody>\n");
     fprintf( file_out, "</table>\n");
     fclose(file_in);
     fclose(file_out);
     return 0;
}
