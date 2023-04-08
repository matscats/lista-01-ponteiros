#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

// Função que irá comprar os valores para as funções
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
  printf("\n");
  // Libera o espaço da memória
  free(numeros_ordenados); 
}

void ordena_float_qsort(int n)
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
  printf("\n");
  // Libera o espaço da memória
  free(numeros_ordenados); 
}

int main(void)
{
  clock_t inicio, fim;
  double tempo;
  inicio = clock();
  ordena_float_qsort(3);
  fim = clock();
  tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  printf("Tempo de execucao utilizando o qsort original: %f segundos\n", tempo);
  inicio = clock();
  ordena_float_meu_qsort(3);
  fim = clock();
  tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
  printf("Tempo de execucao utilizando o meu qsort: %f segundos\n", tempo);
  return 0;    
}