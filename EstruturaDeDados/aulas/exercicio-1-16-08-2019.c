#include <stdio.h>

void converteInteiroEmHoras(int numero);

struct horasMinutos {
  int horas;
  int minutos;
};

int main() {
  int numero;

  printf("Informe um número inteiro: \n");
  scanf("%d", &numero);

  converteInteiroEmHoras(numero);
}

void converteInteiroEmHoras(int numero) {
  struct horasMinutos conversor;

  conversor.horas = numero/60;
  conversor.minutos = (numero % 60);
  printf("%d equivale a %d horas e %d minutos \n", numero, conversor.horas, conversor.minutos);
}