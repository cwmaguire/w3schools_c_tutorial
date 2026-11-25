#include <stdio.h>

// Shower though: can I figure out the type of the value in the union if
// all the types in the union have a type field first.

typedef struct {
  int type;
  int num;
} Num;

typedef struct {
  int type;
  char name[20];
} Name;

typedef union {
  Num num;
  Name name;
} NumOrName;

// Could also have a struct with a type and a union

void print(NumOrName);
void print2(NumOrName);

int main(){
  // You don't actually need the NumOrName or the Name/Num casts
  // The compiler knows from what field you're setting
  NumOrName nnNum = (NumOrName){.num =        {.type = 1, .num = 20}};
  NumOrName nnName =           {.name = (Name){.type = 2, .name = "Chris"}};

  NumOrName nnNum2 = {{1, 99}};             // num is the first union field
  NumOrName nnName2 = {.name = {2, "Foo"}}; // don't need field name because "Foo" is type char[]

  // From Grok:
  // A brace with no designator initializes the union's first member, which is
  // num, so {{2, "Foo"}} tries to store the string in num.num.

  print(nnName);
  print(nnNum);

  print(nnNum2);
  print(nnName2);

  print2(nnName);
  print2(nnNum);
}

void print(NumOrName nn){
  if( *((int *) (&nn)) == 1){
  //if( 1 == 1){
    printf("Number is %d\n", nn.num.num);
  }else{
    printf("Name is %s\n", nn.name.name);
  }
}

void print2(NumOrName nn){
  if(nn.num.type == 1){              // works whether .num or .name was stored
    printf("Number is %d\n", nn.num.num);
  }else{
    printf("Name is %s\n", nn.name.name);
  }
}
