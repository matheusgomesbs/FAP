#include <stdio.h>

void mostrarArray(int value[], int tam);

int main(void) {
  int arr[16] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
  int min, max, tmp;
  max = 16;

  printf("Dados desordenados:\n");
  mostrarArray(arr, max);

  for(int i = 0; i < max; i++) {
    min = i;

    for(int j = i + 1; j < max; j++){
      if(arr[j] > arr[min]) {
        min = j;
      }
    }

    if(min != i) {
      tmp = arr[min];
      arr[min] = arr[i];
      arr[i] = tmp;
    }
  }
  
  printf("\nDados em ordem decrescente:\n");
  mostrarArray(arr, max);
  return 0;
}

void mostrarArray(int value[], int tam) {
  for(int i = 0; i < tam; i++) {
    printf("%d ", value[i]);
  }
}
