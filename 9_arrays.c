#include <stdio.h>

int main(){
  int nums[] = {1, 2, 3, 4};

  printf("Byte size of nums: %ld\n", sizeof(nums));

  printf("Size of nums: %ld\n", sizeof(nums) / sizeof(nums[0]));

  // can't do this with variable sizes, not even with constants
  const int rows = 2;
  const int cols = 3;
  // int matrix[rows][cols] = { {1,2,3}, {4,5,6} }; // 2 rows, 3 columns

  int matrix[2][3] = { {1,2,3}, {4,5,6} }; // 2 rows, 3 columns


  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("i = %d; j = %d, matrix[%d][%d] = %d\n", i, j, i, j, matrix[i][j]);
    }
  }

  printf("Value of 1st col of 1st row: %d\n", **matrix);
  printf("Value of 1st col of 2nd row: %d\n", *(*matrix + 3)); // deref point to 1st element of rows
                                                               // add 3 to pointer get next row, i.e. 3 characters away
                                                               // deref to get first element of 2nd row
                                                               // r1c1 r1c2 r1c3 r2c1
                                                               //   + 3 -----------^
                                                               // I'm guessing the rows are all contiguous

  for(int i = 0; i < 6; i++){
    printf("Matrix %d = %d\n", i, *(*matrix + i)); // Yup, seems to be contiguous
  }

  return 0;
}
