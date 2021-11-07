#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define max_L 11
#define max_N 50

typedef struct {
     int num;
     int lead_idx, *member_idx;
} Group;
Group *groups[3];
char string[max_N+1][max_L];
int N, L, R;

int calculate_dis ( int idx_1, int idx_2 ) {
     int sum = 0;
     for ( int i = 0; i < L; i++ )
          sum += abs( string[idx_1][i] - string[idx_2][i] );
     return sum;
}
int cmp_member ( const void *ptr_1, const void *ptr_2 ) {
     int idx_1 = *((int*)ptr_1);
     int idx_2 = *((int*)ptr_2);
     return strcmp( string[idx_1], string[idx_2] );
}
int cmp_group ( const void *ptr_1, const void *ptr_2 ) {
     Group *group_1 = *((Group**)ptr_1);
     Group *group_2 = *((Group**)ptr_2);
     return strcmp( string[group_1->lead_idx], string[group_2->lead_idx] );
}

int main ( ) {
     scanf("%d%d%d", &N, &L, &R);
     for ( int i = 0; i < N; i++ )
          scanf("%s", &string[i]);

     for ( int i = 0; i < 3; i++ ) {
          groups[i] = (Group*) malloc(sizeof(Group));
          groups[i]->member_idx = (int*) malloc(N*sizeof(int));
          groups[i]->num = 0;
          groups[i]->lead_idx = i;
     }

     for ( int r = 0; r < R; r++ ) {
          qsort( groups, 3, sizeof(Group*), cmp_group);
          for ( int i = 0; i < N; i++ ) {
                    int group, min = INT_MAX;
                    for ( int g = 0; g < 3; g++ ) {
                         int dis = calculate_dis( i, groups[g]->lead_idx );
                         if ( dis < min ) {
                              min = dis;
                              group = g;
                         }
                    }
                    groups[group]->member_idx[groups[group]->num++] = i;
          }

          for ( int g = 0; g < 3; g++ ) {
               int *vec = (int*) calloc(L,sizeof(int));
               for ( int i = 0; i < groups[g]->num; i++ ) {
                    int idx = groups[g]->member_idx[i];
                    for ( int j = 0; j < L; j++ )
                         vec[j] += (int)string[idx][j];
               }
               for ( int j = 0; j < L; j++ )
                    string[N][j] = (char)(vec[j] / (groups[g]->num));

               qsort( groups[g]->member_idx, groups[g]->num, sizeof(int), cmp_member );
               int idx, min = INT_MAX;
               for ( int i = 0; i < groups[g]->num; i++ ) {
                    int dis = calculate_dis( N, groups[g]->member_idx[i] );
                    if ( dis < min ) {
                         min = dis;
                         idx = groups[g]->member_idx[i];
                    }
               }
               groups[g]->lead_idx = idx;
               groups[g]->num = 0;
               free(vec);
          }
     }
     qsort(groups, 3, sizeof(Group*), cmp_group);
     printf("%s\n%s\n%s\n", string[groups[0]->lead_idx], string[groups[1]->lead_idx], string[groups[2]->lead_idx]);
     return 0;
}
