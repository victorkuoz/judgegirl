#include "tct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_tree ( Directory *fs, int level , int *mark ) {
     if ( fs != NULL ) {
          printf(" ");
          for ( int i = 0; i <= level; i++ ) {
               if ( mark[i] )
                    printf("  |");
               else
                    printf("   ");
          }
          printf("\n ");
          for ( int i = 0; i < level; i++ ) {
               if ( mark[i] )
                    printf("  |");
               else
                    printf("   ");
          }
          printf("  ");
          printf("+- %s\n", fs->name);

          if ( fs->childDir != NULL )
               mark[level+1] = 1;
          if ( fs->silbingDir == NULL )
               mark[level] = 0;
          print_tree(fs->childDir, level+1, mark);
          mark[level+1] = 0;
          print_tree(fs->silbingDir, level, mark);
     }
     return;
}
void tree(Directory *fs) {
     int *mark = (int*) calloc(1001, sizeof(int));
     printf("+- %s\n", fs->name);
     if ( fs->childDir != NULL )
          mark[0] = 1;
     print_tree(fs->childDir, 0, mark);
     return;
}

Directory* cd(Directory *fs, char path[]) {
     Directory *dir = fs;
     char *head = path, *deli = strchr(head, '/');

     while ( true ) {
          if ( deli != NULL )
               deli[0] = '\0';
          dir = dir->childDir;
          while ( strcmp(dir->name, head) != 0 )
               dir = dir->silbingDir;

          if ( deli == NULL )
               break;
          head = (++deli);
          deli = strchr(head, '/');
     }
     return dir;
}
