#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define swap(a,b) { int t = a; a = b; b = t; }

void row_swapping ( int *r1, int *r2, int c, int M ) {
    for ( int i = c; i <= M; i++ )
        swap(r1[i],r2[i]);
    return;
}

int *row_reduction ( int *r, int c, int M ) {
    for ( int i = c; i <= M; i++ )
        r[i] /= r[c];
    return r;
}

int *row_addition ( int *r1, int *r2, int c, int M ) {
    for ( int i = c; i <= M; i++ )
        r1[i] -= (r1[c]*r2[i]);
    return r1;
}

double **initialize( int N, int M , char *ques ) {
    double **matrix = (double**) calloc(N, sizeof(double*));
    for ( int i = 0; i < N; i++ )
        matrix[i] = (double*) calloc((M+1), sizeof(double));
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j <= M; j++ )
            scanf("%lf", &matrix[i][j]);
    char c;
    for ( int i = 0; i < M; i++ )
        scanf("%c%c", &ques[i], &c);
    return matrix;
}


int main () {
    int N, M;
    while ( scanf("%d%d", &N, &M) != EOF ) {
        int rank = 0;
        char *ques = (char*) calloc(M, sizeof(char));
        double **matrix =  initialize(N, M, ques);

        for ( int c = 0; c < M; c++ ) {
            int r = rank;
            for ( ; r < N && matrix[r][c] == 0; r++ );
            
            if ( r < N ) {
                row_swapping(matrix[rank], matrix[r], c, M);
                
                if ( matrix[rank][c] != 1 )
                    matrix[rank] = row_reduction(matrix[rank], c, M);
            
                for ( int i = (r+1); i < N; i++ )
                    if ( matrix[i][c] != 0)
                        matrix[i] = row_addition(matrix[i], matrix[r], c, M);
                for ( int i = 0; i < N; i++ )
                    for ( int j = 0; j <= M; j++ )
                        printf("%d%c", matrix[i][j], (j!=M) ? ' ' : '\n');
                printf("\n");
                
                rank++;
            }
        }

        //for ( int i = 0; i < N; i++ )
            //for ( int j = 0; j <= M; j++ )
                //printf("%d%c", matrix[i][j], (j!=M) ? ' ' : '\n');

       free(ques);
       free(matrix);
    }
    return 0;
}