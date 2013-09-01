#include "quick-union.h"
#include <stdlib.h>
#include <stdio.h>

struct qu {
    int*    qu_array;
    int     count;
};

QuickUnion qu_init(int n)
{
    int i;
    QuickUnion qu;
    
    qu = malloc(sizeof(struct qu));
    if (qu == NULL)
        return NULL;

    qu->qu_array = malloc(sizeof(int) * n);
    if (qu->qu_array == NULL)
        return NULL;
    
    qu->count = n;
    for (i = 0; i < qu->count; i++)
        qu->qu_array[i] = i;

    return qu;
}

static int root(QuickUnion qu, int i)
{
    while (qu->qu_array[i] != i)
        i = qu->qu_array[i];
    return i;
}

int qu_union(QuickUnion qu, int p, int q)
{
    int proot, qroot;

    if (p < 0 || p >= qu->count ||
            q < 0 || q >= qu->count)
        return -1;

    proot = root(qu, p);
    qroot = root(qu, q);
    qu->qu_array[proot] = qu->qu_array[qroot];
    return 0;
}

int qu_connected(QuickUnion qu, int p, int q)
{
#if 0
    int i;
    for (i = 0; i < qu->count; i++) {
        printf("%3d ", qu->qu_array[i]);
        if (i % 20 == 0)
            putchar('\n');
    }
    putchar('\n');
#endif
    return root(qu, p) == root(qu, q);
}

void qu_end(QuickUnion qu)
{
    if (!qu)
        return;

    if (qu->qu_array)
        free(qu->qu_array);
    free(qu);
}


