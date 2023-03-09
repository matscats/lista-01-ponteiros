#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

// Função que irá comprar os valores para o qsort
int compare(const void *x, const void *y)
{
  return *(int *)x - *(int *)y; 
}

// Função que irá ordenar o array
void ordena_float(int n)
{
  // Aloca o espaço de memória
  float *numeros_ordenados = (float *) malloc(n * sizeof(float));
  // Entrada dos números floats
  for (int i = 0; i < n; i++){
    scanf("%f", &numeros_ordenados[i]);
  }
  // Ordenação usando o qsort
  qsort(numeros_ordenados, n, sizeof(float), compare);
  // Printa os números ordenados
  for (int i = 0; i < n; i++){
    printf("%f ", numeros_ordenados[i]);
  }
  // Libera o espaço da memória
  free(numeros_ordenados); 
}

int main(void)
{
  ordena_float(3);
  return 0;    
}