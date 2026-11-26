#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// There's a bunch of complicated logic where BASH and the kernel
// put the arguments on the stack for us

#define BASE_10 10

typedef enum {
  NONE,
  INT,
  STR
} ArgType;

int main(int argc, char *argv[]){ // char *argv[] is an array of pointers to char, or a pointer to a pointer to a char
                                  // This is a bit confusing because I don't see how it was decalred
                                  // We need the count precisely because we don't see how many pointers to chars there are,
                                  // and we assume that each one is null-terminated

  printf("Debug:\n");
  for(int i = 1; i < argc; i++){
    printf("Arg %i: %s\n", i, argv[i]); // argv[i] points to a point to a null-terminated string
  }
  printf("\n");

  int arg_type = NONE;

  int i = 1;
  long long_args_index = 0;
  long long_args[argc];
  long str_args_index = 0;
  char *str_args[argc];
  char long_flag[3] = "-i";
  char str_flag[3] = "-s";

  // printf("long_flag: |%s|; str_flag |%s|\n", long_flag, str_flag);
  // printf("None: %i; INT: %i; STR: %i\n", NONE, INT, STR);

  while(i < argc){
    // printf("Arg[%i]: %s; arg type: %i\n", i, argv[i], arg_type);
    // printf("strcmp long flag: %i\n", strcmp(argv[i], long_flag));
    // printf("strcmp str flag: %i\n", strcmp(argv[i], str_flag));

    if(arg_type == NONE && strcmp(argv[i], long_flag) == 0){
      arg_type = INT;
      i++;
    }else if(arg_type == INT){
      long_args[long_args_index] = atoi(argv[i]); // strtol(argv[i], NULL, BASE_10);
      long_args_index++;
      arg_type = NONE;
      i++;
    }else if(arg_type == NONE && strcmp(argv[i], str_flag) == 0){
      arg_type = STR;
      i++;
    }else if(arg_type == STR){

      str_args[str_args_index] = malloc(strlen(argv[i]));
      if(str_args[str_args_index] == NULL){
        perror("Failed to allocate memory");
        exit(errno);
      }
      strcpy(str_args[str_args_index], argv[i]);
      str_args_index++;
      arg_type = NONE;
      i++;
    }else{
      printf("Unrecognized arg: %s\n", argv[i]);
      i++;
    }
  }

  printf("Long args: ");
  for(int i = 0; i < long_args_index; i++){
    printf("%li ", long_args[i]);
  }
  printf("\n");

  printf("String args: ");
  for(int i = 0; i < str_args_index; i++){
    printf("%s ", str_args[i]);
  }
  printf("\n");

  return 0;
}
