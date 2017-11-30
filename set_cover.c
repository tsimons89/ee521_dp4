#include "set_cover.h"
#include <assert.h>

int is_valid_solution(){
  if(unique_values = set.max_value)
    return 1;
  return 0;
}
void print_solution(){
  int i;
  for(i = 0;i < set.num_subsets; i++){
    
  }
  
}
int process_solution(){
  if(solution_size < min_solution_size){
    min_solution_size = solution_size;
    print_solution;  
  }
}

void add_value(int value){
  if(values_hist[value] == 0)
    unique_values++;
  values_hist[value]++;
    
}
int add_subset(int index){
  int i;
  assert(solution[index] == 0);
  solution_size ++;
  int * values = set.subsets[index].values;
  for(i = 0; i < set.subsets[index].num_values; i++)
    add_value(values[i]);
    
}

void remove_value(int value){
  assert(values_hist[value] > 0);
  if(values_hist[value] == 1)
    unique_values--;
  values_hist[value]--;
    
}
int remove_subset(int index){
  int i;
  assert(solution[index] == 1);
  solution_size --;
  int * values = set.subsets[index].values;
  for(i = 0; i < set.subsets[index].num_values; i++)
    remove_value(values[i]);
    
}
