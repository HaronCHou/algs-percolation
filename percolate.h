#ifndef _PERCOLATE_H_
#define _PERCOLATE_H_

struct percolation;
typedef struct percolation *Perco;

/* initialize a percolation model */
Perco perco_init(int n);

/* open site of position(x, y) in percolation model. 
 * Position (0,0) is on the topleft */
int perco_open(Perco pl, int x, int y);

/* return true if (x,y) site is opened */
int is_open(Perco pl, int x, int y);

/* return true if (x,y) site is full */
int is_full(Perco pl, int x, int y);

/* return true if the model is percolated */
int is_percolated(Perco pl);

/* end the percolation model, must be called 
 * after you are done with the model */
void perco_end(Perco pl);

#endif
