#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "percolate.h"

int main(int argc, const char *argv[])
{
    /* read from backwash.txt */
    int     n, p, q;
    Perco   pl;

    /* use backwash.txt to test whether percolation works */
#if 0
    FILE*   fp;

    fp = fopen("backwash.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    fscanf(fp, "%d", &n);
    printf("n = %d\n", n);

    pl = perco_init(n);
    while (fscanf(fp, "%d %d", &p, &q) != EOF) {
        //printf("p = %d, q = %d\n", p, q);
        perco_open(pl, p, q);
    }
    printf("Model percolates? %s\n", is_percolated(pl) ? "yes" : "no");
    perco_end(pl);
#endif

    /* test quick-union efficiency */
#if 1
    clock_t ts, te;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    printf("n = %d\n", n);

    srand(time(NULL));

    ts = clock();

    pl = perco_init(n);
    do {
        p = rand() % n + 1;
        q = rand() % n + 1;
        if (is_open(pl, p, q))
            continue;
        //printf("p = %d, q = %d\n", p, q);
        perco_open(pl, p, q);
    } while (!is_percolated(pl));
    perco_end(pl);

    te = clock();
    printf("Time elasped: %f\n", (double) (te - ts) / CLOCKS_PER_SEC);
#endif
    
    return 0;
}
