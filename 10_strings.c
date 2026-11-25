#include <stdio.h>
#include <string.h>

int main(){

  char s[] = "banana";

  printf("String is %s\n", s);

  s[0] = 'B';
  printf("String is now %s\n", s);

  printf("Size of string s: %ld\n", sizeof(s)); // char is 1 byte, strings include \0 automatically
  printf("strlen(s): %ld\n", strlen(s)); // char is 1 byte, strings include \0 automatically

  char s2[] = "bana\0na";
  printf("String s2 is: %s\n", s2); // early \0 chops the string
  printf("Size of s2 is: %ld\n", sizeof(s2)); // includes both \0's
  printf("strlen() of s2 is: %ld\n", strlen(s2)); // stops at first \0

  strcat(s, s2); // overflows s because it isn't big enough, s2 is next on the stack, and it gets mangled
  printf("strcat(s, s2); s is now %s, s2 is now %s\n", s, s2);
  printf("strlen(s) = %ld\n", strlen(s));
  printf("strlen(s2) = %ld\n", strlen(s2));

  char s3[20] = "foo";
  char s4[20] = "bar";
  printf("before strcpy: s3: %s, s4: %s\n", s3, s4);
  strcpy(s4, s3);
  printf("after strcpy: s3: %s, s4: %s\n", s3, s4); // foo foo

  char s5[30] = "foo in the morning air";
  char s6[30] = "banana split";
  printf("before strncpy: s5: %s, s6: %s\n", s5, s6);
  strncpy(s6, s5, 5); // copies 5 bytes of s5 into s6
  printf("after strncpy: s5: %s, s6: %s\n", s5, s6);

  return 0;
}
