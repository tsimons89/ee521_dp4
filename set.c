#include "set.h"
#include "read_file.h"
#include <stdlib.h>
#include <stdio.h>

void read_header(){
  set.max_value = get_num_from_next_line();
  set.num_subsets = get_num_from_next_line();
  set.subsets = (Subset*)malloc(sizeof(Subset)*set.num_subsets);
}

void set_next_subset(int subset_index){
  set.subsets[subset_index].values = get_values_from_next_line();
  set.subsets[subset_index].num_values = get_num_values();
}

void read_subsets(){
  int i;
  for(i = 0; i < set.num_subsets; i++)
    set_next_subset(i);
}

void read_set_from_file(char * filename){
  open_file(filename);
  read_header();
  read_subsets();
}

Subset * create_subset(int num_values, int * values){
  Subset * new_subset_ptr = (Subset*)malloc(sizeof(Subset));
  new_subset_ptr->num_values = num_values;
  new_subset_ptr->values = values;
  return new_subset_ptr;
}

void print_subset(Subset subset){
  int i = 0;
  printf("Size: %d Values: ",subset.num_values);
  for(i = 0; i < subset.num_values;i++)
    printf("%d ",subset.values[i]);
  printf("\n");
}

void print_set(){
  int i = 0;
  for(i = 0;i < set.num_subsets; i++)
    print_subset(set.subsets[i]);
}

