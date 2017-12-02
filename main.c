#include <assert.h>
#include "set.h"
#include "set_cover.h"
int main(int argc, char *argv[]){
  assert(argc == 2);
  read_set_from_file(argv[1]);
  backtrack();
  return 0;
}
