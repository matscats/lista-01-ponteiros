#include <stdio.h>

int main(void) 
{
  int x[4] = {1, 2, 3, 4};
  int *ptr = &x; 
  for (int i = 0; i < 4; i++){
    printf("%X\n", (ptr + i));
  }
  return 0;
}