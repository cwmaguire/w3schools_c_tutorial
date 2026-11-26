#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){

  FILE *f = fopen("foo.txt", "r");

  printf("Print error\n");
  perror("Foo");
  printf("Error: %i - %s\n", errno, strerror(errno));
  printf("Printed error\n");

  // fclose(f); // seg fault
  
  if(f != NULL){
    fclose(f);
  }

  return 0;
}
