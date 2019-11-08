#include <stdio.h>

int buscaBinaria(int arr[], int chave, int tam);
int main(void) {
  int arr[] = {12, 25, 33, 37, 48, 57, 86, 92, 98, 105};
  // indice do array
  int chave = 8;
  // int = 4 bytes
  int tam = sizeof(arr) / sizeof((arr)[0]);

  printf("%d",  buscaBinaria(arr, chave, tam));

  return 0;
}


int buscaBinaria(int arr[], int chave, int tam){
  int meio = (0 + tam-1) / 2;

  if(arr[chave] != arr[meio])
    if(arr[chave] < arr[meio])
      return buscaBinaria(arr, chave, tam - 1);
    else
      return buscaBinaria(arr, chave, tam + 1);
  else
    return arr[chave];

  return -1;
}
