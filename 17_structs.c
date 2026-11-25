#include <stdio.h>
#include <string.h>

struct s{
  int i;
  char c;
  char s[30];
};

struct inner{
  int i;
};

struct outer{
  struct inner in;
};

int main(){

  struct s s1;

  printf("s1.i: %d; s1.c: %c\n", s1.i, s1.c); // random garbage

  s1.i = 1;
  s1.c = 'a';
  strcpy(s1.s, "some text"); // can't directly assign to array with string

  printf("s1.i: %d; s1.c: %c; s1.s: %s\n", s1.i, s1.c, s1.s);

  struct s s2 = {2, 'b', "more text"};

  printf("s2.i: %d; s2.c: %c; s2.s: %s\n", s2.i, s2.c, s2.s);

  struct outer o = {{1}}; // create struct in struct with struct literals
  struct outer *po = &o;

  printf("outer o.in.i: %d; outer po.in.i: %d\n", o.in.i, po->in.i); // access struct pointer field with ->

  struct outer os[3] = {{{1}}, {{2}}, {{3}}};

  for(int i = 0; i < 3; i++){
    printf("os o.in: %d\n", os[i].in.i);
  }

  return 0;
}
