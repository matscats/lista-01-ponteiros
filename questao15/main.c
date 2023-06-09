#include <stdio.h>
#include <stdlib.h>

void meu_qsort(void *array, size_t n, size_t size, int (*compare) (const void *a, const void *b))
{
  char *ptr = (char *) array; /* Escolhi usar o char pois ele possui apenas um byte e fica mais facil
                                 de percorrer os diferentes tipos de arrays*/
  char temp[size];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if ( compare(ptr + i * size, ptr + j * size) > 0 ) {
          for (int k = 0; k < size; k++) {
              temp[k] = *(ptr + i * size + k);
              *(ptr + i * size + k) = *(ptr + j * size + k);
              *(ptr + j * size + k) = temp[k];
          }
        }
    }
  }
}

// Função que irá comprar os valores para o meu_qsort
int compare(const void *x, const void *y)
{
  return *(float *)x - *(float *)y; 
}

// Função que irá ordenar o array
void ordena_float_meu_qsort(int n)
{
  // Aloca o espaço de memória
  float *numeros_ordenados = (float *) malloc(n * sizeof(float));
  // Entrada dos números floats
  for (int i = 0; i < n; i++){
    scanf("%f", &numeros_ordenados[i]);
  }
  // Ordenação usando o meu_qsort
  meu_qsort(numeros_ordenados, n, sizeof(float), compare);
  // Printa os números ordenados
  for (int i = 0; i < n; i++){
    printf("%f ", numeros_ordenados[i]);
  }
  // Libera o espaço da memória
  free(numeros_ordenados); 
}

int main(void)
{
  ordena_float_meu_qsort(3);
  return 0;    
}