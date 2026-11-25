#include <stdio.h>

void set_val(int* p, int val);

int main(){

  int a = 0;
  int b = 0;

  printf("a = %d, b = %d\n", a, b);

  set_val(&a, 1);
  set_val(&b, 2);

  printf("a = %d, b = %d\n", a, b);

  return 0;
}

void set_val(int* p, int val){
  printf("set_val(%p, %d), val of p is %d\n", p, val, *p);
  *p = val; // weird, you can put a value in what is pointed at by the pointer
            // *p       - get the value
            // *p = 1   - set the value
}

/*
 * Huh, pointers are really no different that variables:
 * i = 1    - you're setting the value pointed at by int i
 * i        - you're getting the value poitned at by int i
 * *p = 1   - you're setting the value pointed at by pointer p
 * *p       - you're getting the value pointed at by pointer p
 *
 * The only difference is that if I pass a, I'm passing the value; if I want to pass the memory address, I have to pass p
 *
 * I think this is the same as Java/C# where if I pass an *object*, I'm passing a pointer; whereas if I pass a primitive, I'm passing a value.
 */
