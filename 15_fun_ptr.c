#include <stdio.h>

int add(int, int);
void doGreetings();
void doFunArray();
void callTotallyVoidFun(void (*)(void));
int plus(int x, int y){ return x + y; }

int main(){
  int (*ptr)(int, int) = add;
  int result = ptr(5,3);
  printf("result: %d\n", result);

  doGreetings();
  doFunArray();
  void (*f)(void) = (void (*)(void))plus;
  callTotallyVoidFun(f);

  return 0;
}

int add(int i, int j){
  return i + j;
}

void greetMorning();
void greetEvening();
void greet(void (*)());

void doGreetings(){
  greet(greetMorning);
  greet(greetEvening);
}

void greet(void (*func)()){
  func();
}

void greetMorning(){
  printf("Good morning!\n");
}

void greetEvening(){
  printf("Good evening!\n");
}

void one(){ printf("one\n"); }
void two(){ printf("two\n"); }
void three(){ printf("three\n"); }

void doFunArray(){
  void (*ops[3])() = {one, two, three};
  for (int i = 0; i < 3; i++){
    ops[i]();
  }

}

void callTotallyVoidFun(void (*x)(void)){
  int (*add)(int, int) = (int (*)(int, int))x;
  printf("add: %d\n", add(1, 2));
}
