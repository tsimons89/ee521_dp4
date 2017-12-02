#ifndef SET_COVER_H
#define SET_COVER_H
#include "set.h"

int solution[1024];
int values_hist[1024];
int candidates[1024];
int num_candidates;
int solution_size;
int unique_values;
int min_solution_size;

void init_backtrack();
void backtrack();



#endif
