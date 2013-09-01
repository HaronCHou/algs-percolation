
#ifndef _QUICK_FIND_H_
#define _QUICK_FIND_H_

struct qf;
typedef struct qf* QuickFind;

/* Initialize the data structure, must be called first */
QuickFind qf_init(int n);

/* connect two components to which p and q belong */
int qf_union(QuickFind qf, int p, int q);

/* check whether p and q elements are connected */
int qf_connected(QuickFind qf, int p, int q);

/* must be called after you are done with the data structure */
void qf_end(QuickFind qf);

#endif
