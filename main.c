#include <assert.h>
#include "set.h"
int main(int argc, char *argv[]){
  assert(argc == 2);
  read_set_from_file(argv[1]);
  print_set();
  return 0;
}
