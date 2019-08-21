#include <stdio.h>

void imparesOuPares(int numero);
void ordemCrescente(int *numeros);

int entrada;
int continuar = 0;
int count = 0;
int numeros[100];
int totalImpares = 0;
int totalPares = 0;
float mediaImpares = 0;
int totalImpares50 = 0;

int main() {

  while(continuar == 0) {
    printf("Informe um número: \n");
    scanf("%d", &entrada);

    if(count < 100) {
      if(entrada < 256) {
        numeros[count] = entrada;
        imparesOuPares(entrada);
      } else {
        printf("Informe um número entre 0 e 255.\n");
      }
    } else {
      printf("Número máximo de entradas atingido.\n");
    } 
    
    printf("Continuar? 0 - Sim | 2 - Não\n");
    scanf("%d", &continuar);
    count++;
  }

  printf("Total de números pares: %d \n", totalPares);
  printf("Total de números ímpares: %d \n", totalImpares);
  printf("Total de números ímpares maiores que 50: %.2f \n", (mediaImpares/totalImpares50));
  ordemCrescente(numeros);
}

void imparesOuPares(int numero){
  if(numero % 2 == 0) {
    totalPares++;
  } else {
    if(numero > 50){
      mediaImpares += numero;
      totalImpares50++;
    }
    totalImpares++;
  }
}

void ordemCrescente(int *numeros){
  int i = 0;
  int temp = 0;
  int j = 0;

  for (i = 0; i < count; i++) {
    for(j= i + 1; j < count; j++){
      if (numeros[i] > numeros[j]){
        temp=numeros[i];
        numeros[i]=numeros[j];
        numeros[j]=temp;
      }
    }
  }

  printf("Números em ordem crescente: ");
  for(i= 0; i < count; i++) {
    printf("%d ", numeros[i]); 
  }
}