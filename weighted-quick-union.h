
#ifndef _WEIGHTED_QUICK_UNION_H_
#define _WEIGHTED_QUICK_UNION_H_

struct qu;
typedef struct qu* QuickUnion;

/* Initialize the data structure, must be called first */
QuickUnion qu_init(int n);

/* connect two components to which p and q belong */
int qu_union(QuickUnion qu, int p, int q);

/* check whether p and q elements are connected */
int qu_connected(QuickUnion qu, int p, int q);

/* must be called after you are done with the data structure */
void qu_end(QuickUnion qu);

#endif
