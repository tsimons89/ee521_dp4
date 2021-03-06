#include "read_file.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
FILE * file_in;
int num_values;
char line[1024];
int values[1024];
char ** temp;

void open_file(char * filename){
  file_in = fopen(filename,"r");
}
int get_num_from_next_line(){
  assert(fgets(line,sizeof(line),file_in));
  return (int)strtol(line,temp,10);
}

int * get_values_from_next_line(){
  char * tok;
  num_values = 0;
  assert(fgets(line,sizeof(line),file_in));
  tok = strtok(line," ");
  values[0] = strtol(tok,temp,10);
  while((tok = strtok(NULL," ")) && *tok != '\n'){
    num_values++;
    values[num_values] = strtol(tok,temp,10);
  }
  num_values++;
  int * return_values = malloc(sizeof(int)*num_values);
  return memcpy(return_values,values,sizeof(int)*num_values);
}

int get_num_values(){
  return num_values;
}

