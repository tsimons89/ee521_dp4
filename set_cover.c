#include "set_cover.h"
#include <assert.h>

int is_valid_solution(){
  return unique_values == set.max_value;
}

void print_solution(){
  int i;
  printf("%d\n",solution_size);
  for(i = 0;i < set.num_subsets; i++){
    if(solution[i]){
      printf("(%d)",i);
      int j;
      for(j = 0;j < set.subsets[i].num_values;j++){
	printf(" %d",set.subsets[i].values[j]);
      }
      printf("\n");
    }
  }
}

int process_solution(){
  if(solution_size < min_solution_size){
    min_solution_size = solution_size;
    print_solution();  
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

void backtrack(){
  if(is_valid_solution())
    process_solution();
}
