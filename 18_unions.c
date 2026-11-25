#include <stdio.h>
#include <string.h>

union u {
  int i;
  char c;
  float f;
  char c2[20];
}; // nothing allocated here, this is just a kind of type

int main(){
  union u u1; // memory allocated here - 20 bytes to hold any possible field

  printf("size of union u1: %zu\n", sizeof(u1)); // z is ... I don't know, u is unsigned (conversion specifier)
  printf("size of union u1: %ld\n", sizeof(u1)); // ld is long; l is a length specifier

  u1.f = 1.123;

  printf("size of union u1: %zu\n", sizeof(u1));

  printf("value of union u1: %f\n", u1.f);

  char c[3] = {'a', 'b', 'c'};

  printf("pointer to u:  %p\n"
         "pointer to c2: %p\n"
         "pointer to i:  %p\n",
         (void *)&u1, (void *)u1.c2, (void *)&u1.i); // all at the same place

  // u1.c2 = ['a', 'b', 'c'];
  // strcpy(u1.c2, ['a', 'b', 'c']);
  // strcpy(u1.c2, {'a', 'b', 'c'});

  strcpy(u1.c2, c); // works.

  printf("value of union u1: %s\n", u1.c2);

  strcpy(u1.c2, "foo"); // also works

  printf("value of union u1: %s\n", u1.c2);
  printf("value of union u1: %c\n", u1.c);
  printf("value of union u1: %hhd\n", u1.i); // hh shrinks an int down to 1 byte

  return 0;
}
