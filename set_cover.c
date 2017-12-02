#include "set_cover.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int solution[1024];
int values_hist[1024];
int subset_scores[1024];
int solution_size = 0;
int unique_values;
int min_solution_size = 1025;
int disable_output = 0;

int is_solution_valid(){
  return unique_values == set.max_value;
}

void print_solution(){
  int i;
  if(disable_output)
    return;
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
  solution[index] = 1;
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
  solution[index] = 0;
  solution_size --;
  int * values = set.subsets[index].values;
  for(i = 0; i < set.subsets[index].num_values; i++)
    remove_value(values[i]);
    
}

int calc_subset_score(int idx){
  Subset subset = set.subsets[idx];
  int i,score = 0;
  if(solution[idx])
    return 0;
  for(i = 0; i < subset.num_values; i++){
    if(values_hist[subset.values[i]] == 0)
      score++;
  }
  return score;
}

int set_subset_scores(){
  int i;
  int num_candidates = 0;
  for(i = 0; i < set.num_subsets; i++){
    subset_scores[i] = calc_subset_score(i);
    if(subset_scores[i] > 0)
      num_candidates++;
  }
  return num_candidates;
}

int cmp_subsets(const void * idx_a, const void * idx_b){
  int score_a = subset_scores[*(int *)idx_a];
  int score_b = subset_scores[*(int *)idx_b];
  return score_b - score_a;
  
}

int * init_candidates(){
  int i;
  int * candidates = (int *) malloc(set.num_subsets * sizeof(int));
  for(i = 0; i < set.num_subsets; i++)
    candidates[i] = i;
  return candidates;
}

int * construct_candidates(int * num_candidates){
  int * candidates = init_candidates();
  *num_candidates = set_subset_scores();
  qsort(candidates,set.num_subsets,sizeof(int),cmp_subsets);
  return candidates;
}

void backtrack(){
  if(is_solution_valid())
    process_solution();
  else{
    int num_candidates,i;
    int * candidates = construct_candidates(&num_candidates);
    for(i = 0; i < num_candidates; i++){
      if(subset_scores[candidates[i]] > 0){
	add_subset(candidates[i]);
	backtrack();
	remove_subset(candidates[i]);
      }
    }
    free(candidates);
  }
    
}
