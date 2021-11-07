#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    if (x < y)    return -1;
    if (x > y)    return 1;
    return 0;
}

#define MAXN 1024
#define iswap(x, y) {int t = x; x = y, y = t;}
int n, ndiv2, A[MAXN];
int used[MAXN];
int LR[2][MAXN];
int possible(int lw, int rw, int lidx, int ridx) {
    int ll = n-1, rr = ridx+1;
    for (int i = n-1; i >= 0; i--) {
        if (used[i])    continue;
        if (lidx < n)
            lw += ll * A[i], ll--, lidx++;
        else
            rw += rr * A[i], rr++, ridx++;
    }
    return lw >= rw;
}
int seesaw(int lw, int rw, int lidx, int ridx, int spos) {
    if (lw == rw && lidx == ndiv2 && ridx == ndiv2) {
        for (int i = ndiv2-1; i >= 0; i--)
            printf("%d ", LR[0][i]);
        printf("_^_");
        for (int i = 0; i < ndiv2; i++)
            printf(" %d", LR[1][i]);
        puts("");
        return 1;
    }
    if (lw > rw) {
        iswap(lw, rw);
        iswap(lidx, ridx);
        spos = !spos;
    }
    if (lidx == ndiv2)
        return 0;
    if (!possible(lw, rw, lidx, ridx))
        return 0;
    for (int i = 0, prev = INT_MIN; i < n; i++) {
        if (used[i])    continue;
        if (A[i] == prev)
            continue;
        used[i] = 1;
        LR[spos][lidx] = A[i];
        if (seesaw(lw + (lidx+1) * A[i], rw, lidx+1, ridx, spos))
            return 1;
        used[i] = 0;
        prev = A[i];
    }
    return 0;
}
int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        ndiv2 = n/2;
        qsort(A, n, sizeof(int), cmp);
        memset(used, 0, sizeof(used));
        int ret = seesaw(0, 0, 0, 0, 0);
        if (ret == 0)
            puts("N");
    }
    return 0;
}
