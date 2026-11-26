#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int age;
} Person;

int main(){

  Person *p = calloc(10, sizeof(Person)); 

  for(int i = 0; i < 10; i++){
    p[i].age = 1 << i;
    sprintf(p[i].name, "%d", i);
    //strcpy(p[0].name, i2s(0));
  }


  for(int i = 0; i < 10; i++){
    printf("Person name: %s; age: %i\n", p[i].name, p[i].age);
  }

  p->age = 1000; // use the -> operator instead of an array subscript
  printf("Person name: %s; age: %i\n", p->name, p->age);

  free(p);

  return 0;
}
