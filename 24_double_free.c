#include <stdio.h>
#include <stdlib.h>

int main(){

  int *j = calloc(10, sizeof(int));
  free(j);
  j = NULL; // if ptr is NULL, no operation is performed - man -s 3 free
  free(j); // I think this is fine
  printf("Survived double free.\n");
   
  int *i = calloc(10, sizeof(int));
  free(i);
  free(i); // aborted!

  return 0;
}
