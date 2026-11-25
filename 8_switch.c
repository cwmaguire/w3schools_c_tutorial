#include <stdio.h>

int main(){

  switch(1){
    case 1:
      printf("case 1 == 1\n");
      break;
  }

  switch('a'){ // counts as an int
    case 'a':
      printf("case a == a\n");
      break;
  }

  // invalid, not an int

  //switch("abc"){  
  //  case "abc":
  //    printf("case \"abc\" == \"abc\"\n");
  //    break;
  //}


  return 0;
}
