#include <stdio.h>

int main() {
  int arr[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
  int tam = sizeof(arr) / sizeof((arr)[0]);
 
  printf("Array original:\n");
  for (int i = 0; i < tam; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n\n");

  //Bubblesort:
  int tmp;
  for (int i = 1; i < tam; i++) {
    for (int j = 0; j < tam - 1; j++) {
      if (arr[j + 1] > arr[j]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
  
        printf("\nResultado:\n");
        for (int i = 0; i < tam; i++) {
          printf("%d\t", arr[i]);
        }
        printf("\n\n");
      }
    }
  }

  printf("\nResultado Final:\n");
  for (int i = 0; i < tam; i++) {
    printf("%d\t", arr[i]);
  }

  return 0;
}
