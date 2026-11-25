#include <stdio.h>
#include <ctype.h>

void char_is(char); // have to declare before use

int main(){
  char c = 'a';
  char s = ' ';
  char i = '1';
  char C = 'A';

  char_is(c);
  char_is(C);
  char_is(s);
  char_is(i);

  return 0;
}

void char_is(char c){
  printf("'%c' is%s a digit\n", c, isdigit(c) ? "" : " not");
  printf("'%c' is%s a alpha\n", c, isalpha(c) ? "" : " not");
  printf("'%c' is%s a alnum\n", c, isalnum(c) ? "" : " not");
  printf("'%c' is%s a upper\n", c, isupper(c) ? "" : " not");
  printf("'%c' is%s a lower\n", c, islower(c) ? "" : " not");
  printf("'%c' is%s a space\n", c, isspace(c) ? "" : " not");
  return;
}
