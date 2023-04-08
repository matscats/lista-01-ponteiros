#include <stdio.h>
#include <stdlib.h>

void ordena_float(const int n)
{
  // Aloca o espaço de memória
  float *numeros_ordenados = (float *) malloc(n * sizeof(float));
  // Entrada dos números floats
  for (int i = 0; i < n; i++){
    scanf("%f", &numeros_ordenados[i]);
  }
  // Ordena os números
  double temp;
  for (int i = 0; i < n; i++){     
    for (int j = i + 1; j < n; j++){     
        if (numeros_ordenados[i] > numeros_ordenados[j]) {    
            temp = numeros_ordenados[i];    
            numeros_ordenados[i] = numeros_ordenados[j];    
            numeros_ordenados[j] = temp;    
        }     
    }     
  }
  // Printa os elementos ordenados
  for (int i = 0; i < n; i++){
    printf("%f\n", numeros_ordenados[i]);
  }
  // Libera o espaço de memória
  free(numeros_ordenados);
}
