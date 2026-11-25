#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>
#include <stdint.h>

int main(){

  //void *p0 = malloc(SIZE_MAX);
  void *p0 = malloc(9223372036854775807);   // <- max object size
  if(p0 == NULL){
    printf("Could not allocate massive chunk of memory\n");
  }else{
    printf("Allocated massive chunk of memory!\n");
  }

  void *p1 = malloc(1);
  p1 = realloc(p1, 20);
  free(p1);

  int *i;
  int *p2 = (int *) calloc(5, sizeof(*i));
  //((int *) *p2) = 1;
  *p2 = 1;
  *(p2 + sizeof(*i)) = 2;
  p2[2] = 3;
  printf("p2[0] = %i, p2[1] = %i\n", *p2, *(p2 + sizeof(*i)));
  printf("p2[2] = %i\n", p2[2]);
  free(p2);

  /* Nope
  int p3[] = (int *) calloc(5, sizeof(*i));
  p3[0] = 10;
  free(p3);
  */

  return 0;
}
