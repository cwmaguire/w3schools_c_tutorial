#include <stdio.h>
#include <string.h>

typedef union {
  int color;
  char song[20];
} Fav;

typedef struct {
  int favType;
  char name[20];
  int age;
  Fav f;
} Person; // <- type name "Person" replaces "struct person", so "Person p" instead of "struct person p"

typedef void (*Fun)(void);
typedef int (*IntInt)(int);

int inc(int x){ return x + 1; }

int main(){

  Fun fn = (Fun)inc;
  //printf("1 + 1 = %i\n", ((int (*)(int))fn)(1));
  printf("1 + 1 = %i\n", ((IntInt)fn)(1));    // AHA! we can save a bunch of typing by assigning aliases to function signatures

  //Fav f;
  //strcpy(f.song, "Amazing Grace"); // cannot assign string to array, I think.

  Fav f = (Fav){.song = "Amazing Grace"};  // you can build this all in one go



  /* Neither work: cannot assign to expresion with array type
   * initialization is different from assignment:
   * char song[20] = "foo"; <- initialization
   *
   * char song[20];
   * song = "foo";          <-- assignment
   *
  char amazingGrace[20] = "Amazing Grace";
  f.song = &amazingGrace;
  f.song = amazingGrace;
  */

  Person p = {2, "Chris", 48, f};

  char fav[30];
  if(p.favType == 1){
    sprintf(fav, "%i", p.f.color);
  }else{
    sprintf(fav, "%s", p.f.song);
  }

  printf("%s is %i years old and they like %s\n", p.name, p.age, fav);

  return 0;
}
