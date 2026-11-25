#include <stdio.h>

int main(){

  int n;

  printf("Type number: \n");

  int ret = scanf("%d", &n);  // DANGER: can overflow

  printf("Your number is %d\n", n);
  printf("Return is %d\n", ret); // EOF is -1

  printf("EOF is %d\n", EOF);

  char c;

  printf("Enter a number and a character:\n");

  ret = scanf("%d %c", &n, &c);

  printf("Your values were: %d, %c\n", n, c);
  printf("Return is %d\n", ret); // EOF is -1

  char c2;
  char s[] = "abcd";
  sscanf(s, "%c%c", &c, &c2);

  printf("First two chars of s are: %c %c\n", c, c2);

  printf("Address of c: %p\n", &c);

  // sscanf(s, "%c%c%c", &c, (*)\0, &c2); // Just goofing around trying to put the second letter in a null pointer

  return 0;
}
