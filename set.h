typedef struct Subset{
  int num_values;
  int * values;
} Subset;

struct set{
  int num_subsets;
  int max_value;
  Subset * subsets;
} set;


void read_set_from_file(char * filename);
void print_set();
