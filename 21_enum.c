#include <stdio.h>

enum Level {
  LOW = 10,
  MEDIUM, // now 11
  HIGH = 20
};

typedef enum {
  BLUE = 2,
  RED,
  PURPLE = BLUE,     // works: same value, one references other, restarts count at 2
  GREEN,             // equal to RED: both default to 2 + 1
  // HIGH,           // fails: conflicts with Level.HIGH
  // YELLOW = PINK,  // fails: PINK not defined yet
  PINK = 10
} Color;

int main(){
  enum Level l = LOW;
  printf("Level is %i\n", (enum Level) HIGH);
  printf("Level is %i\n", MEDIUM);
  printf("Level is %i\n", l);

  //Color dflt;
  Color blue = BLUE;
  //printf("Color default is %i\n", dflt); // error: dflt is uninitialized
  printf("Color BLUE is %i\n", blue);
  printf("Color PURPLE is %i\n", PURPLE);
  printf("Color RED is %i\n", RED);
  printf("Color GREEN is %i\n", GREEN);
  printf("Color PINK is %i\n", PINK);
  return 0;
}
