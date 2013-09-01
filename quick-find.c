#include "quick-find.h"
#include <stdlib.h>
#include <stdio.h>

struct qf {
    int*    qf_array;
    int     count;
};

QuickFind qf_init(int n)
{
    int i;
    QuickFind qf;
    
    qf = malloc(sizeof(struct qf));
    if (qf == NULL)
        return NULL;

    qf->qf_array = malloc(sizeof(int) * n);
    if (qf->qf_array == NULL)
        return NULL;
    
    qf->count = n;
    for (i = 0; i < qf->count; i++)
        qf->qf_array[i] = i;

    return qf;
}

int qf_union(QuickFind qf, int p, int q)
{
    int i, pid, qid;

    if (p < 0 || p >= qf->count ||
            q < 0 || q >= qf->count)
        return -1;

    pid = qf->qf_array[p];
    qid = qf->qf_array[q];
    for (i = 0; i < qf->count; i++)
        if (qf->qf_array[i] == pid)
            qf->qf_array[i] = qid;
    return 0;
}

int qf_connected(QuickFind qf, int p, int q)
{
#if 0
    int i;
    for (i = 0; i < qf->count; i++) {
        printf("%3d ", qf->qf_array[i]);
        if (i % 20 == 0)
            putchar('\n');
    }
    putchar('\n');
#endif
    return qf->qf_array[p] == qf->qf_array[q];
}

void qf_end(QuickFind qf)
{
    if (!qf)
        return;

    if (qf->qf_array)
        free(qf->qf_array);
    free(qf);
}


