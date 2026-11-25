#include <stdio.h>

int main(){

  int i = 0, j = 1;
  char a = 'a';
  float f = 0.0123;
  double d = 0.02345;
  const int ci = 2;

  printf("Float f = %f\nDouble = %lf\nInt i = %i, j = %i\nChar a = %c, as int = %i\nconst int ci = %i\n", f, d, i, j, a, a, ci);

  return 0;
}
