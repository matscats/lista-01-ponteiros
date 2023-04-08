#include <stdio.h>

// Ponteiro para função pode ser util em funções callbacks

void callback(void)
{
  printf("Callback disparada\n");
}

void func(int condicao, void (*callback) (void)) 
{
  if (condicao == 1) {
    callback();
  } 
  else {
    printf("A callback falhou\n");
  }
}

int main(void)
{
  void (*ptr) (void) = &callback;
  func(1, ptr);
  func(2, ptr);
  return 0;
}
