#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// You can use -D on the compile command line to do a `#define`
// cc -Wall -Wextra -Wpedantic -DROUNDS=2 27_rand.c -o 27_rand

#ifndef ROUNDS
  #define ROUNDS 20
#endif

#define RAND (rand() - rand())

int main(){

  printf("ROUNDS = %i\n", ROUNDS); // -DROUNDS sets ROUNDS to 1

  srand(time(NULL));

  for(int i = 0; i < ROUNDS; i++){
    printf("%i\n", RAND);
  }

  //for(;;){
  //  printf("1: Happens once?\n"); // Nope!
  //}

  // for(int i = 0; i < ;){ } // error

  return 0;
}
