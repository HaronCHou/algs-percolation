#include "percolate.h"
#include "weighted-quick-union.h"
#include <stdlib.h>
#include <stdio.h>

enum { BLOCKED, OPEN, FULL };

struct percolation {
    QuickUnion  grid;           /* data structure */
    char*       site_state;     /* record the state of every site */
    int         n;              /* grid side count */
};

Perco perco_init(int n)
{
    Perco pl;
    int i;

    pl = malloc(sizeof(struct percolation));
    if (pl == NULL)
        return NULL;

    pl->n = n;
    pl->grid = qu_init(n * n + 2);
    if (pl->grid == NULL) {
        free(pl);
        return NULL;
    }
    pl->site_state = malloc(n * n + 2);
    if (pl->site_state == NULL) {
        qu_end(pl->grid);
        free(pl);
        return NULL;
    }

    for (i = 1; i <= n*n; i++)
        pl->site_state[i] = BLOCKED;
    pl->site_state[0] = pl->site_state[n*n+1] = OPEN;

    return pl;
}

static int xy_to_int(Perco pl, int x, int y)
{
    if (x <= 0 || x > pl->n ||
            y <= 0 || y > pl->n)
        return -1;

    return (x - 1) * pl->n + y;
}

int is_open(Perco pl, int x, int y)
{
    int idx = xy_to_int(pl, x, y);
    if (idx == -1)
        return -1;
    return pl->site_state[idx] == OPEN;
}

int is_full(Perco pl, int x, int y)
{
    int idx = xy_to_int(pl, x, y);
    if (idx == -1)
        return -1;
    return qu_connected(pl->grid, 0, idx);
}

int perco_open(Perco pl, int x, int y)
{
    int idx = xy_to_int(pl, x, y);
    if (idx < 0)
        return -1;

    /* TODO: a lot of operations needed here */
    pl->site_state[idx] = OPEN;
    if (x != 1 && is_open(pl, x-1, y)) 
        qu_union(pl->grid, idx, xy_to_int(pl, x-1, y));
    if (x != pl->n && is_open(pl, x+1, y))
        qu_union(pl->grid, idx, xy_to_int(pl, x+1, y));
    if (y != 1 && is_open(pl, x, y-1))
        qu_union(pl->grid, idx, xy_to_int(pl, x, y-1));
    if (y != pl->n && is_open(pl, x, y+1))
        qu_union(pl->grid, idx, xy_to_int(pl, x, y+1));

    if (idx <= pl->n) qu_union(pl->grid, 0, idx);
    if (idx >= (pl->n - 1) * (pl->n) + 1)
        qu_union(pl->grid, pl->n * pl->n + 1, idx);
    return 0;
}

int is_percolated(Perco pl)
{ 
    return qu_connected(pl->grid, 0, pl->n * pl->n + 1);
}

void perco_end(Perco pl)
{
    if (!pl)
        return;

    qu_end(pl->grid);
    if (pl->site_state)
        free(pl->site_state);
    free(pl);
}

