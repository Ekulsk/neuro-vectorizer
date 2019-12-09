#include "header.h"

int   ia[1024] ALIGNED16;
int op1[64][1024];
int op2[64][1024];

__attribute__((noinline))
void example13(int op1[][1024], int op2[][1024], int *out) {
  int i,j;
  for (i = 0; i < 64; i++) {
    int sum_sub = 0;
    for (j = 0; j < 1024; j+=8) {
      sum_sub += (op1[i][j] -op2[i][j]);
    }
    out[i] = sum_sub;
  }
}
int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[1024]);
  init_memory(&op1[0][0], &op1[0][1024]);
  init_memory(&op2[0][0],&op2[0][1024]);
  BENCH("Example13",  example13(op1,op2,ia), 32768, digest_memory(&ia[0], &ia[1024]));
  return 0;
}