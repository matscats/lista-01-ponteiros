#include <stdio.h>

void soma_vetor(int vec_1[], int vec_2[], int *vec_soma, int num)
{
  for (int i = 0; i < num; i++) {
    vec_soma[i] = vec_1[i] + vec_2[i];
  }
} 

int main(void) {
  int vec_1[] = {1,2,3};
  int vec_2[] = {2,3,4};
  int soma[3];
  soma_vetor(vec_1, vec_2, &soma[0], 3);
  for (int i = 0; i < 3; i++) {
    printf("%d ", soma[i]);
  }
  return 0;
}