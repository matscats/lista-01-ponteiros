#include <stdio.h>

void multiplica_matriz(int *A, int *B, int *C, int la, int ca, int cb)
{
  for (int i = 0; i < la; i++) {
    for (int j = 0; j < cb; j++) {
        *(C + (i * cb + j)) = 0;
        for (int k = 0; k < ca; k++) {
            *(C + (i * cb + j)) += *(A + (i * cb + k)) * *(B + (k * cb + j));
        }
    }
  }
}

int main(void)
{
  // Matriz teste A
  int A[2][2] = {
    {1,2},
    {3,4}
  };
  // Matriz teste B
  int B[2][2] = {
    {1,1},
    {1,1}
  };
  // Matriz Resultado
  int C[2][2];

  multiplica_matriz(&A[0][0], &B[0][0], &C[0][0], 2, 2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        printf("%d ",C[i][j]);
    }
    printf("\n");
  }
  return 0;
}