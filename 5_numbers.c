#include <stdio.h>

int main(){
  int a = 1;
  int b = 2;

  printf("a: %i, b: %i\n", a, b);

  b = a;

  printf("a: %i, b: %i\n", a, b);

  a = 3; // doesn't change b, b is not a pointer

  printf("a: %i, b: %i\n", a, b);

  int* aa = &a;
  int* bb = &b;

  printf("aa: %p - %i, bb: %p - %i\n", aa, *aa, bb, *bb); // pointers

  bb = aa;

  printf("aa: %p - %i, bb: %p - %i\n", aa, *aa, bb, *bb); // bb shows the existing value of a

  a = 4; // changes *aa and *bb

  printf("aa: %p - %i, bb: %p - %i\n", aa, *aa, bb, *bb); // bb shows the new value of a

  return 0;
}

// $./5_numbers 
// a: 1, b: 2
// a: 1, b: 1
// a: 3, b: 1
// aa: 0x7ffd7b3ca530 - 3, bb: 0x7ffd7b3ca534 - 1
// aa: 0x7ffd7b3ca530 - 3, bb: 0x7ffd7b3ca530 - 3
// aa: 0x7ffd7b3ca530 - 4, bb: 0x7ffd7b3ca530 - 4
