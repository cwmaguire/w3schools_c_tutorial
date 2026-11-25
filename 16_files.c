#include <stdio.h>

int main(){
  FILE *fptr;
  fptr = fopen("15_fun_ptr.c", "r");
  char fileText[100];

  for(int i = 0; i < 5; i++){
    fgets(fileText, 100, fptr); // reads the newline
    printf("Read from 15_fun_ptr.c: %s", fileText);
  }

  fclose(fptr);

  FILE *fptr2;
  fptr2 = fopen("15_out", "w");
  fprintf(fptr2, "Foo");
  fclose(fptr2);

  FILE *fptr3;
  fptr3 = fopen("15_out", "a");
  fprintf(fptr3, " Bar");
  fclose(fptr3);

  FILE *fptr4;
  fptr4 = fopen("15_out", "r");
  char fileText2[100];
  fgets(fileText2, 100, fptr4);

  printf("Read from 15_out: %s\n", fileText2);

  fclose(fptr4);

  return 0;
}
