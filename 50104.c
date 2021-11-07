#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_len 41

typedef struct member {
     char name[max_len];
     struct member *left, *right;
} Member;
typedef struct club{
     char name[max_len];
     Member *leader;
     struct club *left, *right;
} Club;

Member *building_member ( Member *node, char *member ) {
     if ( node == NULL ) {
          node = (Member*) malloc(sizeof(Member));
          strcpy( node->name, member );
          node->left = node->right = NULL;
          return node;
     }
     int flag = strcmp( member, node->name);
     if ( flag < 0 )
          node->left = building_member( node->left, member );
     else if ( flag > 0)
          node->right = building_member( node->right, member );
     return node;
}
Club *building_club ( Club *node, int type, char *member, char *club ) {
     if ( !type ) {
          if ( node == NULL ) {
               node = (Club*) malloc(sizeof(Club));
               strcpy( node->name, club );
               node->left = node->right = NULL;
               node->leader = (Member*) malloc(sizeof(Member));
               strcpy( node->leader->name, member) ;
               node->leader->left = node->leader->right = NULL;
               return node;
          }
          else if ( strcmp( club, node->name ) < 0 )
               node->left = building_club( node->left, type, member, club );
          else
               node->right = building_club( node->right, type, member, club );
          return node;
     }

     if ( type ) {
          int flag = strcmp( club, node->name );
          if ( flag == 0 )
               node->leader = building_member( node->leader, member);
          else if ( flag < 0 )
               node->left = building_club( node->left, type, member, club );
          else
               node->right = building_club( node->right, type, member, club );
          return node;
     }
}

void query_member ( Member *node, char *member ) {
     if ( node == NULL )
          printf("0\n");
     else {
          int flag = strcmp( member, node->name );
          if ( flag < 0 )
               query_member( node->left, member );
          else if ( flag > 0 )
               query_member( node->right, member );
          else
               printf("1\n");
     }
     return;
}
void query_club ( Club *node, int type, char *member, char *club ) {
     if ( node == NULL ) {
          if ( !type )
               printf("None\n");
          else
               printf("-1\n");
          return;
     }

     int flag = strcmp( club, node->name );
     if ( !type ) {
          if ( flag < 0 )
               query_club( node->left, type, member, club );
          else if ( flag > 0 )
               query_club( node->right, type, member, club );
          else
               printf("%s\n", node->leader->name);
     }
     else {
          if ( flag < 0 )
               query_club( node->left, type, member, club );
          else if ( flag > 0 )
               query_club( node->right, type, member, club );
          else
               query_member( node->leader, member );
     }
     return;
}


int main ( ) {
     int n, type;
     char member[max_len], club[max_len];
     scanf("%d", &n);
     Club *clubs = NULL;

     for ( int i = 0; i < n; i++ ) {
          scanf("%d%s%s", &type, &member, &club);
          clubs = building_club( clubs, type, member, club);
     }

     scanf("%d", &n);
     for ( int i = 0; i < n; i++ ) {
          scanf("%d", &type);
          if ( !type )
               scanf("%s", &club);
          else
               scanf("%s%s", &member, &club);
          query_club( clubs, type, member, club );
     }
     return 0;
}
