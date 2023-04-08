#include <stdio.h>

int main(void) 
{
  char x1[4] = {'a', 'b', 'c', 'd'};
  int x2[4] = {1, 2, 3, 4};
  float x3[4] = {1.0, 2.0, 3.0, 4.0};
  double x4[4] = {1.0, 2.0, 3.0, 4.0};
  printf("Array de char:\n");
  for (int i = 0; i < 4; i++){
    printf("%X\n", (x1 + i));
  }
  printf("Array de int:\n");
  for (int i = 0; i < 4; i++){
    printf("%X\n", (x2 + i));
  }
  printf("Array de float:\n");
  for (int i = 0; i < 4; i++){
    printf("%X\n", (x3 + i));
  }
  printf("Array de double:\n");
  for (int i = 0; i < 4; i++){
    printf("%X\n", (x4 + i));
  }
  return 0;
}